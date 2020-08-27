/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/27 22:19:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			add_light_color(t_ray *ray, t_vcolor light_color, double angle)
{
	t_vcolor	diffuse_color;

	diffuse_color = mult_vec3(ray->obj_color, light_color);
	diffuse_color = scale_vec3(fabs(angle), diffuse_color);
	ray->vcolor = add_vec3(ray->vcolor, diffuse_color);
}

bool			is_in_shadow(t_lstobj *objs, t_ray *ray, t_vec3 light_dir)
{
	t_ray		shadow_ray;
	t_lstobj	*hit_obj;
	double		t;

	t = norm_vec3(light_dir);
	shadow_ray = create_ray(ray->hit_p, normalize_vec3(light_dir), t);
	hit_obj = trace_ray_to_objs(objs, &shadow_ray);
	if (hit_obj)
		return (true);
	return (false);
}
