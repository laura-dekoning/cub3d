/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:58:39 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/19 16:58:45 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_check(t_check *check)
{
	int	i;

	i = 0;
	printf(B_Y"Settings:\n"DEF);
	while (i < 7)
	{
		if (check->setting[i] == true)
			printf("Setting[%i] == true\n", i);
		else if (check->setting[i] == false)
			printf("Setting[%i] == false\n", i);
		i++;
	}
}
