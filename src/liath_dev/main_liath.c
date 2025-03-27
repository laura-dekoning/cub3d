/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_liath.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:27 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/27 16:57:21 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	// (void)argv;
	// (void)argc;
	
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
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
