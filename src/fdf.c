/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 21:56:08 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/27 21:56:11 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_key_funct(int keycode, void *param)
{
	ft_printf("key event %d\n",keycode);
	if (keycode == 53)
		exit(0);
	keycode = 1;
	return 0;
}

t_env	*set_env()
{
	t_env *tmp;

	tmp = (t_env *)malloc(sizeof(t_env));
	tmp->mlx = mlx_init();
	tmp->x = 0;
	tmp->win_large = 1200;
	tmp->win_longu = 2000;
	tmp->y = 0;
	tmp->x_max = 0;
	tmp->y_max = 0;
	return (tmp);
}

int main(int av, char **ac)
{
	t_env *e;

	e = set_env();
	e->win = mlx_new_window(e->mlx, e->win_longu, e->win_large, "FDF");
	//get_map(e, av, ac);
	get_img(e);
	// y = 50;
	// while (y < 150)
	// {
	// 	x = 50;
	// 	while (x < 150)
	// 	{
	// 		mlx_pixel_put(e->mlx, e->win, x, y, 0xFF00FFF);
	// 		x++;
	// 	}
	// 	y++;
	// }
	mlx_key_hook(e->win, my_key_funct, 0);
	mlx_loop(e->mlx);
	// mlx_key_hook(e->win, my_key_funct, 0);
	// mlx_loop(e->mlx);
	return (0);
}
