/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvadakku <uvadakku@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 16:28:29 by uvadakku          #+#    #+#             */
/*   Updated: 2026/07/20 16:34:57 by uvadakku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "parse.h"
#include "../libft/libft.h"

int  dispatch_scene_parsing(t_scene *scene, char **tokens)
{
	char *type;

	type = tokens[0];
	if(ft_strncmp(type, "A", 2) == 0)
		return (parse_ambient(scene, tokens));
	if(ft_strncmp(type, "C", 2) == 0)
		return (parse_camera(scene, tokens));
	if(ft_strncmp(type, "L", 2) == 0)
		return (parse_light(scene, tokens));
	if(ft_strncmp(type, "sp", 3) == 0)
		return (parse_sphere(scene, tokens));
	if(ft_strncmp(type, "pl", 3) == 0)
		return (parse_plane(scene, tokens));
	if(ft_strncmp(type, "cy", 3) == 0)
		return (parse_cylinder(scene, tokens));
	return (0);
}
