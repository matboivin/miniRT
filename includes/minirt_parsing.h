/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:00:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/08/26 22:50:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

typedef	void	(*t_pars_func)(t_minirt *env, char **input);

typedef struct	s_pars_arr
{
	char		*u_id;
	t_pars_func	func;
}				t_pars_arr;

extern struct s_pars_arr	g_pars_elem[];

void			parse_scene(t_minirt *env, const char *filepath);

/*
** Global render settings
*/

void			get_resolution(t_minirt *env, char **input);
void			get_ambient(t_minirt *env, char **input);

/*
** Camera and light
*/

void			get_camera(t_minirt *env, char **input);
void			get_light(t_minirt *env, char **input);

/*
** Objects
*/

void			add_obj_to_scene(t_minirt *env, void *obj, t_objid type);
void			get_sphere(t_minirt *env, char **input);
void			get_plane(t_minirt *env, char **input);
void			get_square(t_minirt *env, char **input);
void			get_cylinder(t_minirt *env, char **input);
void			get_triangle(t_minirt *env, char **input);

/*
** Parsing utils
*/

int				get_integer(t_minirt *env, char **input);
double			get_double(t_minirt *env, char **input);
t_vcolor		get_color(t_minirt *env, char **input);
t_vec3			get_vec3(t_minirt *env, char **input);
bool			ft_vec3_range(t_vec3 vec, double start, double end);
void			skip_blank(char **s);
int				skip_separator(char **s, int sep);
void			skip_digits(char **s);
void			skip_double(t_minirt *env, char **s);
void			check_max_display(t_minirt *env);
void			check_null_vector(t_vec3 *to_check, t_vec3 default_vec);

#endif
