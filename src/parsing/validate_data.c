/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:27:05 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/16 16:42:25 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_player(t_data *data)
{
	int	cols;
	int	rows;

	cols = (int)data->map->cols;
	rows = (int)data->map->rows;
	printf("rows = %i\ty = %i\ncols = %i\tx = %i\n", rows, data->player->y, cols, data->player->x);
	if (data->player->dir < 0 || data->player->dir > 3)
		error_free_data(data, "Player direction is missing!");
	else if (data->player->x < 0 || data->player->x > cols)
		error_free_data(data, "Player x is missing or incorrect!");
	else if (data->player->y < 0 || data->player->y > rows)
		error_free_data(data, "Player y is missing or incorrect!");
}

static void	check_textures(t_data *data, char *texture)
{
	if (ft_strncmp(texture + ft_strlen(texture) - 4,
			".png", 4))
		error_free_data(data, TEXTURE);
}

static void	check_rgb(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->floor[i] > 255 || data->ceiling[i] > 255)
			error_free_data(data, BIG);
		i++;
	}
}

void	validate_data(t_data *data)
{
	check_rgb(data);
	check_textures(data, data->north_texture);
	check_textures(data, data->east_texture);
	check_textures(data, data->south_texture);
	check_textures(data, data->west_texture);
	check_player(data);
}
