/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 03:40:13 by abarriel          #+#    #+#             */
/*   Updated: 2017/02/17 10:22:49 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ntab_(t_env *e)
{
	e->tab[e->i][e->z][0] = e->x + (e->e + (e->e / 2));
	e->x = e->tab[e->i][e->z][0];
	if (e->tab[e->i][e->z][2] <= 0)
	{
		e->tab[e->i][e->z][1] = e->y + (e->e / 2);
		e->y = e->tab[e->i][e->z][1] - e->e;
	}
	else
	{
		e->tab[e->i][e->z][1] =
		e->y + (e->e / 2) - (e->tab[e->i][e->z][2] * e->pente);
		e->y =
		e->tab[e->i][e->z][1] - e->e + (e->tab[e->i][e->z][2] * e->pente);
	}
}

void	ntab(t_env *e)
{
	e->i = -1;
	e->z = -1;
	while (++e->i != e->nbline)
	{
		while (++e->z != e->nbcolon)
			ntab_(e);
		e->x = e->fx + e->e + (e->e / 2);
		e->y = e->fy + e->e;
		e->fx = e->x;
		e->fy = e->y;
		e->z = -1;
	}
}

void	create_tab(t_env *e)
{
	e->y = -1;
	e->x = -1;
	if (!(e->tab = (int ***)malloc(sizeof(int **) * e->nbline)))
		ft_exit("Failed to Malloc");
	while (++e->y != e->nbline)
	{
		e->tab[e->y] = (int **)malloc(sizeof(int *) * e->nbcolon);
		while (++e->x != e->nbcolon)
		{
			e->tab[e->y][e->x] = (int *)malloc(sizeof(int) * 3);
			e->tab[e->y][e->x][0] = 0;
			e->tab[e->y][e->x][1] = 0;
			e->tab[e->y][e->x][2] = e->map[e->y][e->x];
		}
		e->x = -1;
	}
	e->fx = e->sx;
	e->fy = e->sy;
	e->x = e->fx;
	e->y = e->fy;
	ntab(e);
}
