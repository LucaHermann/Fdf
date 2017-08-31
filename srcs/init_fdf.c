/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 06:15:30 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/10 07:08:44 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_map(t_coef *s, int x, int y)
{
	int	i;

	i = 0;
	s->map = malloc(sizeof(double*) * y);
	while (i < y)
		s->map[i++] = malloc(sizeof(double) * x);
}

void	reset_value(int *i, int *j, int *k, char **line)
{
	*j += 1;
	*k = 0;
	*i = 0;
	*line = NULL;
	free(*line);
}

void	init_struct(t_coef *scoef)
{
	scoef->coef = 2;
	scoef->xi = 40;
	scoef->yi = 600;
	scoef->cz = 1;
	scoef->mlx = mlx_init();
	scoef->win = mlx_new_window(scoef->mlx, 2600, 1390, "FDF 42");
}

void	init_image(t_coef *scoef)
{
	int bpp;
	int endian;

	scoef->img = mlx_new_image(scoef->mlx, 2600, 1390);
	scoef->data = mlx_get_data_addr(scoef->img, &bpp, &scoef->sl, &endian);
}

void	put_pixel(t_coef *scoef, int x, int y, int color)
{
	int i;

	if (x >= 2600 || x < 0 || y >= 1390 || y < 0)
		return ;
	i = x * 4 + y * scoef->sl;
	scoef->data[i] = color & 0xff;
	scoef->data[i++] = (color >> 18) & 0xff;
	scoef->data[i++] = (color >> 16);
}
