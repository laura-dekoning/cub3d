/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_clear_exit.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:42:03 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/13 20:54:22 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

void	error_and_exit(char *str)
{
	ft_putendl_fd(B_R"Error: "DEF, 2);
	ft_putendl_fd(str, 2);
	exit(FAILURE);
}

void	free_fake_parsing(t_data *data)
{
	int i;
	// free player
	free(data->player);
	
	// free map
    i = 0; 
	while (i < data->map->rows)
	{
        free(data->map->map[i]);
		i++;
	}
    free(data->map->map);
	free(data->map);
}

void	clear_everything(t_data *data)
{
	free_fake_parsing(data);
	free(data);
}
