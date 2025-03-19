/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string_with_values.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:54:43 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/19 16:54:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_string_with_values(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i])
		{
			printf(B_G"|%c |", str[i]);
			i++;			
		}
		printf("\n");
		i = 0;
		while (str[i])
		{
			printf("|%i|", str[i]);
			i++;			
		}
		printf("\n"DEF);
	}
}
