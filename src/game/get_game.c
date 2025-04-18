/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/04 14:34:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/18 17:00:25 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(t_game *game, t_data *data)
{
	size_t	i;
	size_t	rows;

	rows = data->map->rows;
	game->map->rows = data->map->rows;
	game->map->cols = data->map->cols;
	game->map->map_width_px = data->map->cols * GRIDSIZE;
	game->map->map_height_px = data->map->rows * GRIDSIZE;
	game->map->map = (char **)safe_calloc(game, data, rows + 1, sizeof(char *));
	i = 0;
	while (i < game->map->rows)
	{
		game->map->map[i] = ft_strdup(data->map->map[i]);
		if (game->map->map[i] == NULL)
		{
			error_free_game_and_data(game, data, MALLOC);
		}
		i++;
	}
}

void	parse_player(t_game *game, t_data *data)
{
	float	offset;

	offset = GRIDSIZE / 2;
	if (data->player->dir == NORTH)
		game->player->angle = DIR_NORTH;
	else if (data->player->dir == EAST)
		game->player->angle = DIR_EAST;
	else if (data->player->dir == SOUTH)
		game->player->angle = DIR_SOUTH;
	else if (data->player->dir == WEST)
		game->player->angle = DIR_WEST;
	game->player->pos.x = (data->player->x * GRIDSIZE) + offset;
	game->player->pos.y = (data->player->y * GRIDSIZE) + offset;
	game->player->dir.x = cos(game->player->angle);
	game->player->dir.y = sin(game->player->angle);
	game->player->size = game->minimap.minimap_size / MINIMAP_GRID;
	game->player->wall_hit = false;
}

void	get_game(t_game *game, t_data *data)
{
	int	*f;
	int	*c;

	f = data->floor;
	c = data->ceiling;
	game->floor_colour = rgb_to_hex(f[0], f[1], f[2], 255);
	game->ceiling_colour = rgb_to_hex(c[0], c[1], c[2], 255);
	init_wall_textures(game, data);
	init_window(game);
	init_minimap_image(game);
	parse_map(game, data);
	parse_player(game, data);
	free_data(data);
}
