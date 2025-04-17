

# Cub3D


[Raycasting Docs](https://lodev.org/cgtutor/raycasting.html)

[Raycasting Video](https://www.youtube.com/watch?v=gYRrGTC7GtA)
[Raycasting Video -> Github](https://github.com/3DSage/OpenGL-Raycaster_v1/blob/master/3DSage_Raycaster_v1.c)


TODO:

door hele code heen lopen en checken waar ik exit

valgrind zegt dit 17-04-25 16:30:
==73441== 
==73441== HEAP SUMMARY:
==73441==     in use at exit: 317,955 bytes in 3,107 blocks
==73441==   total heap usage: 83,112 allocs, 80,005 frees, 245,472,586 bytes allocated
==73441== 
==73441== LEAK SUMMARY:
==73441==    definitely lost: 0 bytes in 1 blocks
==73441==    indirectly lost: 0 bytes in 0 blocks
==73441==      possibly lost: 0 bytes in 0 blocks
==73441==    still reachable: 317,955 bytes in 3,106 blocks
==73441==         suppressed: 0 bytes in 0 blocks
==73441== Rerun with --leak-check=full to see details of leaked memory
==73441== 
==73441== For lists of detected and suppressed errors, rerun with: -s
==73441== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)



[X] sagfaults and memleaks:

[] ./cub3d maps/liath_map.cub

==33051==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 24 byte(s) in 1 object(s) allocated from:
	#0 0x49a3cd in malloc (/sgoinfre/livliege/cub3d/cub3d+0x49a3cd)
	#1 0x505ca0 in ft_calloc (/sgoinfre/livliege/cub3d/cub3d+0x505ca0)
	#2 0x4cd1a9 in safe_calloc /home/livliege/sgoinfre/cub3d/src/memory/safe_calloc.c

SUMMARY: AddressSanitizer: 24 byte(s) leaked in 1 allocation(s).


[] ./cub3d maps/correct_map_small.cub

==33238==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 24 byte(s) in 1 object(s) allocated from:
	#0 0x49a3cd in malloc (/sgoinfre/livliege/cub3d/cub3d+0x49a3cd)
	#1 0x505ca0 in ft_calloc (/sgoinfre/livliege/cub3d/cub3d+0x505ca0)
	#2 0x4cd1a9 in safe_calloc /home/livliege/sgoinfre/cub3d/src/memory/safe_calloc.c

SUMMARY: AddressSanitizer: 24 byte(s) leaked in 1 allocation(s).



[] ./cub3d maps/texture_path_with_space_before_path.cub
==34681==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 24 byte(s) in 1 object(s) allocated from:
    #0 0x49a3cd in malloc (/sgoinfre/livliege/cub3d/cub3d+0x49a3cd)
    #1 0x505ca0 in ft_calloc (/sgoinfre/livliege/cub3d/cub3d+0x505ca0)
    #2 0x4cd1a9 in safe_calloc /home/livliege/sgoinfre/cub3d/src/memory/safe_calloc.c

SUMMARY: AddressSanitizer: 24 byte(s) leaked in 1 allocation(s).




[] ./cub3d maps/map_one_space_less_than_max_cols.cub 

==34377==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 24 byte(s) in 1 object(s) allocated from:
	#0 0x49a3cd in malloc (/sgoinfre/livliege/cub3d/cub3d+0x49a3cd)
	#1 0x505ca0 in ft_calloc (/sgoinfre/livliege/cub3d/cub3d+0x505ca0)
	#2 0x4cd1a9 in safe_calloc /home/livliege/sgoinfre/cub3d/src/memory/safe_calloc.c



[] ./cub3d maps/correct_map.cub

==33080==ERROR: AddressSanitizer: SEGV on unknown address (pc 0x0000004202b4 bp 0x000000000000 sp 0x7ffe38cfdea0 T0)
==33080==The signal is caused by a READ memory access.
==33080==Hint: this fault was caused by a dereference of a high value address (see register values below).  Disassemble the provided pc to learn which register was used.
	#0 0x4202b4 in __asan::Allocator::Deallocate(void*, unsigned long, unsigned long, __sanitizer::BufferedStackTrace*, __asan::AllocType) (/sgoinfre/livliege/cub3d/cub3d+0x4202b4)
	#1 0x49a1c5 in free (/sgoinfre/livliege/cub3d/cub3d+0x49a1c5)
	#2 0x505ddb in ft_free_arr (/sgoinfre/livliege/cub3d/cub3d+0x505ddb)
	#3 0x4cd140 in free_game /home/livliege/sgoinfre/cub3d/src/memory/free_game.c:21:4
	#4 0x4cb4cd in main /home/livliege/sgoinfre/cub3d/src/main.c:35:2
	#5 0x7f0e310aad8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
	#6 0x7f0e310aae3f in __libc_start_main csu/../csu/libc-start.c:392:3
	#7 0x41f504 in _start (/sgoinfre/livliege/cub3d/cub3d+0x41f504)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV (/sgoinfre/livliege/cub3d/cub3d+0x4202b4) in __asan::Allocator::Deallocate(void*, unsigned long, unsigned long, __sanitizer::BufferedStackTrace*, __asan::AllocType)
==34629==ABORTING


[] ./cub3d maps/texture_path_with_space.cub 

==34544==ERROR: AddressSanitizer: SEGV on unknown address (pc 0x0000004202b4 bp 0x000000000000 sp 0x7ffc569974c0 T0)
==34544==The signal is caused by a READ memory access.
==34544==Hint: this fault was caused by a dereference of a high value address (see register values below).  Disassemble the provided pc to learn which register was used.
    #0 0x4202b4 in __asan::Allocator::Deallocate(void*, unsigned long, unsigned long, __sanitizer::BufferedStackTrace*, __asan::AllocType) (/sgoinfre/livliege/cub3d/cub3d+0x4202b4)
    #1 0x49a1c5 in free (/sgoinfre/livliege/cub3d/cub3d+0x49a1c5)
    #2 0x505ddb in ft_free_arr (/sgoinfre/livliege/cub3d/cub3d+0x505ddb)
    #3 0x4cd140 in free_game /home/livliege/sgoinfre/cub3d/src/memory/free_game.c:21:4
    #4 0x4cb4cd in main /home/livliege/sgoinfre/cub3d/src/main.c:35:2
    #5 0x7f6b6bb01d8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #6 0x7f6b6bb01e3f in __libc_start_main csu/../csu/libc-start.c:392:3
    #7 0x41f504 in _start (/sgoinfre/livliege/cub3d/cub3d+0x41f504)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV (/sgoinfre/livliege/cub3d/cub3d+0x4202b4) in __asan::Allocator::Deallocate(void*, unsigned long, unsigned long, __sanitizer::BufferedStackTrace*, __asan::AllocType)
==34544==ABORTING



[] ./cub3d maps/texture_path_with_space_and_extra.cub 
==34629==ERROR: AddressSanitizer: SEGV on unknown address 0x001b000010f2 (pc 0x0000004202b4 bp 0x000000000000 sp 0x7ffdb87cc7b0 T0)
==34629==The signal is caused by a WRITE memory access.
    #0 0x4202b4 in __asan::Allocator::Deallocate(void*, unsigned long, unsigned long, __sanitizer::BufferedStackTrace*, __asan::AllocType) (/sgoinfre/livliege/cub3d/cub3d+0x4202b4)
    #1 0x49a1c5 in free (/sgoinfre/livliege/cub3d/cub3d+0x49a1c5)
    #2 0x505ddb in ft_free_arr (/sgoinfre/livliege/cub3d/cub3d+0x505ddb)
    #3 0x4cd140 in free_game /home/livliege/sgoinfre/cub3d/src/memory/free_game.c:21:4
    #4 0x4cb4cd in main /home/livliege/sgoinfre/cub3d/src/main.c:35:2
    #5 0x7fc1531a4d8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #6 0x7fc1531a4e3f in __libc_start_main csu/../csu/libc-start.c:392:3
    #7 0x41f504 in _start (/sgoinfre/livliege/cub3d/cub3d+0x41f504)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV (/sgoinfre/livliege/cub3d/cub3d+0x4202b4) in __asan::Allocator::Deallocate(void*, unsigned long, unsigned long, __sanitizer::BufferedStackTrace*, __asan::AllocType)
==34629==ABORTING




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