/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_setting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/20 15:38:53 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 17:49:37 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_setting(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (PATH);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (PATH);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (PATH);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (PATH);
	else if (ft_strncmp(line, "F", 1) == 0)
		return (RGB);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (RGB);
	else if (is_map_content(line) == true)
		return (MAP);
	else
		return (NONE);
}
