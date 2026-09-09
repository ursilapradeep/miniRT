/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:10:59 by uvadakku          #+#    #+#             */
/*   Updated: 2026/09/07 15:26:21 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	setup_hooks(t_app *app)
{
	mlx_hook(app->mlx->win, 2, 1L << 0, handle_key, app);
	mlx_mouse_hook(app->mlx->win, handle_mouse, app);
	mlx_hook(app->mlx->win, 17, 0, handle_close, app);
}

void	destroy_app(t_app *app)
{
	if (app == NULL)
		return ;
	if (app->scene != NULL)
		free_scene(app->scene);
	destroy_mlx(app->mlx);
}
