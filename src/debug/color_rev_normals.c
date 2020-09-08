/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rev_normals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 01:01:23 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/09 00:00:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vcolor		color_rev_normals(t_ray *ray)
{
	t_vcolor	color;

	color = create_vec3(
		floor(fmax(DEFAULT_VALUE, -ray->normal.x) * MAX_RGB),
		floor(fmax(DEFAULT_VALUE, -ray->normal.y) * MAX_RGB),
		floor(fmax(DEFAULT_VALUE, -ray->normal.z) * MAX_RGB));
	return (color);
}
