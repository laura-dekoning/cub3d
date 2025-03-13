/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:13:13 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/13 13:20:52 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_message(t_data *data, char *str)
{
	if (data)
	{
		free_data(data);
	}
	ft_putendl_fd(B_R"Error"DEF, 2);
	ft_putendl_fd(str, 2);
	exit(FAILURE);
}
