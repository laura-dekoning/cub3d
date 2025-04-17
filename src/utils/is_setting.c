/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_setting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/20 15:38:53 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/17 13:47:10 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_setting(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[i], "EA", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[i], "SO", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[i], "WE", 2) == 0)
		return (PATH);
	else if (ft_strncmp(&line[i], "F", 1) == 0)
		return (RGB);
	else if (ft_strncmp(&line[i], "C", 1) == 0)
		return (RGB);
	else if (is_map_content(line) == true)
		return (MAP);
	else
		return (NONE);
}
