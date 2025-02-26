/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:28 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/02/26 14:58:40 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	const char	*file;
	size_t		len;


	if (argc != 2)
		error_message(ARGS);
	file = argv[1];
	len = ft_strlen(file);
	if (len < 5 || (ft_strncmp(file + len - 4, ".cub", 4)))
		error_message(FILE);
}
