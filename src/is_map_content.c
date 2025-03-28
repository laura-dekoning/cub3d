/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_map_content.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/20 13:55:58 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 13:13:23 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static bool	map_content(char c)
// {
// 	if (c == ' ' || c == '1' || c == '0')
// 		return (true);
// 	return (false);
// }

bool	is_map_content(char *str, int start)
{
	if (!ft_strchr(str + start, '0') || !ft_strchr(str + start, '1'))
		return (false);
	return (true);
}
