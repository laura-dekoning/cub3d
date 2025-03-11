/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fake_parsing.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 16:40:29 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/12 00:11:29 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"


	// char temp_map[8][8] =
	// {
	// 	"11111111",
	// 	"10100001",
	// 	"10100001",
	// 	"10100001",
	// 	"10000001",
	// 	"10000101",
	// 	"10000001",
	// 	"11111111"};

	
void fake_parsing(t_data *data)
{

	data->player = (t_player *)ft_calloc(sizeof(t_player), 1);
	if (data->player == NULL)
		error_and_exit("Malloc allocation failed\n");
		
	data->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (data->map == NULL)
		error_and_exit("Malloc allocation failed\n");


	data->map->rows = 5;	// y
	data->map->cols = 6;	// x

	char temp_map[5][6] =
	{
		"111111",
		"100101",
		"101001",
		"1100N1",
		"111111"};


		
	data->map->map = (char **)malloc(data->map->rows * sizeof(char *));
	if (data->map->map == NULL)
		error_and_exit("Malloc allocation failed\n");

	for (int i = 0; i < data->map->rows; i++)
	{
		data->map->map[i] = malloc(data->map->cols * sizeof(char));
		if (data->map->map[i] == NULL)
			error_and_exit("Malloc allocation failed\n");
	}
		
	for (int i = 0; i < data->map->rows; i++)
	{
		for (int j = 0; j < data->map->cols; j++)
		{
			data->map->map[i][j] = temp_map[i][j];
		}
	}

	int x;
	int y;
	
	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
			if (!ft_isdigit(data->map->map[y][x]))
			{
				if(data->map->map[y][x] == 'N')
				{
					data->player->angle = DIR_NORTH;
					data->player->pos.x = (x + 0.5) * GRIDSIZE + x;
					data->player->pos.y = (y + 0.5) * GRIDSIZE + y;
				}
				if(data->map->map[y][x] == 'S')
				{
					data->player->angle = DIR_SOUTH;
					data->player->pos.x = (x + 0.5) * GRIDSIZE + x;
					data->player->pos.y = (y + 0.5) * GRIDSIZE + y;
				}
				if(data->map->map[y][x] == 'E')
				{
					data->player->angle = DIR_EAST;
					data->player->pos.x = (x + 0.5) * GRIDSIZE + x;
					data->player->pos.y = (y + 0.5) * GRIDSIZE + y;
				}
				if(data->map->map[y][x] == 'W')
				{
					data->player->angle = DIR_WEST;
					data->player->pos.x = (x + 0.5) * GRIDSIZE + x;
					data->player->pos.y = (y + 0.5) * GRIDSIZE + y;
				}
			}
			x++;
		}
		y++;
	}
	
	data->player->dir.x = cos(data->player->angle);  
	data->player->dir.y = sin(data->player->angle);  
	
}
