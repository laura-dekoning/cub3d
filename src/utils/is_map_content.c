/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_map_content.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/20 13:55:58 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/10 14:15:17 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_content(char *str)
{
	if (ft_strchr(str, '0') || ft_strchr(str, '1'))
		return (true);
	return (false);
}
