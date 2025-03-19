/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 16:53:38 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/19 16:53:50 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_data(t_data *data)
{
	printf(B_O"Data:\n"DEF);
	printf(G"North texture:"DEF" [%s]\n", data->north_texture);
	printf(Y"East texture:"DEF" [%s]\n", data->east_texture);
	printf(O"South texture:"DEF" [%s]\n", data->south_texture);
	printf(R"West texture:"DEF" [%s]\n", data->west_texture);
	print_floor_and_ceiling(data->floor, data->ceiling);
	print_map(data->map);
	print_player(data->player);
	print_check(data->check);
}
