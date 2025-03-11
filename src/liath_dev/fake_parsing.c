/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fake_parsing.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 16:40:29 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/11 23:19:16 by anonymous     ########   odam.nl         */
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
	// MAP:
	data->map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (data->map == NULL)
		error_and_exit("Malloc allocation failed\n");

	data->map->grid_size = GRIDSIZE;
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

	// PLAYER:
	data->player = (t_player *)ft_calloc(sizeof(t_player), 1);
	if (data->player == NULL)
		error_and_exit("Malloc allocation failed\n");

	data->player->pos.x = 300;
	data->player->pos.y = 300;

	data->player->angle = 0;
	
	data->player->dir.x = cos(data->player->angle);  
	data->player->dir.y = sin(data->player->angle);  
	
}
