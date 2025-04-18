/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_window_and_images.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/18 14:21:24 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_wall_textures(t_game *game, t_data *data)
{
	game->textures.north_texture = mlx_load_png(data->north_texture);
	if (!game->textures.north_texture)
		error_free_game_and_data(game, data, "Loading north wall failed");
	game->textures.east_texture = mlx_load_png(data->east_texture);
	if (!game->textures.east_texture)
		error_free_game_and_data(game, data, "Loading east wall failed");
	game->textures.south_texture = mlx_load_png(data->south_texture);
	if (!game->textures.south_texture)
		error_free_game_and_data(game, data, "Loading south wall failed");
	game->textures.west_texture = mlx_load_png(data->west_texture);
	if (!game->textures.west_texture)
		error_free_game_and_data(game, data, "Loading west wall failed");
}

void	init_minimap_border_image(t_game *game)
{
	game->minimap_border_image = mlx_new_image(game->window, game->minimap.minimap_size + 2, game->minimap.minimap_size + 2);
	if (game->minimap_border_image == NULL)
	{
		mlx_terminate(game->window);
		error_free_game(game, "Image could not be created");
	}
	if (mlx_image_to_window(game->window, game->minimap_border_image, 9, 9) < 0)
	{
		mlx_delete_image(game->window, game->window_image);
		mlx_delete_image(game->window, game->minimap_image);
		mlx_terminate(game->window);
		error_free_game(game, "Image could not be displayed on the window");
	}
}

void	get_minimap_size(t_game *game)
{
	if (WINDOW_HEIGHT > WINDOW_WIDTH)
		game->minimap.minimap_size = WINDOW_WIDTH / MINIMAP_SCALE;
	else
		game->minimap.minimap_size = WINDOW_HEIGHT / MINIMAP_SCALE;
}

void	init_minimap_image(t_game *game)
{
	get_minimap_size(game);
	game->minimap_image = mlx_new_image(game->window, game->minimap.minimap_size, game->minimap.minimap_size);
	if (game->minimap_image == NULL)
	{
		mlx_terminate(game->window);
		error_free_game(game, "Image could not be created");
	}
	if (mlx_image_to_window(game->window, game->minimap_image, 10, 10) < 0)
	{
		mlx_delete_image(game->window, game->window_image);
		mlx_terminate(game->window);
		error_free_game(game, "Image could not be displayed on the window");
	}
	init_minimap_border_image(game);
}

void	init_window(t_game *game)
{
	game->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	if (game->window == NULL)
	{
		error_free_game(game, "Window could not be created");
	}
	game->window_image = mlx_new_image(game->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (game->window_image == NULL)
	{
		mlx_terminate(game->window);
		error_free_game(game, "Image could not be created");
	}
	if (mlx_image_to_window(game->window, game->window_image, 0, 0) < 0)
	{
		mlx_terminate(game->window);
		error_free_game(game, "Image could not be displayed on the window");
	}
}
