/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safe_calloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:08:01 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 15:40:42 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*safe_calloc(t_game *game, t_data *data, size_t count, size_t size)
{
	void	*ptr;

	if (data == NULL)
	{
		ptr = ft_calloc(count, size);
		if (!ptr)
			error_free_game(game, MALLOC);
	}
	else if (game == NULL)
	{
		ptr = ft_calloc(count, size);
		if (!ptr)
			error_free_data(data, MALLOC);
	}
	else
	{
		ptr = ft_calloc(count, size);
		if (!ptr)
			error_free_game_and_data(game, data, MALLOC);
	}
	return (ptr);
}
