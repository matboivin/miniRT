/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_save.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 13:47:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/09/08 23:52:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_SAVE_H
# define MINIRT_SAVE_H

# define BMP_FILENAME "minirt.bmp"
# define RGB_LEN 3
# define TRUE_COLOR 24
# define DEFAULT_DPI 96
# define PPM_CONV_FACTOR 39.375
# define HEADER_BYTES 54
# define DEFAULT_BIPLANES 1
# define UNUSED 0
# define FILE_PERMISSIONS 0644

/*
** Struct: Bitmap file header
**
** bmp_type: The characters 'BM' (2 bytes)
** file_size: The size of the file in bytes (4 bytes)
** reserved1: Unused - must be 0 (2 bytes)
** reserved2: Unused - must be 0 (2 bytes)
** offset: Offset to start of pixel data (4 bytes)
*/

typedef struct	s_bmp_h
{
	t_uchar		bmp_type[2];
	int			file_size;
	short		reserved1;
	short		reserved2;
	t_uint		offset;
}				t_bmp_h;

/*
** Struct: Bitmap information header
**
** size_header: Header Size - Must be at least 40 (4 bytes)
** width: Image width in pixels (4 bytes)
** height: Image height in pixels (4 bytes)
** planes: Must be 1 (2 bytes)
** bit_count: Bits per pixel - 1, 4, 8, 16, 24, or 32 (2 bytes)
** compr: Compression type
**   0=RGB(No Compression), 1=RLE8, 2=RLE4, 3=BITFIELDS (4 bytes)
** img_size: Image size (4 bytes)
** ppm_x: Preferred resolution in pixels per meter (4 bytes)
** ppm_y: Preferred resolution in pixels per meter (4 bytes)
** clr_used: Number Color Map entries that are actually used (4 bytes)
** clr_important: Number of significant colors (4 bytes)
*/

typedef struct	s_dib_h
{
	t_uint		size_header;
	t_uint		width;
	t_uint		height;
	short int	planes;
	short int	bit_count;
	t_uint		compr;
	t_uint		img_size;
	t_uint		ppm_x;
	t_uint		ppm_y;
	t_uint		clr_used;
	t_uint		clr_important;
}				t_dib_h;

void			save_bmp(t_minirt *env, const char *filename);

#endif
