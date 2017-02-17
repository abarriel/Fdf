/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:45:15 by abarriel          #+#    #+#             */
/*   Updated: 2017/02/17 10:21:40 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_img(t_env *e)
{
	int bpp;
	int end;

	end = 0;
	bpp = 0;
	e->slen = 0;
	e->img = mlx_new_image(e->mlx, e->win_longu, e->win_large);
	e->data = (int *)mlx_get_data_addr(e->img, &bpp, &e->slen, &end);
	create_tab(e);
	send_trace(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	qds(e);
}

void	get_map(t_env *e)
{
	if (!(e->map = (int **)malloc(sizeof(int *) * e->nbline)))
		ft_exit("Failed to Malloc");
	while (++e->i < e->nbline)
		e->map[e->i] = (int *)malloc(sizeof(int) * e->nbcolon);
	while (++e->y < e->nbline)
	{
		while (++e->x < e->nbcolon)
			e->map[e->y][e->x] = ft_atoi_p(&e->smap[e->y]);
		e->x = -1;
	}
}

void	recup_map(int fd, t_env *e)
{
	char	*line;
	char	*tmp;

	if (!(e->smap = (char **)malloc(sizeof(char*) * 500)))
		ft_exit("Failed to Malloc");
	while (get_next_line(fd, &line) > 0)
	{
		e->smap[e->nbline++] = ft_strdup(line);
		free(line);
	}
	if (get_next_line(fd, &line) == -1)
		ft_exit("Try to open a folders");
	tmp = e->smap[0];
	while (*tmp != '\0' && ++e->nbcolon)
	{
		ft_atoi_p(&tmp);
		if (*tmp != '\0')
			if (*tmp != 32 && *tmp != 45 && (*tmp < 48 || *tmp > 57))
				ft_exit("Wrong Files");
	}
	close(fd);
	while ((e->e * e->nbline) < (e->win_longu / 6))
		e->e += 2;
	get_map(e);
}

int		get(t_env *e, int av, char **ac)
{
	int	fd;

	if ((fd = open(ac[1], O_RDONLY)) == -1)
		ft_exit("Unable to open the file");
	recup_map(fd, e);
	e->win = mlx_new_window(e->mlx, e->win_longu, e->win_large, "FDF");
	create_img(e);
	return (1);
}
