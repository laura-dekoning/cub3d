/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_and_replace.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 14:41:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/27 07:55:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_empty(char *temp, char *map, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (i < len)
	{
		while (map[y] != '\0')
		{
			temp[i] = map[y];
			i++;
			y++;

		}
		temp[i] = ' ';
		i++;
	}
}

void	fill_map(t_data *data)
{
	int		x;
	char	*temp;

	x = 0;
	while (data->map->map[x] != NULL)
	{
		if (ft_strlen(data->map->map[x]) < data->map->cols)
		{
			temp = safe_calloc(data, data->map->cols + 1, sizeof(char));
			fill_empty(temp, data->map->map[x], data->map->cols);
			free(data->map->map[x]);
			data->map->map[x] = ft_substr(temp, 0, data->map->cols + 1);
			// print_string_with_values(data->map->map[x]);
			free(temp);
		}
		x++;
	}
}

// int	main()
// {
// 	char	*map = "11123";
// 	char	*temp;
// 	int		i;

// 	temp = ft_calloc(10, sizeof(char));
// 	temp = fill_empty(temp, map, 9);
// 	i = 0;
// 	while (temp[i] != '\0')
// 	{
// 		printf("|%c |", temp[i]);
// 		i++;
// 	}
// 		printf("\n");
// 	i = 0;
// 	while (temp[i] != '\0')
// 	{
// 		printf("|%i|", temp[i]);
// 		i++;
// 	}
// 	return (0);
// }
