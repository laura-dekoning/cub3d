/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_liath.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:27 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/21 09:17:25 by anonymous     ########   odam.nl         */
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

	fake_parsing(data);

// ======= THE GAME =======//
	cub3d(data);
// ========================//

	clear_everything(data);
	printf("CLEAN EXIT!\n");
}
