/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:28 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/24 12:23:16 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	const char	*file;
	t_data		*data;
	t_game		*game;
	size_t		len;

	if (argc != 2)
		error(ARGS);
	file = argv[1];
	len = ft_strlen(file);
	if (len < 5 || (ft_strncmp(file + len - 4, ".cub", 4)))
		error(FILE);
	data = (t_data *)alloc_mem_for_data();
	get_data(data, file);
	game = (t_game *)alloc_mem_for_game(data);
	get_game(game, data);
	cub3d(game);
	free_game(game);
	return (0);
}
