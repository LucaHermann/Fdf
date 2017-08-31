/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:40:56 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/10 07:54:09 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_mycoef
{
	double		coef;
	double		**map;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			sl;
	int			xi;
	int			yi;
	int			cntwrd;
	double		cz;
}					t_coef;

int					ft_countwords(char const *s);
int					ft_open(char *s);
int					*ft_reader(char **av);
int					**ft_map(t_coef *param, int x, int y, char **av);
void				init_map(t_coef *s, int x, int y);
void				reset_value(int *i, int *j, int *k, char **line);
int					ft_keyhock(int key, t_coef *param);
void				init_struct(t_coef *scoef);
void				init_image(t_coef *scoef);
void				put_pixel(t_coef *scoef, int x, int y, int color);
void				ft_line(t_coef *s, int a[2], int x_b, int y_b);
void				ft_xa(t_coef *s, int tab[2], double coef, double **map);
void				ft_ya(t_coef *s, int tab[4], double coef, double **map);
int					ft_window(t_coef *s, double **map, double coef);

#endif
