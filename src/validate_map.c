/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 19:41:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/16 16:37:24 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	surrounded_by_walls(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (data->map->map[x] != NULL)
// 	{
// 		y = 0;
// 		while (data->map->map[x][y] != '\0')
// 		{
// 			if (data->map->map[0][y] != '1' || )
// 			y++;
// 		}
// 		x++;
// 	}
// }

// char	*fill_empty(char *temp, char *map)
// {

// }

char	*replace_tab(char *temp, char *map)
{
	int	y;
	int	i;
	int	spaces;

	y = 0;
	i = 0;
	spaces = 4;
	while (map[y] != '\0')
	{
		if (map[y] == '\t')
		{
			while (spaces-- != 0)
			{
				temp[i] = ' ';
				i++;
			}
			y++;
		}
		temp[i] = map[y];
		i++;
		y++;
	}
	return (temp);
}

// void	fill_and_replace(t_data *data)
// {
// 	int		x;
// 	char	*temp;

// 	temp = safe_calloc(data, data->map->cols + 1, sizeof(char));
// 	x = 0;
// 	while (data->map->map[x] != NULL)
// 	{
// 		if (ft_strlen(data->map->map[x]) < data->map->cols)
// 		{
// 			temp = replace_tab(temp, data->map->map[x]);
// 			temp = fill_empty(temp, data->map->map[x]);
// 			free(data->map->map[x]);
// 			data->map->map[x] = temp;
// 		}
// 		free(temp);
// 		x++;
// 	}
// }

// void	validate_map(t_data *data)
// {
// 	fill_and_replace(data);
// 	surrounded_by_walls(data);
// 	make_square(data);
// }

int	main()
{
	char	*map = "11	123 ";
	char	*temp;
	int		i;

	temp = ft_calloc(10, sizeof(char));
	temp = replace_tab(temp, map);
	i = 0;
	while (temp[i] != '\0')
	{
		printf("|%c |", temp[i]);
		i++;
	}
		printf("\n");
	i = 0;
	while (temp[i] != '\0')
	{
		printf("|%i|", temp[i]);
		i++;
	}
	return (0);
}
