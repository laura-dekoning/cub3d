
#ifndef LIATH_H
# define LIATH_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/incl/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define SUCCESS 		0
# define FAILURE 		1

// adjusable:
# define WINDOW_WIDTH	1000
# define WINDOW_HEIGHT	1000
# define WINDOW_TITLE	"L&L Cub3d"

# define MOVING_SPEED	2
# define ROTATE_SPEED	1

# define GRIDSIZE		(64 / 2)
// --------------


# define PI				3.14159265359
# define ONE_DEGREE		0.0174533

# define NUMB_RAYS		120

# define NORTH 			1
# define EAST 			2
# define SOUTH 			3
# define WEST 			4

# define DIR_NORTH 		(3 * PI / 2)
# define DIR_EAST 		(0)
# define DIR_SOUTH 		(PI / 2)
# define DIR_WEST 		(PI)

# define PLAYER_SIZE	(GRIDSIZE / 8)		// this is the radius of the circle
# define NOSE_LENGTH 	(PLAYER_SIZE * 3)

# define COLOUR_M_PINK	0xCC99FFFF  // R=CC, G=99, B=FF, A=FF
# define COLOUR_YELLOW	0xFFFF66FF  // R=FF, G=FF, B=66, A=FF
# define COLOUR_ORANGE	0xFF9933FF  // R=FF, G=99, B=33, A=FF
# define COLOUR_MAGENTA	0x660033FF  // R=66, G=00, B=33, A=FF
# define COLOUR_RED		0xFF0000FF  // R=FF, G=00, B=00, A=FF
# define COLOUR_GREEN	0x00CC00FF  // R=00, G=CC, B=00, A=FF
# define COLOUR_CYAN	0x00FFFFFF  // R=00, G=FF, B=FF, A=FF
# define COLOUR_PURPLE	0x6600FFFF  // R=66, G=00, B=FF, A=FF
# define COLOUR_BLUE	0x0099CCFF  // R=00, G=99, B=CC, A=FF
# define COLOUR_GRAY	0x333333FF  // R=33, G=33, B=33, A=FF
# define COLOUR_BLACK	0x000000FF  // R=00, G=00, B=00, A=FF
# define COLOUR_WHITE	0xFFFFFFFF  // R=FF, G=FF, B=FF, A=FF

#endif

typedef struct s_map
{
	char	**map;
	int		rows;	// y
	int		cols;	// x
} t_map;

typedef struct s_vector_f
{
	float x;
	float y;
} t_vector_f;

typedef struct s_vector_i
{
	int x;
	int y;
} t_vector_i;

typedef struct s_ray 
{
	t_vector_f	ray_start;
	t_vector_f	ray_end;
	t_vector_f	ray_dir;
	t_vector_f	ray_unit_step_size;

	t_vector_i	map_pos;

	t_vector_f	collision_point;
	t_vector_i	step;

	bool		wall_hit;
	float 		distance;
} t_ray ;


typedef struct s_player
{
	t_vector_f	pos;
	t_vector_f	dir;
	float		angle;
	bool		wall_hit;
} t_player;

typedef struct s_data
{
	mlx_t		*window;
	mlx_image_t	*image;

	t_map		*map;
	t_player	*player;
	t_vector_i	minimap_size;


	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;

	int			*floor;
	int			*ceiling;
} t_data;


void	fake_parsing(t_data *data); // TAKE OUT

void	error_and_exit(char *str);
void	clear_everything(t_data *data);
void	init_window(t_data *data);
void	fill_canvas(t_data *data);
void	key_is_pressed(void *data);
void	game(t_data *data);
void 	raycasting(t_data *data);
void	draw_line(t_data *data, t_vector_f start, t_vector_f end, uint64_t colour);
float	get_max(float a, float b);
float	get_min(float a, float b);

