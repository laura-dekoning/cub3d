
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
# define WINDOW_WIDTH	1200
# define WINDOW_HEIGHT	1200
# define WINDOW_TITLE	"L&L Cub3d"

// these are good for gameplay
	// # define MOVING_SPEED	0.7
	// # define ROTATE_SPEED	0.03
// for te devs:
# define MOVING_SPEED	1.5
 # define ROTATE_SPEED	0.1

# define MINIMAP_WIDTH	(WINDOW_WIDTH / 3)
# define MINIMAP_HEIGHT	(WINDOW_HEIGHT / 3)
# define GRIDSIZE		32
// --------------

# define PI				3.14159265359
# define ONE_DEGREE		0.0174533

# define NUMB_RAYS		120

# define NORTH 			1
# define EAST 			2
# define SOUTH 			3
# define WEST 			4

# define DIR_NORTH 		(3 * (PI / 2))
# define DIR_EAST 		(0)
# define DIR_SOUTH 		(PI / 2)
# define DIR_WEST 		(PI)

# define PLAYER_SIZE	(GRIDSIZE / 4)

// ==== COLOURS FOR PIXELS ==== 0xRRGGBBAA
# define COLOUR_BLACK			0x000000FF
# define COLOUR_WHITE			0xFFFFFFFF
# define COLOUR_GRAY			0x808080FF
# define COLOUR_LIGHT_GRAY		0xD3D3D3FF
# define COLOUR_DARK_GRAY		0x404040FF

# define COLOUR_RED				0xFF0000FF
# define COLOUR_LIGHT_RED		0xFF6666FF
# define COLOUR_DARK_RED		0x8B0000FF

# define COLOUR_GREEN			0x00FF00FF
# define COLOUR_LIGHT_GREEN		0x66FF66FF
# define COLOUR_DARK_GREEN		0x006400FF

# define COLOUR_BLUE			0x0000FFFF
# define COLOUR_LIGHT_BLUE		0x6699FFFF
# define COLOUR_DARK_BLUE		0x00008BFF

# define COLOUR_YELLOW			0xFFFF00FF
# define COLOUR_LIGHT_YELLOW	0xFFFF99FF
# define COLOUR_DARK_YELLOW		0xCCCC00FF

# define COLOUR_ORANGE			0xFFA500FF
# define COLOUR_LIGHT_ORANGE	0xFFCC66FF
# define COLOUR_DARK_ORANGE		0xCC5500FF

# define COLOUR_PURPLE			0x800080FF
# define COLOUR_LIGHT_PURPLE	0xDDA0DDFF
# define COLOUR_DARK_PURPLE		0x4B0082FF

# define COLOUR_PINK			0xFF69B4FF
# define COLOUR_LIGHT_PINK		0xFFB6C1FF
# define COLOUR_DARK_PINK		0xC71585FF

# define COLOUR_TURQUOISE		0x40E0D0FF
# define COLOUR_LIGHT_TURQUOISE	0xAFEEEEFF
# define COLOUR_DARK_TURQUOISE	0x008B8BFF

# define COLOUR_AQUA			0x00FFFFFF
# define COLOUR_TEAL			0x008080FF

# define COLOUR_MAGENTA			0xFF00FFFF
# define COLOUR_LAVENDER		0xE6E6FAFF

# define COLOUR_GOLD			0xFFD700FF
# define COLOUR_SILVER			0xC0C0C0FF
# define COLOUR_BRONZE			0xCD7F32FF

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
	t_vector_f	start_pos;
	t_vector_f	end_pos;
	t_vector_f	direction;
	t_vector_f	step_size;

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
	mlx_image_t	*window_image;
	mlx_image_t	*minimap_image;

	t_map		*map;
	t_player	*player;

	t_ray 		ray[NUMB_RAYS];
	
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	
	int			*floor;
	int			*ceiling;

	t_vector_i	minimap_size;
} t_data;



// draw_2D.c
void	draw_2D_map(t_data *data, mlx_image_t *image);
void	draw_player(t_data *data, mlx_image_t *image);

// draw_3D.c
void	draw_3d_wall(t_data *data, t_ray *ray, int ray_i, float angle);

// draw_shapes.c
void	draw_line(mlx_image_t *image, t_vector_f start, t_vector_f end, uint64_t colour);
void	draw_filled_square(mlx_image_t *image, t_vector_f start_pos, uint32_t width, uint32_t height, uint64_t colour);
void	draw_filled_circle(mlx_image_t	*image, t_vector_f centre, int radius, int colour);
void draw_circle(mlx_image_t *image, t_vector_f centre, int radius, int colour);

// error_clear_exit.c    
void	error_and_exit(char *str);
void	clear_everything(t_data *data);
// fake_parsing.c        
void	fake_parsing(t_data *data); // TAKE OUT
// init_game.c           
void	init_window(t_data *data);
void	fill_canvas(t_data *data);
void	game(t_data *data);
// keys.c                
void	key_is_pressed(void *data);


// minimap.c
// player_collision.c
void	check_collision(t_data *data, t_vector_f step);
// rays.c
void 	raycasting(t_data *data);
// utils
float	get_min(float a, float b);
float	get_max(float a, float b);