/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 21:56:08 by abarriel          #+#    #+#             */
/*   Updated: 2017/02/17 10:20:32 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hook_mod(int code, t_env *e)
{
	create_img(e);
	return (0);
}

void	set_env(t_env *p)
{
	p->mlx = mlx_init();
	p->pente = 6;
	p->data = NULL;
	p->map = NULL;
	p->tab = NULL;
	p->img = NULL;
	p->nbcolon = 0;
	p->nbline = 0;
	p->color = 0xFFFFFF;
	p->e = 2;
	p->key = 0;
	p->color2 = 0xFFFFFF;
	p->win_large = 1200;
	p->win_longu = 2000;
	p->sy = 500;
	p->sx = 0;
	p->y = -1;
	p->u = 1;
	p->i = -1;
	p->x = -1;
	p->z = 0;
}

int		main(int av, char **ac)
{
	t_env	e;

	if (av != 2)
	{
		ft_dprintf(2, "Too Many/Few Arguments\n");
		return (-1);
	}
	set_env(&e);
	get(&e, av, ac);
	mlx_key_hook(e.win, handles_keys, &e);
	mlx_hook(e.win, 2, 0, hook_mod, &e);
	mlx_loop(e.mlx);
	return (0);
}
