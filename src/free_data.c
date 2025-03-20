/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:21:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/20 18:20:45 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//MAKE SURE EVERYTHING IS FREED!!!! Might need to add some extras for Liath stuff and extra added things in struct

static void	free_int_arr(t_data *data)
{
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
}

static void	free_textures(t_data *data)
{
	if (data->north_texture)
		free(data->north_texture);
	if (data->south_texture)
		free(data->south_texture);
	if (data->east_texture)
		free(data->east_texture);
	if (data->west_texture)
		free(data->west_texture);
}

void	free_data(t_data *data)
{
	if (data)
	{
		free_textures(data);
		free_int_arr(data);
		if (data->map)
		{
			ft_free_arr(data->map->map);
			free(data->map);
		}
		if (data->player)
			free(data->player);
		if (data->check)
			free(data->check);
		free(data);
	}
}
