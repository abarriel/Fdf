/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:07:23 by abarriel          #+#    #+#             */
/*   Updated: 2017/02/17 10:28:47 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>

typedef struct	s_algo
{
	int			dx;
	int			xinc;
	int			dy;
	int			yinc;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_algo;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			*data;
	int			*m;
	void		*img;
	int			**map;
	int			***tab;
	char		**smap;
	int			win_large;
	int			win_longu;
	int			nbline;
	int			slen;
	int			nbcolon;
	int			x;
	int			pente;
	int			cumul;
	int			y;
	int			p;
	int			i;
	int			key;
	int			e;
	int			z;
	int			sy;
	int			sx;
	int			fy;
	int			fx;
	int			color;
	int			color2;
	int			u;
}				t_env;
void 			qds(t_env *e);
void 			create_img(t_env *e);
void			line(t_algo *algo, t_env *e);
void			create_tab(t_env *e);
int				get(t_env *e, int av, char **ac);
void			get_window(t_env *e);
void			send_trace(t_env *e);
int				handles_keys(int key, t_env *e);
#endif
