/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_and_replace_space.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 14:41:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 17:09:36 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*make_temp(t_data *data)
{
	char	*temp;

	temp = (char *)safe_calloc(NULL, data, data->map->cols + 1, sizeof(char));
	if (!temp)
		error_free_data(data, MALLOC);
	return (temp);
}

void	replace_map_x(t_data *data, char *temp, int x)
{
	free(data->map->map[x]);
	data->map->map[x] = ft_substr(temp, 0, data->map->cols + 1);
	free(temp);
}

void	replace_space(char *temp, char *map)
 {
 	int	i;
 	int	y;
 
 	i = 0;
 	y = 0;
 	while (map[y] != '\0')
 	{
 		if (map[y] == ' ')
 		{
			temp[i] = '1';
			i++;
 		}
 		else
 		{
 			temp[i] = map[y];
 			i++;
 		}
 		y++;
 	}
 }

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
		temp[i] = '1';
		i++;
	}
}

void	fill_and_replace_space(t_data *data)
{
	int		x;
	char	*temp;

	x = 0;
	while (data->map->map[x] != NULL)
	{
		if (ft_strlen(data->map->map[x]) < data->map->cols)
 		{
			temp = make_temp(data);
			fill_empty(temp, data->map->map[x], data->map->cols);
			replace_map_x(data, temp, x);
		}
		if (ft_strchr(data->map->map[x], ' ') != NULL)
		{
			temp = make_temp(data);
			replace_space(temp, data->map->map[x]);
			replace_map_x(data, temp, x);
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
