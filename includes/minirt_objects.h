/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_objects.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 00:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/07/31 17:08:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJECTS_H
# define MINIRT_OBJECTS_H

typedef struct		s_sphere
{
	t_vec3			pos;
	double			diameter;
	t_color			color;
}					t_sphere;

typedef struct		s_plane
{
	t_vec3			pos;
	t_vec3			rot;
	t_color			color;
}					t_plane;

typedef struct		s_square
{
	t_vec3			pos;
	t_vec3			rot;
	double			side;
	t_color			color;
}					t_square;

typedef struct		s_cyl
{
	t_vec3			pos;
	t_vec3			rot;
	double			diameter;
	double			side;
	t_color			color;
}					t_cyl;

typedef struct		s_tri
{
	t_vec3			point1;
	t_vec3			point2;
	t_vec3			vec3;
	t_color			color;
}					t_tri;

typedef struct		s_lstobj
{
	char			*type;
	void			*obj;
	struct s_lstobj	*next;
}					t_lstobj;

t_lstobj			*new_lstobj(void *obj, char *type);
void				lstobj_add_back(t_lstobj **lst, t_lstobj *new);
void				lstobj_clear(t_lstobj **lst);

#endif
