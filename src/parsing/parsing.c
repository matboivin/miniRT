/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/14 23:55:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Struct: Element identifiers associated to parsing functions
*/

static t_parsers	g_parsers[] =
{
	{ "sp", 2, &get_sphere },
	{ "pl", 2, &get_plane },
	{ "sq", 2, &get_square },
	{ "cy", 2, &get_cylinder },
	{ "tr", 2, &get_triangle },
	{ "R", 1, &get_resolution },
	{ "A", 1, &get_ambient },
	{ "c", 1, &get_camera },
	{ "l", 1, &get_light }
};

/*
** This function calls the appropriate function to parse a line
*/

static void		handle_scene_elem(t_minirt *env, char **input)
{
	int			i;

	i = 0;
	while (i < MAX_PARS_FUNC)
	{
		if (!ft_strncmp(g_parsers[i].u_id, *input, g_parsers[i].size))
		{
			(*g_parsers[i].func)(env, input);
			return ;
		}
		i++;
	}
	exit_error(env, ID_ERR);
}

/*
** This function gets the entire scene description
*/

static char		*read_scene_file(t_minirt *env, const char *filepath)
{
	char		*result;
	char		buffer[BUFFER_SIZE + 1];
	int			fd;
	int			bytes_read;

	result = NULL;
	fd = open(filepath, O_RDONLY | O_NOFOLLOW);
	if (!fd)
		exit_error(env, DEFAULT_ERR);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		result = ft_strjoindelone(result, buffer);
		if (!result)
			exit_error(env, DEFAULT_ERR);
	}
	close(fd);
	return (result);
}

/*
** This function checks whether the scene description is valid
*/

static void		check_scene(t_minirt *env)
{
	if (!env->res.is_declared)
		exit_error(env, NO_RES);
	if (!env->ambient.is_declared)
		exit_error(env, NO_AMB);
	if (!env->cams)
		exit_error(env, NO_CAM);
	if (!env->lights)
		exit_error(env, NO_LIGHT);
	if (!env->objs)
		exit_error(env, NO_OBJ);
}

/*
** This function iterates over the input to call functions
*/

void			parse_scene(t_minirt *env, const char *filepath)
{
	const char	*ids = "RAclspt";
	char		*input;
	char		*head;

	input = read_scene_file(env, filepath);
	if (!input)
		exit_error(env, DEFAULT_ERR);
	head = input;
	while (*input)
	{
		if (*input == '\n')
			input++;
		else if (ft_ischarset(*input, ids))
			handle_scene_elem(env, &input);
		else
			exit_error(env, SCENE_FMT);
	}
	ft_strdel(&head);
	check_scene(env);
	check_max_display(env);
}
