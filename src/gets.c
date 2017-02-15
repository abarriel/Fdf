/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:45:15 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/27 23:45:17 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void print_map(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while(e->x < e->x_max)
	{
		while(e->y < e->m[e->x])
		{
			ft_printf("%d ",e->map[e->x][e->y]);
			e->y++;
		}
		ft_printf("\n");
		e->y = 0;
		e->x++;
	}
}

void get_map_(t_env *e, int av, char **ac)
{
	int	 fd;
	char *line;

	fd = open(ac[1], O_RDONLY);
	e->tmp = (char **)malloc(sizeof(char*));
	e->m = (int *)malloc(sizeof(int));
	while (get_next_line(fd, &line) > 0)
	{
		e->tmp[e->x] = (char *)malloc(sizeof(char));
		e->tmp[e->x] = line;
			while(*line)
			{
						ft_atoi_p(&line);
						e->y++;
			}
		e->m[e->x] = (int)malloc(sizeof(int));
		e->m[e->x] = e->y;
		e->y = 0;
		e->x++;
	}
	close(fd);
	free(line);
	e->x_max = e->x;
}

void get_map(t_env *e, int av, char **ac)
{
	get_map_(e,av,ac);
	e->map = (int **)malloc(sizeof(int *) * e->x_max + 1);
	e->x = 0;
	e->y = 0;
	while(e->x < e->x_max)
	{
		e->map[e->x] = (int *)malloc(sizeof(int) * e->m[e->x]);
		while(e->y < e->m[e->x])
		{
			e->map[e->x][e->y] = ft_atoi_p(&e->tmp[e->x]);
			e->y++;
		}
		e->y = 0;
		e->x++;
	}
		//print_map(e);
}
