
#include "./fdf.h"

void		image_set_pixel(t_img *i, int x, int y, int color)
{
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	*(int *)(i->ptr + ((x + y * WIN_W) * i->bpp)) = color;
}

static void		plot_line_low(t_mlx *mlx, t_line *l)
{
	int x;
	int y;

	y = ROUND(l->from.y);
	x = ROUND(l->from.x);
	l->dx = ROUND(l->to.x) - x;
	l->dy = ROUND(l->to.y) - y;
	l->yi = 1;
	if (l->dy < 0)
	{
		l->yi = -1;
		l->dy = -(l->dy);
	}
	l->big_d = 2 * l->dy - l->dx;
	while (x++ != ROUND(l->to.x))
	{
		image_set_pixel(&mlx->img, x, y, mlx->form.color);
		if (l->big_d > 0)
		{
			y += l->yi;
			l->big_d -= 2 * l->dx;
		}
		l->big_d += 2 * l->dy;
	}
}

static void		plot_line_high(t_mlx *mlx, t_line *l)
{
	int x;
	int y;

	y = ROUND(l->from.y);
	x = ROUND(l->from.x);
	// printf ("Y == %f\n", l->from.y);
	l->dx = ROUND(l->to.x) - x;
	l->dy = ROUND(l->to.y) - y;
	l->xi = 1;
	if (l->dx < 0)
	{
		l->xi = -1;
		l->dx = -(l->dx);
	}
	l->big_d = 2 * l->dx - l->dy;
	while (y++ != ROUND(l->to.y))
	{
		image_set_pixel(&mlx->img, x, y, mlx->form.color);
		if (l->big_d > 0)
		{
			x += l->xi;
			l->big_d -= 2 * l->dy;
		}
		l->big_d += 2 * l->dx;
	}
}

void		set_direction(t_line *l, t_pix from, t_pix to)
{
	l->from = from;
	l->to = to;
}

void			plot_line(t_pix p0, t_pix p1, t_mlx *mlx)
{
	t_line	line;

	if ((p0.x < 0 || p0.x >= WIN_W || p0.y < 0 || p0.y >= WIN_H)
		&& (p1.x < 0 || p1.x >= WIN_W || p1.y < 0 || p1.y >= WIN_H))
		return ;
	ft_bzero(&line, sizeof(line));
	if ((ABS((ROUND(p1.y) - ROUND(p0.y)))) <
					(ABS((ROUND(p1.x) - ROUND(p0.x)))))
	{
		if (p0.x > p1.x)
			set_direction(&line, p1, p0);
		else
			set_direction(&line, p0, p1);
		plot_line_low(mlx, &line);
	}
	else
	{
		if (p0.y > p1.y)
			set_direction(&line, p1, p0);
		else
			set_direction(&line, p0, p1);
		plot_line_high(mlx, &line);
	}
}
