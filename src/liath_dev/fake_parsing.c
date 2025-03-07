/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fake_parsing.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 16:40:29 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/07 17:32:34 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"


void fake_parsing(t_data *data)
{

	data->player = (t_player *)ft_calloc(sizeof(t_player), 1);
	if (data->player == NULL)
		error_and_exit("Malloc allocation failed\n");
	data->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (data->map == NULL)
		error_and_exit("Malloc allocation failed\n");


	int map[] = { \
		1, 1, 1, 1, 1, 1, 1, 1, \
		1, 0, 0, 0, 0, 0, 0, 1, \
		1, 0, 0, 0, 0, 0, 0, 1, \
		1, 0, 0, 0, 0, 0, 0, 1, \
		1, 0, 0, 0, 0, 0, 0, 1, \
		1, 0, 0, 0, 0, 0, 0, 1, \
		1, 0, 0, 0, 0, 0, 0, 1, \
		1, 1, 1, 1, 1, 1, 1, 1, \
	};

	
	data->player->x = 300;
	data->player->y = 300;

	data->map->cols = 8;
	data->map->rows = 8;
	data->map->size = 64;
	data->map->map = map;
	
	
} 
