/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:29:30 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/06 20:21:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_file(const char *file)
{
	int		fd;
	char	*line;
	char	*file_str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_message("File not found");
	file_str = safe_calloc(1, 1);
	if (!file_str)
		error_message(MALLOC);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			map_as_str = ft_gnl_strjoin(map_as_str, line);
			free(line);
		}
		else
			break ;
	}
	close(fd);
	return (file_str);
}
