/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:32:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/07 20:40:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function displays image in window
*/

void	put_image_to_window(t_minirt *env)
{
	mlx_put_image_to_window(
		env->mlx_ptr,
		env->win_ptr,
		env->imgs->img_ptr,
		UPPER_LEFT_CORNER,
		UPPER_LEFT_CORNER);
}
