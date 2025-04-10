/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string_with_index.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/10 13:26:47 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/10 13:41:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_character(int c, int i)
{
	if (c == '\t')
		printf(G"|\\t|"DEF);
	else if (i < 10)
		printf(G"|%c|"DEF, c);
	else if (i < 100)
		printf(G"|%c |"DEF, c);
	else
		printf(G"|%c  |"DEF, c);
}

void	print_string_with_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i])
		{
			print_character(str[i], i);
			i++;
		}
		printf("\n");
		i = 0;
		while (str[i])
		{
			if (str[i] == '\t' && i < 10)
				printf(B_G"|%i |"DEF, i);
			else
				printf(B_G"|%i|"DEF, i);
			i++;
		}
		printf("\n"DEF);
	}
}
