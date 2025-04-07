/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_array_with_index.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:55:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 17:51:39 by lade-kon      ########   odam.nl         */
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

static void	print_index(char **map, int x)
{
	static int	i = 0;
	int			y;

	y = 0;
	printf(B"|%2d|"DEF, i);
	while (map[x][y])
	{
		printf(G"|%2d|"DEF, y);
		y++;
	}
	i++;
}

static void	print_characters(char **map, int x)
{
	int			y;
	static int	i = 0;

	y = 0;
	printf(B"|%2d|"DEF, i);
	while (map[x][y])
	{
		printf("|%2c|", map[x][y]);
		y++;
	}
	i++;
}

void	print_array_with_index(char **map)
{
	int	x;

	x = 0;
	print_lines(map);
	while (map[x] != NULL)
	{
		printf(B_P"|"DEF);
		print_index(map, x);
		print_end_nl_begin();
		print_characters(map, x);
		printf(B_P"|"DEF);
		printf("\n");
		x++;
	}
	print_lines(map);
}
