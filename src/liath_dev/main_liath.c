/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:27 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/07 15:10:25 by livliege      ########   odam.nl         */
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
	// parsing
	init_window(data);
	printf("window done!!\n");

	clear_everything(data);
	printf("DONE!\n");
}