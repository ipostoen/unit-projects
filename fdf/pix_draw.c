
#include "./fdf.h"

t_pix			view_perspective(t_pix raw_p, t_mlx *mlx)
{
	t_pix	ret;

	ret.x = (double)(-raw_p.x / ((raw_p.z) / (1.0 *
			(mlx->fdf.max_z - mlx->fdf.min_z)) + mlx->fdf.max_z / (1.0 *
			(mlx->fdf.max_z - mlx->fdf.min_z))));
	ret.y = (double)(-raw_p.y / ((raw_p.z) / 10 + 1));
	ret.z = -1;
	ret.col_pix = raw_p.col_pix;
	return (ret);
}

t_pix			view_rotate(t_pix raw_p, t_form vw)
{
	t_pix	ret;

	ret.x = cos(vw.y) * raw_p.x - sin(vw.y) * raw_p.z;
	ret.z = sin(vw.y) * raw_p.x + cos(vw.y) * raw_p.z;
	ret.y = cos(vw.x) * raw_p.y + sin(vw.x) * ret.z;
	ret.z = -sin(vw.x) * raw_p.y + cos(vw.x) * ret.z;
	ret.x = ret.x * cos(vw.z) + ret.y * sin(vw.z);
	ret.y = ret.y * cos(vw.z) - ret.x * sin(vw.z);
	ret.col_pix = raw_p.col_pix;
	return (ret);
}

t_pix			prepare_point(t_pix raw_p, t_mlx *mlx)
{
	t_pix ret;

	ret.x = raw_p.x - (mlx->fdf.width - 1) / 2.0;
	ret.y = raw_p.y - (mlx->fdf.heigth - 1) / 2.0;
	ret.z = raw_p.z / (0.25 * (mlx->fdf.max_z - mlx->fdf.min_z));
	ret.col_pix = raw_p.col_pix;
	ret = view_rotate(ret, mlx->form);
	if (mlx->form.p)
		ret = view_perspective(ret, mlx);
	ret.x *= mlx->form.scale;
	ret.y *= mlx->form.scale;;
	ret.x += mlx->form.offsetx;
	ret.y += mlx->form.offsety;
	return (ret);
}