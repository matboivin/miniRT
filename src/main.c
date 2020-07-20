/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:16:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/20 23:11:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_app		*g_app;

static void	check_filename(const char *filepath)
{
	int		len;

	len = ft_strlen(filepath);
	if (len < 4)
		put_error(FILENAME);
	filepath += len - 3;
	if (!ft_strnequ(filepath, ".rt", 3))
		put_error(FILENAME);
}

int			main(int argc, char **argv)
{
	t_scene	scene;

	if (argc < 2 || argc > 3)
		put_usage();
	check_filename(argv[1]);
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		put_error(SAVE_OPTION);
	start_application(RENDER_X, RENDER_Y, WIN_TITLE);
	create_scene(&scene);
	if (argc == 3)
		save_bmp(&scene, BMP_FILE);
	register_events(&scene);
	return (run_app());
}
