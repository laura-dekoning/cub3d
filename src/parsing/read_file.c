/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:29:30 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/23 20:33:08 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_file(t_data *data, const char *file)
{
	int		fd;
	char	*line;
	char	*file_str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_free_data(data, "File not found");
	file_str = (char *)safe_calloc(NULL, data, 1, 1);
	if (!file_str)
		error_free_data(data, MALLOC);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			file_str = ft_gnl_strjoin(file_str, line);
			free(line);
		}
		else
			break ;
	}
	close(fd);
	return (file_str);
}
