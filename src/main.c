/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:28 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/11 21:24:11 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	const char	*file;
	t_data		*data;
	size_t		len;

	if (argc != 2)
		error_message(ARGS);
	file = argv[1];
	len = ft_strlen(file);
	if (len < 5 || (ft_strncmp(file + len - 4, ".cub", 4)))
		error_message(FILE);
	data = (t_data *)safe_calloc(1, sizeof(t_data));
	set_default(data);
	get_data(data, file);

}

//gebruik gnl met strjoin om de hele file uit te lezen in 1 string.
//vervolgens loop door de string en set scene (NO, SO, WE, EA, S, F, C)
//daarna als het een ' ' of '1' is dan begint de map
//substr vanaf daar tot het einde van de file naar str *map
//check of de map valid is -> loop door de string en check of er alleen 0, 1, ' ', N, S, W, E in zitten
//check of de map gesloten is -> loop door de map en check of de buitenste randen bestaan uit 1's
//check of de map maar 1 speler bevat -> loop door de map en check of *player_pos is already true
//yd{1, 0, -1, 0} xd{0, 1, 0, -1} -> loop door de map en check of de 0 niet omgeven is door een ' '
//check max map_len 
//fill char **map met de map
//maak map rectangle door lege plekken eind string op te vullen met ' '