/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_array_with_values.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:55:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/19 17:33:49 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_lines(char **map)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (map[0][len] != '\0' && map[0] != NULL)
		len++;
	while (i < (len * 4) + 2)
	{
		printf(B_P"-"DEF);
		i++;
	}
	printf("\n");
}

static void	print_end_nl_begin(void)
{
	printf(B_P"|"DEF);
	printf("\n");
	printf(B_P"|"DEF);
}

static void	print_values(char **map, int x)
{
	int	y;

	y = 0;
	while (map[x][y])
	{
		printf("|%i|", map[x][y]);
		y++;			
	}
}

static void	print_characters(char **map, int x)
{
	int	y;

	y = 0;
	while (map[x][y])
	{
		printf("|%c |", map[x][y]);
		y++;			
	}
}

void	print_array_with_values(char **map)
{
	int	x;

	x = 0;
	print_lines(map);
	while (map[x] != NULL)
	{
		printf(B_P"|"DEF);
		print_characters(map, x);
		print_end_nl_begin();
		print_values(map, x);
		printf(B_P"|"DEF);
		printf("\n");
		x++;
	}
	print_lines(map);
}
