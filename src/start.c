/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 03:40:13 by abarriel          #+#    #+#             */
/*   Updated: 2017/02/14 03:40:19 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void get_img(t_env *e)
{
  int x = 0;
  int y = 0;
  int bpp = 0;
  int size_line = 0;
  int *da;
  int endian = 0;
  e->img = mlx_new_image(e->mlx, 2000, 1200);
   da = (int *)mlx_get_data_addr(e->img, &bpp, &size_line,&endian);
  mlx_put_image_to_window(e->mlx, e->win,e->img, 0,0);
    while(x < 400)
    {
      da[x] = 1441;
      x++;
    }
}
