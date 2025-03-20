/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_setting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/20 15:38:53 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/20 15:39:01 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_setting(char *line, size_t start)
{
	if (ft_strncmp(&line[start], "NO", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[start], "EA", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[start], "SO", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[start], "WE", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[start], "F", 1) == 0)
		return (RGB);
	else if (ft_strncmp(&line[start], "C", 1) == 0)
		return (RGB);
	else if (is_map_content(line, start) == true)
		return (MAP);
	else
		return (NONE);
}
