# Cub3D


[Raycasting Docs](https://lodev.org/cgtutor/raycasting.html)

[Raycasting Video](https://www.youtube.com/watch?v=gYRrGTC7GtA)
[Raycasting Video -> Github](https://github.com/3DSage/OpenGL-Raycaster_v1/blob/master/3DSage_Raycaster_v1.c)



TODO:
[]	add framerate

TODO BONUS:
[]	add mouse-rotation
[]  add compass


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