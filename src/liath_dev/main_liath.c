/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_liath.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:27 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/07 16:48:04 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	(void)argc;
	
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		error_and_exit("Malloc allocation failed\n");

	fake_parsing(data);	// replace with Laura's killer parser

	// LIATHS JOB!
	init_window(data);
	clear_everything(data);
	printf("CLEAN EXIT!\n");
}
