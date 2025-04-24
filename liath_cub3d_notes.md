

TESTEN MORGEN VOOR DE EVAL!:

./cub3d maps/tests/crashed.cub
./cub3d maps/tests/new.cub
./cub3d maps/tests/noplayer.cub
./cub3d maps/tests/segfault.cub

./cub3d maps/good/test_pos_bottom.cub
./cub3d maps/good/test_pos_right.cub
./cub3d maps/good/test_textures.cub
./cub3d maps/good/test_pos_left.cub
./cub3d maps/good/test_pos_top.cub
./cub3d maps/good/test_whitespace.cub

./cub3d maps/bad/color_invalid_rgb.cub
./cub3d maps/bad/color_missing.cub
./cub3d maps/bad/color_missing_ceiling_rgb.cub
./cub3d maps/bad/color_missing_floor_rgb.cub
./cub3d maps/bad/color_none.cub
./cub3d maps/bad/color_split_by_letters.cub
./cub3d maps/bad/color_split_by_non_commas.cub
./cub3d maps/bad/empty.cub
./cub3d maps/bad/file_letter_end.cub
./cub3d maps/bad/filetype_missing
./cub3d maps/bad/filetype_wrong.buc
./cub3d maps/bad/forbidden.cub
./cub3d maps/bad/map_first.cub
./cub3d maps/bad/map_middle.cub
./cub3d maps/bad/map_missing.cub
./cub3d maps/bad/map_only.cub
./cub3d maps/bad/map_too_small.cub
./cub3d maps/bad/player_multiple.cub
./cub3d maps/bad/player_none.cub
./cub3d maps/bad/player_on_edge.cub
./cub3d maps/bad/textures_dir.cub
./cub3d maps/bad/textures_duplicates.cub
./cub3d maps/bad/textures_forbidden.cub
./cub3d maps/bad/textures_invalid.cub
./cub3d maps/bad/textures_missing.cub
./cub3d maps/bad/textures_none.cub
./cub3d maps/bad/textures_not_png.cub
./cub3d maps/bad/wall_hole_east.cub
./cub3d maps/bad/wall_hole_north.cub
./cub3d maps/bad/wall_hole_south.cub
./cub3d maps/bad/wall_hole_west.cub
./cub3d maps/bad/wall_none.cub
./cub3d maps/bad/correct_map.cub

./cub3d maps/checked_for_parsing/correct_map_small.cub.cub
./cub3d maps/checked_for_parsing/file_no_format
./cub3d maps/checked_for_parsing/liath_map.cub
./cub3d maps/checked_for_parsing/map_one_space_less_than_max_cols.cub
./cub3d maps/checked_for_parsing/map_open_wall.cub
./cub3d maps/checked_for_parsing/map_with_tab.cub
./cub3d maps/checked_for_parsing/rgb_3_numbers_too_big.cub
./cub3d maps/checked_for_parsing/rgb_4_numbers.cub
./cub3d maps/checked_for_parsing/rgb_negative_number.cub
./cub3d maps/checked_for_parsing/texture_path_with_space.cub
./cub3d maps/checked_for_parsing/texture_path_with_space_and_extra.cub
./cub3d maps/checked_for_parsing/texture_path_with_space_before_path.cub
./cub3d maps/checked_for_parsing/texture_path_wrong_format.cub
./cub3d maps/checked_for_parsing/texture_path_wrong_id.cub





# Cub3D


[Raycasting Docs](https://lodev.org/cgtutor/raycasting.html)

[Raycasting Video](https://www.youtube.com/watch?v=gYRrGTC7GtA)
[Raycasting Video -> Github](https://github.com/3DSage/OpenGL-Raycaster_v1/blob/master/3DSage_Raycaster_v1.c)


TODO:

[] fill and replace space heeft nog een main erin staan



[X] door hele code heen lopen en checken waar ik exit

[X] sagfaults and memleaks

[X]	change liaths code "error_and_exit(err_message)" to lauras's "error_message(t_data *data, char *str)"

TODO BONUS:
[]	add mouse-rotation
[]  add compass
[]	add framerate?


maps:

 =================================
	data->map->rows = 5;   // y
	data->map->cols = 6;   // x
	char temp_map[5][6] = {
		"111111",
		"100101",
		"101001",
		"1000N1",
		"111111"
	};
 =================================
	data->map->rows = 8;   // y
	data->map->cols = 8;   // x
	char temp_map[8][8] =
	{
		"11111111",
		"10100001",
		"10100001",
		"10110001",
		"100S0001",
		"10000101",
		"10000001",
		"11111111"
	};
 =================================
	data->map->rows = 20;   // y
	data->map->cols = 20;   // x
		char temp_map[20][20] =
	{
		"11111111111111111111",
		"10000001000000000001",
		"10000001000000000001",
		"10000001000000000001",
		"11111001111111110001",
		"10000000000000000001",
		"10000000000000000001",
		"10000000000000000001",
		"10011111111100000001",
		"10010000000000000001",
		"10010000000000000001",
		"10010000000100000001",
		"10010000000100000001",
		"100100000001000N0001",
		"10010000000100000001",
		"10010000000111111111",
		"10010000000000000001",
		"10010000000000000001",
		"10000000000000000001",
		"11111111111111111111"
	};



// uint64_t darken_colour(uint64_t colour, int shift)
// {
// 	uint64_t darker_colour;

// 	uint64_t r = (colour >> 24) & 0xFF;
// 	uint64_t g = (colour >> 16) & 0xFF;
// 	uint64_t b = (colour >> 8) & 0xFF;
// 	uint64_t a = (colour) & 0xFF;

// 	r = r >> shift;
// 	g = g >> shift;
// 	b = b >> shift;

// 	darker_colour = (r << 24) | (g << 16) | ( b << 8) | a;
// 	return (darker_colour);
// }



the arrow looks good! but back to the minimap, it looks a lot better! but because im drawing the map in a way that the player "jumps" to the new grid tile, the arrow sometimes looks like it goes into the wall or just misses it. 
can you help me figure out how to draw the rays and arrow it such a way that it "jumps" with the player? 