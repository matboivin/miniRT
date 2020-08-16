/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/16 18:04:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function frees scene and application
*/

static void	free_all(t_scene *scene)
{
	destroy_scene(scene);
	quit_app();
}

/*
** This function frees allocated memory and exits
*/

int			exit_success(t_scene *scene)
{
	free_all(scene);
	ft_printf("EXIT\n");
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** This function frees allocated memory, prints an error message and exits
*/

void		exit_error(t_scene *scene, t_errid raised)
{
	free_all(scene);
	put_error(raised);
}
