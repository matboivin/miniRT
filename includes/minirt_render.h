/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/01 18:06:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

void	*intersect(t_scene *scene, t_ray ray);
t_color	shading(t_scene *scene, void *obj);
void	set_camera_ray(t_scene *scene, t_ray *ray);
t_color	trace_ray(t_scene *scene, t_ray ray);
void	render(t_scene *scene);
void	generate_image(t_scene *scene);

#endif
