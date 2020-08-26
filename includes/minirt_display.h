/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_display.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:25 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 22:41:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DISPLAY_H
# define MINIRT_DISPLAY_H

void	switch_camera(t_minirt *env);
void	open_window(t_minirt *env);
void	put_image_to_window(t_minirt *env);
int		reload_image(t_minirt *env);
void	display_render(t_minirt *env);

#endif
