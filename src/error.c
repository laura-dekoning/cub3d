/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:13:13 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 16:05:11 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_free_game_and_data(t_game *game, t_data *data, char *str)
{
	if (game)
		free_game(game);
	if (data)
		free_data(data);
	ft_putendl_fd(B_R"Error"DEF, 2);
	ft_putendl_fd(str, 2);
	exit(FAILURE);
}

void	error_free_game(t_game *game, char *str)
{
	if (game)
		free_game(game);
	ft_putendl_fd(B_R"Error"DEF, 2);
	ft_putendl_fd(str, 2);
	exit(FAILURE);
}

void	error_free_data(t_data *data, char *str)
{
	if (data)
		free_data(data);
	ft_putendl_fd(B_R"Error"DEF, 2);
	ft_putendl_fd(str, 2);
	exit(FAILURE);
}

void	error(char *str)
{
	ft_putendl_fd(B_R"Error"DEF, 2);
	ft_putendl_fd(str, 2);
	exit(FAILURE);
}
