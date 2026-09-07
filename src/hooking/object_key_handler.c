/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_key_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:00:00 by uvadakku          #+#    #+#             */
/*   Updated: 2026/09/07 18:51:54 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

# define QUARTER_TURN 1.57079632679
# define OBJECT_STEP 0.05

#ifdef __APPLE__
# define KEY_OBJECT_UP 105
# define KEY_OBJECT_DOWN 107
# define KEY_OBJECT_LEFT 106
# define KEY_OBJECT_RIGHT 108
# define KEY_OBJECT_FORWARD 117
# define KEY_OBJECT_BACK 111
# define KEY_OBJECT_ROTATE_X_CW 122
# define KEY_OBJECT_ROTATE_X_CCW 120
# define KEY_OBJECT_ROTATE_Y_CW 99
# define KEY_OBJECT_ROTATE_Y_CCW 118
# define KEY_OBJECT_ROTATE_Z_CW 98
# define KEY_OBJECT_ROTATE_Z_CCW 110
#else
# define KEY_OBJECT_UP 105  // 'i'
# define KEY_OBJECT_DOWN 107 // 'k'
# define KEY_OBJECT_LEFT 106 // 'j'
# define KEY_OBJECT_RIGHT 108 // 'l'
# define KEY_OBJECT_FORWARD 117 // 'u'
# define KEY_OBJECT_BACK 111 // 'o'
# define KEY_OBJECT_ROTATE_X_CW 122 // 'z'
# define KEY_OBJECT_ROTATE_X_CCW 120 // 'x'
# define KEY_OBJECT_ROTATE_Y_CW 99 // 'c'
# define KEY_OBJECT_ROTATE_Y_CCW 118 // 'v'
# define KEY_OBJECT_ROTATE_Z_CW 98 // 'b'
# define KEY_OBJECT_ROTATE_Z_CCW 110 // 'n'
#endif

static bool	handle_object_move(int keycode, t_object *object)
{
	t_vec3	delta;

	if (object == NULL)
		return (false);
	delta = (t_vec3){0.0, 0.0, 0.0};
	if (keycode == KEY_OBJECT_UP)
		delta.y = OBJECT_STEP;
	else if (keycode == KEY_OBJECT_DOWN)
		delta.y = -OBJECT_STEP;
	else if (keycode == KEY_OBJECT_LEFT)
		delta.x = -OBJECT_STEP;
	else if (keycode == KEY_OBJECT_RIGHT)
		delta.x = OBJECT_STEP;
	else if (keycode == KEY_OBJECT_FORWARD)
		delta.z = OBJECT_STEP;
	else if (keycode == KEY_OBJECT_BACK)
		delta.z = -OBJECT_STEP;
	else
		return (false);
	object_translate(object, delta);
	return (true);
}

static bool	handle_object_rotate(int keycode, t_object *object)
{
	t_vec3	axis;
	double	angle;

	if (object == NULL)
		return (false);
	axis = (t_vec3){0.0, 0.0, 0.0};
	angle = QUARTER_TURN;
	if (keycode == KEY_OBJECT_ROTATE_X_CW)
		axis.x = 1.0;
	else if (keycode == KEY_OBJECT_ROTATE_X_CCW)
		axis.x = 1.0, angle = -QUARTER_TURN;
	else if (keycode == KEY_OBJECT_ROTATE_Y_CW)
		axis.y = 1.0;
	else if (keycode == KEY_OBJECT_ROTATE_Y_CCW)
		axis.y = 1.0, angle = -QUARTER_TURN;
	else if (keycode == KEY_OBJECT_ROTATE_Z_CW)
		axis.z = 1.0;
	else if (keycode == KEY_OBJECT_ROTATE_Z_CCW)
		axis.z = 1.0, angle = -QUARTER_TURN;
	else
		return (false);
	object_rotate(object, axis, angle);
	return (true);
}

bool	handle_object_key(int keycode, t_object *object)
{
	return (handle_object_move(keycode, object)
		|| handle_object_rotate(keycode, object));
}