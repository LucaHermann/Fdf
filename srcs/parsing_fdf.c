/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhermann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:52:49 by lhermann          #+#    #+#             */
/*   Updated: 2017/07/10 08:07:03 by lhermann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_countwords(char const *s)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else
		{
			words++;
			while (s[i] != ' ' && s[i])
				i++;
		}
	}
	return (words);
}

int		ft_open(char *str)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putendl("Error, fdf will close immediatly");
		exit(-1);
	}
	return (fd);
}

int		*ft_reader(char **av)
{
	int		fd;
	int		*tab;
	char	*line;

	tab = malloc(sizeof(int) * 2);
	tab[0] = 0;
	tab[1] = 0;
	fd = ft_open(av[1]);
	while (get_next_line(fd, &line))
	{
		if (tab[0] == 0)
			tab[0] = ft_countwords(line);
		if (ft_countwords(line) < tab[0])
		{
			ft_putendl("Wrong line length, fdf will close immediatly");
			tab[0] = -1;
			return (tab);
		}
		tab[1]++;
		line = NULL;
		free(line);
	}
	close(fd);
	return (tab);
}

int		**ft_map(t_coef *param, int x, int y, char **av)
{
	int		tab[4];
	char	*line;

	tab[1] = 0;
	tab[2] = 0;
	init_map(param, x, y);
	tab[3] = ft_open(av[1]);
	tab[0] = 0;
	while (get_next_line(tab[3], &line))
	{
		while (line[tab[0]] != '\0')
			if (line[tab[0]] == ' ')
				tab[0]++;
			else
			{
				param->map[tab[1]][tab[2]] = ft_atoi(&line[tab[0]]);
				tab[2]++;
				while (line[tab[0]] != ' ' && line[tab[0]])
					tab[0]++;
			}
		reset_value(&tab[0], &tab[1], &tab[2], &line);
	}
	param->map[tab[1]] = NULL;
	close(tab[3]);
	return (0);
}

int		ft_keyhock(int key, t_coef *param)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 69)
		param->coef *= 1.05f;
	else if (key == 78)
		param->coef *= 0.95f;
	else if (key == 123)
		param->xi -= 10;
	else if (key == 124)
		param->xi += 10;
	else if (key == 125)
		param->yi += 10;
	else if (key == 126)
		param->yi -= 10;
	else if (key == 75)
		param->cz -= 0.2;
	else if (key == 67)
		param->cz += 0.2;
	else
		return (0);
	mlx_destroy_image(param->mlx, param->img);
	init_image(param);
	ft_window(param, param->map, param->coef);
	return (0);
}
