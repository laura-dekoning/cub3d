/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:27:05 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/10 18:48:13 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_images(t_data *data)
{
	if (!data->north_texture || !data->south_texture || !data->west_texture || !data->east_texture)
		error_free_data(data, TEXTURE);
	if (ft_strncmp(data->north_texture + ft_strlen(data->north_texture) - 4,
			".png", 4))
		error_free_data(data, TEXTURE);
	return ;
}

void	check_rgb(t_data *data)
{
	int	i;

	i = 0;
	if (!data->floor || !data->ceiling)
		error_free_data(data, "RGB missing");
	while (i < 3)
	{
		if (data->floor[i] > 255 || data->ceiling[i] > 255)
			error_free_data(data, BIG);
		i++;
	}
}

void	validate_data(t_data *data)
{
	check_rgb(data);
	check_images(data);
}
