/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_adjacent.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:54:07 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 17:54:55 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	r = -1;
void	print_adjacent(char **map, int row, int col)
{
	int	r;
	int	c;

	r = -1;
	while (r <= 1)
	{
		c = -1;
		while (c <= 1)
		{
			printf("%c ", map[row + r][col + c]);
			c++;
		}
		printf("\n");
		r++;
	}
}
