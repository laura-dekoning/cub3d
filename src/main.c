/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:28 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/04 14:35:44 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	const char	*file;
	t_data		*data;
	t_game		*game;
	size_t		len;

	if (argc != 2)
		error_message(NULL, ARGS);
	file = argv[1];
	len = ft_strlen(file);
	if (len < 5 || (ft_strncmp(file + len - 4, ".cub", 4)))
		error_message(NULL, FILE);
	data = (t_data *)alloc_mem_for_data();
	game = (t_game *)alloc_mem_for_game();
	print_data(data);
	get_data(data, file);
	print_data(data);
	get_game(game, data); // Put this in header file as well
	cub3d(game);
	clear_everything(game);
	printf(B_G"YEEEEEEY EVERYTHING GOOD!\n"DEF);

	// 1.) get data;
	// 2.) convert data to game;
	// 3.) free data;
	// 4.) start execution with game >> cub3d(game);
	// 5.) end program with freeing game (NOT DATA >> is already freed);
	return (0);
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