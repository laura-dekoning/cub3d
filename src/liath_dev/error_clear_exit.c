/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_clear_exit.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:42:03 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/07 14:49:24 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

void	error_and_exit(char *str)
{
	ft_putendl_fd(B_R"Error: "DEF, 2);
	ft_putendl_fd(str, 2);
	exit(FAILURE);
}

void	clear_everything(t_data *data)
{
	free(data);
}
