/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string_with_values.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:54:43 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/10 13:41:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_character(int c)
{
	if (c == '\t')
		printf(P"|\\t|"DEF);
	else if (c < 10)
		printf(P"|%c|"DEF, c);
	else if (c < 100)
		printf(P"|%c |"DEF, c);
	else
		printf(P"|%c  |"DEF, c);
}

void	print_string_with_values(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		while (str[i])
		{
			print_character(str[i]);
			i++;
		}
		printf("\n");
		i = 0;
		while (str[i])
		{
			if (str[i] == '\t')
				printf(B_P"|%i |"DEF, str[i]);
			else
				printf(B_P"|%i|"DEF, str[i]);
			i++;
		}
		printf("\n"DEF);
	}
}
