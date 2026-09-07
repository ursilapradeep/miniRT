/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_axes_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:03:36 by ybutkov           #+#    #+#             */
/*   Updated: 2026/09/07 12:54:37 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void put_number(t_mlx *mlx, int x, int y, double value)
{
	char text[32];

	snprintf(text, sizeof(text), "%.2f", value);
	mlx_string_put(mlx->mlx, mlx->win, x, y, 0xFFFFFF, text);
}

static void put_axis_labels(t_app *app)
{
	mlx_string_put(app->mlx->mlx, app->mlx->win, WIN_WIDTH - 75, 18,
		0xFFFFFF, "Camera axes");
	mlx_string_put(app->mlx->mlx, app->mlx->win, WIN_WIDTH - 30, 65,
		0xFF0000, "X");
	mlx_string_put(app->mlx->mlx, app->mlx->win, WIN_WIDTH - 75, 20,
		0x00FF00, "Y");
	mlx_string_put(app->mlx->mlx, app->mlx->win, WIN_WIDTH - 100, 65,
		0x0000FF, "Z");
}

void draw_axes_labels(t_app *app)
{
	t_camera *camera;

	if (app == NULL || app->mlx == NULL || app->scene == NULL)
		return ;
	camera = &app->scene->camera;
	put_axis_labels(app);
	mlx_string_put(app->mlx->mlx, app->mlx->win, 20, 25, 0xFFFFFF,
		"Camera position:");
	mlx_string_put(app->mlx->mlx, app->mlx->win, 20, 45, 0xFFFFFF, "X:");
	put_number(app->mlx, 40, 45, camera->coordinates.x);
	mlx_string_put(app->mlx->mlx, app->mlx->win, 115, 45, 0xFFFFFF, "Y:");
	put_number(app->mlx, 135, 45, camera->coordinates.y);
	mlx_string_put(app->mlx->mlx, app->mlx->win, 210, 45, 0xFFFFFF, "Z:");
	put_number(app->mlx, 230, 45, camera->coordinates.z);
	mlx_string_put(app->mlx->mlx, app->mlx->win, 20, 75, 0xFFFFFF,
		"Direction:");
	mlx_string_put(app->mlx->mlx, app->mlx->win, 20, 95, 0xFFFFFF, "X:");
	put_number(app->mlx, 40, 95, camera->direction.x);
	mlx_string_put(app->mlx->mlx, app->mlx->win, 115, 95, 0xFFFFFF, "Y:");
	put_number(app->mlx, 135, 95, camera->direction.y);
	mlx_string_put(app->mlx->mlx, app->mlx->win, 210, 95, 0xFFFFFF, "Z:");
	put_number(app->mlx, 230, 95, camera->direction.z);
	mlx_string_put(app->mlx->mlx, app->mlx->win, 20, 125, 0xFFFFFF,
		"FOV:");
	put_number(app->mlx, 55, 125, camera->fov);
}
