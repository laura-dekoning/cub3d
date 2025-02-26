/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:27:05 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/02/26 16:38:52 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_textures(t_data *data)
{
	if (!data->north_texture || !data->south_texture || !data->west_texture || !data->east_texture)
		return (FAILURE);
	if (ft_strncmp(data->north_texture + ft_strlen(data->north_texture) - 4, ".xpm", 4))
		error_message(TEXTURE);

	return (SUCCESS);
}

int	check_rgb(t_data *data)
{

}
