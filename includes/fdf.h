/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:07:23 by abarriel          #+#    #+#             */
/*   Updated: 2017/01/27 23:07:26 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mlx.h>

typedef struct	s_env
{
	void	*mlx;
	char *mlx_get_data;
	int		win_large;
	int		win_longu;
	void	*win;
	int		**map;
	int		*m;
	char	*data;
	char 	**tmp;
	int 	x;
	int 	y;
	int		z;
	void 	*img;
	int		x_max;
	int		y_max;
}				t_env;
void	get_map(t_env *e, int av, char **ac);
void	get_window(t_env *e);
void get_img(t_env *e);
int		my_key_funct(int keycode, void *param);
void	add_pix(t_env *e);
