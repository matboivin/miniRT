/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/11 18:08:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function resets t_nearest to max double value
*/

void		reset_ray_nearest(t_ray *ray)
{
	ray->t_nearest = __DBL_MAX__;
}

/*
** This function sets the ray direction
*/

void		set_ray_dir(t_ray *ray, t_mat4x4 mat, t_vec4 pixel_coord)
{
	ray->dir = mult_mat4x4_vec4(mat, pixel_coord);
	ray->dir = normalize_vec4(ray->dir);
}

/*
** This function initializes the ray origin
*/

void		set_ray_origin(t_ray *ray, t_mat4x4 mat)
{
	t_vec4	vec;

	vec = create_vec4(0.0, 0.0, 0.0, 1.0);
	ray->origin = mult_mat4x4_vec4(mat, vec);
	ray->t_nearest = __DBL_MAX__;
}
