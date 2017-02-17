/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 06:53:25 by abarriel          #+#    #+#             */
/*   Updated: 2017/02/17 16:37:50 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allume_pixel(int x, int y, t_env *e)
{
	if ((x > 0 && x < e->win_longu) && (y > 0 && y < e->win_large))
	{
		if (e->tab[e->i][e->x][2] > 0)
			e->data[y * (e->slen / 4) + x] = e->color;
		else
			e->data[y * (e->slen / 4) + x] = e->color2;
	}
}

void	line_(t_algo *a, t_env *e, int i)
{
	e->cumul = a->dy / 2;
	while (++i <= a->dy)
	{
		a->y0 += a->yinc;
		e->cumul += a->dx;
		if (e->cumul >= a->dy)
		{
			e->cumul -= a->dy;
			a->x0 += a->xinc;
		}
		allume_pixel(a->x0, a->y0, e);
	}
}

void	line(t_algo *a, t_env *e)
{
	int	i;

	i = 0;
	a->dx = abs(a->x1 - a->x0);
	a->xinc = (a->x0 < a->x1) ? 1 : -1;
	a->dy = abs(a->y1 - a->y0);
	a->yinc = (a->y0 < a->y1) ? 1 : -1;
	allume_pixel(a->x0, a->y0, e);
	if (a->dx > a->dy)
	{
		e->cumul = a->dx / 2;
		while (++i <= a->dx)
		{
			a->x0 += a->xinc;
			e->cumul += a->dy;
			if (e->cumul >= a->dx)
			{
				e->cumul -= a->dx;
				a->y0 += a->yinc;
			}
			allume_pixel(a->x0, a->y0, e);
		}
	}
	else
		line_(a, e, 0);
}

void	send_trace_(t_env *e, t_algo *a)
{
	if (e->x < (e->nbcolon - 1))
	{
		a->x0 = e->tab[e->i][e->x][0];
		a->y0 = e->tab[e->i][e->x][1];
		a->x1 = e->tab[e->i][e->x + 1][0];
		a->y1 = e->tab[e->i][e->x + 1][1];
		line(a, e);
	}
	if (e->i < (e->nbline - 1))
	{
		a->x0 = e->tab[e->i][e->x][0];
		a->y0 = e->tab[e->i][e->x][1];
		a->x1 = e->tab[e->i + 1][e->x][0];
		a->y1 = e->tab[e->i + 1][e->x][1];
		line(a, e);
	}
}

void	send_trace(t_env *e)
{
	t_algo a;

	e->i = -1;
	e->x = -1;
	while (++e->i < e->nbline)
	{
		while (++e->x < e->nbcolon)
			send_trace_(e, &a);
		e->x = -1;
	}
}
