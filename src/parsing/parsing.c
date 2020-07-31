/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:01:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/31 18:24:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Parse the scene description to fill the scene struct
**
** g_pars_elem struct  :  Element ids associated to parsing functions
** call_parsing_func() :  Gets the function matching identifier
** read_scene_file()   :  Gets the entire scene description
** check_scene()       :  Checks the scene data is valid
** parse_scene()       :  Iterates over the input to call functions
*/

struct s_pars_elem	g_pars_elem[] =
{
	{ "R ", &get_resolution },
	{ "A ", &get_ambient },
	{ "c ", &get_cam },
	{ "l ", &get_light },
	{ "sp", &get_sphere },
	{ "pl", &get_plane },
	{ "sq", &get_square },
	{ "cy", &get_cylinder },
	{ "tr", &get_triangle }
};

static void		handle_scene_elem(t_scene *scene, char **input)
{
	int			i;

	i = 0;
	while (i < 9)
	{
		if (ft_strnequ(g_pars_elem[i].u_id, *input, 2))
		{
			(*g_pars_elem[i].func)(scene, input);
			return ;
		}
		i++;
	}
	exit_error(scene, ID_ERR);
}

char			*read_scene_file(t_scene *scene, const char *filepath)
{
	int			fd;
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	char		*result;

	result = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		exit_error(scene, DEFAULT_ERR);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		result = ft_strjoindelone(result, buffer);
		if (result == NULL)
			exit_error(scene, DEFAULT_ERR);
	}
	close(fd);
	return (result);
}

static void		check_scene(t_scene *scene)
{
	if ((scene->res.is_declared == false) || (scene->amb.is_declared == false))
		exit_error(scene, MISS_RA);
	if (scene->main_cam == NULL)
		exit_error(scene, MISS_CAM);
	if (scene->lights == NULL)
		exit_error(scene, MISS_LIGHT);
	return ;
}

void			parse_scene(t_scene *scene, const char *filepath)
{
	char		*input;
	char		*head;
	const char	*ids = "RAclspt";

	input = read_scene_file(scene, filepath);
	if (input == NULL)
		exit_error(scene, DEFAULT_ERR);
	head = input;
	while (*input)
	{
		if (*input == '\n')
			input++;
		else if (ft_ischarset(*input, ids) == true)
			handle_scene_elem(scene, &input);
		else
			exit_error(scene, SCENE_FMT);
	}
	ft_strdel(&head);
	check_scene(scene);
	resize_window(scene);
}
