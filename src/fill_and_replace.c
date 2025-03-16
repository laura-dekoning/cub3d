/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_and_replace.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/16 14:41:18 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/16 16:50:43 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*fill_empty(char *temp, char *map, int len)
{
	int	i;
	int	y;
	int	end;

	i = 0;
	y = 0;
	end = 0;
	while (end < len)
	{
		while (map[y] != '\0')
		{
			temp[i] = map[y];
			i++;
			y++;
			end++;

		}
		temp[i] = ' ';
		i++;
		end++;
	}
	return (temp);
}

char	*replace_tab(char *temp, char *map)
{
	int	i;
	int	y;
	int	spaces;

	i = 0;
	y = 0;
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

void	fill_and_replace(t_data *data)
{
	int		x;
	char	*temp;

	temp = safe_calloc(data, data->map->cols + 1, sizeof(char));
	x = 0;
	while (data->map->map[x] != NULL)
	{
		if (ft_strlen(data->map->map[x]) < data->map->cols)
		{
			temp = replace_tab(temp, data->map->map[x]);
			temp = fill_empty(temp, data->map->map[x], data->map->cols);
			free(data->map->map[x]);
			data->map->map[x] = temp;
		}
		free(temp);
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
