/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/12 18:42:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function converts pixel to World coordinates
*/

t_vec3		get_pixel_coord(t_scene *scene, int x, int y)
{
	t_vec3	result;
	double	scale;
	double	pixel_x;
	double	pixel_y;

	scale = tan(degrees_to_radians(scene->main_cam->fov * 0.5));
	pixel_x = (2 * (x + 0.5) / g_app->win_x - 1) * scene->aspect_ratio * scale;
	pixel_y = (1 - 2 * (y + 0.5) / g_app->win_y) * scale;
	result = create_vec3(pixel_x, pixel_y, 1);
	return (result);
}

/*
** This function sets the ray direction
*/

void		set_ray_dir(t_ray *ray, t_scene *scene, int x, int y)
{
	t_vec3	pixel_coord;

	pixel_coord = get_pixel_coord(scene, x, y);
	ray->dir = mult_mat3x3_vec3(scene->main_cam->cam_to_world3, pixel_coord);
	ray->dir = normalize_vec3(ray->dir);
	ray->t_nearest = __DBL_MAX__;
}

/*
** This function initializes the ray origin
*/

void		set_ray_origin(t_ray *ray, t_vec3 cam_pos)
{
	ray->origin = cam_pos;
}
