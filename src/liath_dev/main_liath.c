/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_liath.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:27 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/18 22:54:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	(void)argc;
	
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		error_and_exit("Malloc allocation failed\n");

// in this rewrite we finished the parsing, the players pos is now the x and y index of the map.
// plan: to write the game again, but instead of doing the calculations acording to the minimap, we want to see if we can just draw the 3d game like this.
// later we will turn these calculations into a minimap.
	fake_parsing(data);

// ======= THE GAME =======//
	cub3d(data);
	// init_window(data);
// ========================//
	clear_everything(data);
	printf("CLEAN EXIT!\n");
}
