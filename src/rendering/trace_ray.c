/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/24 01:07:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function traces rays from the hit object to light spots to retrieve the
** final color.
*/

static t_color	trace_secondary_ray(t_scene *scene, t_ray *ray, t_lstobj *hit_obj)
{
	t_color		color;
	t_vec3		hit_p;
	t_vec3		normal;

	hit_p = get_hit_point(ray->origin, ray->t_nearest, ray->dir);
	normal = get_obj_normal(hit_p, hit_obj);
	color = handle_light_point(scene, ray, hit_obj, hit_p, normal);
	return (color);
}

/*
** This function traces a ray from the camera and checks whether this ray
** intersects any object in the scene.
** It iterates over all the objects and returns a pointer to the nearest
** intersected object. Otherwise, a null pointer is returned.
*/

static t_lstobj	*trace_primary_ray(t_scene *scene, t_ray *ray)
{
	t_lstobj	*nearest_obj;
	t_lstobj	*head;

	nearest_obj = NULL;
	head = scene->objs;
	while (scene->objs)
	{
		if (intersect(scene->objs, ray) == true)
			nearest_obj = scene->objs;
		scene->objs = scene->objs->next;
	}
	scene->objs = head;
	return (nearest_obj);
}

/*
** This function casts a ray. If the primary ray intersects an object, a
** secondary ray is traced to process shading and retrieve final color.
** Else, default color is returned.
*/

t_color			trace_ray(t_scene *scene, t_ray *ray)
{
	t_color		default_color;
	t_color		hit_color;
	t_lstobj	*hit_obj;

	default_color = create_color(0, 0, 0);
	hit_obj = trace_primary_ray(scene, ray);
	if (hit_obj)
	{
		hit_color = trace_secondary_ray(scene, ray, hit_obj);
		return (hit_color);
	}
	return (default_color);
}
