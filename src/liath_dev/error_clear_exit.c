/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_clear_exit.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:42:03 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/04 13:46:06 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_and_exit(char *str)
{
	ft_putendl_fd(B_R"Error: "DEF, 2);
	ft_putendl_fd(str, 2);
	exit(FAILURE);
}

void	clear_everything(t_game *data)
{
	size_t i;

	i = 0; 
	while (i < data->map->rows)
	{
		free(data->map->map[i]);
		i++;
	}
	free(data->map->map);
	free(data->map);
	free(data);
}




