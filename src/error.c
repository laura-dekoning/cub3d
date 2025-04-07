/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:13:13 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 15:29:21 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message(t_game *game, t_data *data, char *str, int flag)
{
	if (flag == 1)
	{
		if (game)
			free_game(game);
	}
	else if (flag == 2)
	{
		if (data)
			free_data(data);
	}
	else if (flag == 3)
	{
		if (game)
			free_game(game);
		if (data)
			free_data(data);
	}
	ft_putendl_fd(B_R"Error"DEF, 2);
	ft_putendl_fd(str, 2);
	exit(FAILURE);
}
