/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 01:07:42 by abarriel          #+#    #+#             */
/*   Updated: 2017/02/17 16:36:28 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	qds(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 1180, 0XFF0000, "QUIT: ESC ||");
	mlx_string_put(e->mlx, e->win, 240, 1180, 0XFF0000, "ZOOM: +/-");
	mlx_string_put(e->mlx, e->win, 410, 1180, 0XFF0000, "LEFT - RIGHT: < / >");
	mlx_string_put(e->mlx, e->win, 700, 1180, 0XFF0000, "UP - DOWN:  Arrow ");
	mlx_string_put(e->mlx, e->win, 1060, 1180, 0XFF0000, "COLOR: C");
	mlx_string_put(e->mlx, e->win, 1360, 1180, 0XFF0000, "RESET COLOR: R");
	mlx_string_put(e->mlx, e->win, 1860, 1180, 0XFF0000, "RELIEF: H / B");
}

int		handles_keys_(int key, t_env *e)
{
	if (key == 124)
		e->sx += 25;
	if (key == 123)
		e->sx -= 25;
	if (key == 125)
		e->sy += 25;
	if (key == 126)
		e->sy -= 25;
	if (key == 69)
		e->e += 1;
	if (key == 78)
		e->e -= 1;
	if (key == 4)
		e->pente += 2;
	if (key == 11)
		e->pente -= 2;
	key = 1;
}

int		handles_keys(int key, t_env *e)
{
	e->key = key;
	if (key == 53)
		exit(0);
	if (key == 8)
	{
		e->color2 *= 3;
		e->color *= 2;
		if (e->color == 0)
			e->color = 0x708090;
		if (e->color2 == 0)
			e->color2 = 0x0000cd;
	}
	if (key == 15)
	{
		e->color = 0XFFFFFF;
		e->color2 = e->color;
	}
	handles_keys_(key, e);
	return (0);
}
