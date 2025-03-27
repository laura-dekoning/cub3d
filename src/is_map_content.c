/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_map_content.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/20 13:55:58 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/27 07:56:09 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	map_content(char c)
{
	if (c != ' ' && c != '1' && c != '0')
		return (false);
	return (true);
}

bool	is_map_content(char *str, int start)
{
	int	i;

	i = start;
	while (str[i] != '\n')
	{
		if (map_content(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
