/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fake_parsing.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 16:40:29 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/18 11:34:46 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"
	
void fake_parsing(t_data *data)
{
	data->player = (t_player *)ft_calloc(sizeof(t_player), 1);
	if (data->player == NULL)
		error_and_exit("Malloc allocation failed\n");

	data->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (data->map == NULL)
		error_and_exit("Malloc allocation failed\n");

	// data->map->rows = 5;   // y
	// data->map->cols = 6;   // x

	// char temp_map[5][6] = {
	// 	"111111",
	// 	"100101",
	// 	"101001",
	// 	"1000N1",
	// 	"111111"
	// };

	data->map->rows = 8;   // y
	data->map->cols = 8;   // x
	
	char temp_map[8][8] =
	{
		"11111111",
		"10100001",
		"10100001",
		"10110001",
		"100S0001",
		"10000101",
		"10000001",
		"11111111"
	};
	
	
	data->minimap_size.x = (data->map->cols * GRIDSIZE) + data->map->cols;
	data->minimap_size.y = (data->map->rows * GRIDSIZE) + data->map->rows;
	

	data->map->map = (char **)malloc(data->map->rows * sizeof(char *));
	if (data->map->map == NULL)
		error_and_exit("Malloc allocation failed\n");

	int i;
	int j;
	i = 0;
	while (i < data->map->rows) 
	{
		data->map->map[i] = malloc(data->map->cols * sizeof(char));
		if (data->map->map[i] == NULL)
			error_and_exit("Malloc allocation failed\n");
		i++;
	}
	i = 0;
	while (i < data->map->rows) 
	{
		j = 0;
		while (j < data->map->cols) 
		{
			data->map->map[i][j] = temp_map[i][j];
			j++;
		}
		i++;
	}
	
	int x;
	int y;
	float offset;
	
	offset = GRIDSIZE / 2;
	y = 0;
	while (y < data->map->rows) 
	{
		x = 0;
		while (x < data->map->cols) 
		{
			if (!ft_isdigit(data->map->map[y][x])) 
			{
				if (data->map->map[y][x] == 'N') 
				{
					data->player->angle = DIR_NORTH;
					data->player->pos.x = (x * GRIDSIZE) + offset;
					data->player->pos.y = (y * GRIDSIZE) + offset;
				}
				if (data->map->map[y][x] == 'S')
				{
					data->player->angle = DIR_SOUTH;
					data->player->pos.x = (x * GRIDSIZE) + offset;
					data->player->pos.y = (y * GRIDSIZE) + offset;
				}
				if (data->map->map[y][x] == 'E') 
				{
					data->player->angle = DIR_EAST;
					data->player->pos.x = (x * GRIDSIZE) + offset;
					data->player->pos.y = (y * GRIDSIZE) + offset;
				}
				if (data->map->map[y][x] == 'W')
				{
					data->player->angle = DIR_WEST;
					data->player->pos.x = (x * GRIDSIZE) + offset;
					data->player->pos.y = (y * GRIDSIZE) + offset;
				}
			}
			x++;
		}
		y++;
	}
	data->player->dir.x = cos(data->player->angle);
	data->player->dir.y = sin(data->player->angle);
	data->player->wall_hit = false;
}


