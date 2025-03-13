/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:29:30 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/13 14:18:38 by lade-kon      ########   odam.nl         */
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
		error_message(data, "File not found");
	file_str = safe_calloc(data, 1, 1);
	if (!file_str)
		error_message(data, MALLOC);
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

// int	main(int argc, char **argv)
// {
// 	char *file;


// 	file = read_file(argv[1]);
// 	printf(B_R"FILE CONTENT:"DEF"\n%s\n", file);
// 	return (0);	
// }
