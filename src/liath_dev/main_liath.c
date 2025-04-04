/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_liath.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:27 by livliege      #+#    #+#                 */
/*   Updated: 2025/04/04 12:30:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*data;

	// (void)argv;
	// (void)argc;
	
	data = (t_game *)ft_calloc(sizeof(t_game), 1);
	if (data == NULL)
		error_and_exit("Malloc allocation failed\n");

	if (argc == 2 && ft_strcmp(argv[1], "lauliland") == 0)
	{
		printf("festival!\n");
		festival_parsing(data);
	}
	else
		fake_parsing(data);

	
// ======= THE GAME =======//
	cub3d(data);
// ========================//

	clear_everything(data);
	printf("CLEAN EXIT!\n");
}
