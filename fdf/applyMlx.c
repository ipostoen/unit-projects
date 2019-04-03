/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applyMlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipostoen <ipostoen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 13:19:12 by ipostoen          #+#    #+#             */
/*   Updated: 2018/06/10 19:46:41 by ipostoen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void		ft_textDiscr(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->window, 20, 20,
									0xFFFFFF, "Arrows - Translate");
	mlx_string_put(mlx->mlx, mlx->window, 20, 40, 0xFFFFFF, "WASD - Rotate");
	mlx_string_put(mlx->mlx, mlx->window, 20, 60, 0xFFFFFF, "+-   - Scale");
	mlx_string_put(mlx->mlx, mlx->window, 20, 80, 0xFFFFFF, "<--  - Reset");
	mlx_string_put(mlx->mlx, mlx->window, 20, 100,
											0xFFFFFF, "P    - Perspective");
	mlx_string_put(mlx->mlx, mlx->window, 20, 120,
											0xFFFFFF, "*    - Reset ALL");
}

void			ft_newImg(t_mlx *mlx)
{
	if (!(mlx->img.img = mlx_new_image(mlx->mlx, WIN_W, WIN_H)))
	{
		if (mlx->img.img)
			mlx_destroy_image(mlx->mlx, mlx->img.img);
		ft_memdel((void **)&mlx->img);
	}
	mlx->img.ptr = mlx_get_data_addr(mlx->img.img,
	&mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
	mlx->img.bpp /= 8;
}

void    ft_applyMlx(char *tit, t_mlx *mlx)
{
    if (!(mlx->mlx = mlx_init()))
		printf("MLX init ERROR\n");
	if (!(mlx->window = mlx_new_window(mlx->mlx, WIN_W, WIN_H, tit)))
		printf("Open window ERROR\n");
	if (tit)
		free(tit);
	ft_newImg(mlx);
	ft_textDiscr(mlx);
	mlx->form.x = -0.1;
	mlx->form.y = 6.5;
	mlx->form.z = 12.0;
	mlx->form.color = 0xFFFFFF;
	mlx->form.scale = ((double)mlx->fdf.heigth / (double)WIN_H >
							(double)mlx->fdf.width / (double)WIN_W) ?
	((double)mlx->fdf.heigth - (double)WIN_H) / (double)mlx->fdf.heigth :
	((double)mlx->fdf.width - (double)WIN_W) / (double)mlx->fdf.width;
	mlx->form.scale = ABS(mlx->form.scale / 2);
	if (mlx->form.scale < 1)
		mlx->form.scale = 1;
	mlx->form.offsetx = WIN_W / 2;
	mlx->form.offsety = WIN_H / 2;
}