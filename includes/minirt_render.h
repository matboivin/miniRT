/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/02 00:24:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

t_color		get_obj_color(t_lstobj *hit_obj);
t_color		shading(t_scene *scene, t_ray *ray, t_lstobj *hit_obj);

void		set_viewdist(t_cam *cam);
void		reset_ray_nearest(t_ray *ray);
void		set_camera_ray(t_ray *ray, int x, int y);
void		create_camera_ray(t_scene *scene, t_ray *ray);

bool		intersect(void *obj, t_ray *ray, double *t);
t_lstobj	*trace(t_scene *scene, t_ray *ray);
t_color		cast_ray(t_scene *scene, t_ray *ray);

void		render(t_scene *scene);
void		generate_image(t_scene *scene);

#endif
