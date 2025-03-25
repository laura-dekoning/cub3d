/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   liath.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 16:40:29 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/25 16:34:30 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIATH_H
# define LIATH_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/incl/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define SUCCESS 		0
# define FAILURE 		1

# define WINDOW_WIDTH	1800
# define WINDOW_HEIGHT	1800
# define WINDOW_TITLE	"L&L Cub3d"

# define PI				3.14159265359
# define ONE_D_RADIAN	0.0174533		// 1 degree = 0.0174533 radians

# define FOV			60.0
# define NUMB_RAYS		(WINDOW_WIDTH / 2)

# define RENDER_DIST	1000
# define SHADOW_ALPHA	100		// 0 is complete seetrough aka completely gray (max 255)
# define FOG_FACTOR		4		// smaller numebr is "thicker fog" effect

# define NORTH 			1
# define EAST 			2
# define SOUTH 			3
# define WEST 			4

# define DIR_NORTH 		(3 * (PI / 2))
# define DIR_EAST 		0
# define DIR_SOUTH 		(PI / 2)
# define DIR_WEST 		PI

# define MOVING_SPEED	4
# define ROTATING_SPEED	0.03

# define GRIDSIZE		64

// # define PLAYER_SIZE	(GRIDSIZE_MM / 4)
# define MINIMAP_SCALE	3 		// 1 is fullsize, 5 is good
# define MINIMAP_GRID	13 		// n X n grid


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

typedef struct s_map
{
	char	**map;
	int		rows;	// y
	int		cols;	// x
	int		map_width_px;
	int		map_height_px;
}	t_map;

typedef struct s_vector_f
{
	float	x;
	float	y;
}	t_vector_f;

typedef struct s_vector_i
{
	int		x;
	int		y;
}	t_vector_i;

typedef struct s_wall_sagment_3d
{
	bool			N_S_wall;
	int				wall_side;
	
	float			wall_distance;
	float			corrected_distance;
	
	float			wall_height;
	int				wall_top;
	int				wall_bottom;
	int				wall_shadow;

	uint8_t			line_width;
	mlx_texture_t	*texture;
	float			wall_hit_screen_x;
	int				texture_x;
	int				texture_y;
	float			texture_y_step; 
	float			texture_y_pos;

}	t_wall_sagment_3d;

typedef struct s_ray
{
	t_vector_f			start_pos;
	float				angle;
	t_vector_f			direction;
	t_vector_i			step_dir;
	t_vector_f			step_size;
	t_vector_f			collision_point;
	t_vector_f			end_pos;
	float				distance;
	bool				wall_hit;
	t_wall_sagment_3d	wall_3d;
}	t_ray;

typedef struct s_player
{
	t_vector_f	pos;
	t_vector_f	dir;
	float		angle;
	bool		wall_hit;
	uint16_t	size;
	
}	t_player;

typedef struct s_minimap
{
	uint64_t	back_ground_colour;
	uint64_t	wall_colour;
	uint64_t	floor_colour;
	uint64_t	player_colour;
	uint64_t	ray_colour;
	uint64_t	border_colour;
	uint8_t		border_size;
	uint16_t	minimap_size;
	uint16_t	grid_size;
	uint16_t	player_size;
	t_vector_f	player_pos;

}	t_minimap;

typedef struct s_textures
{
	char			*path_to_north_texture;
	char			*path_to_south_texture;
	char			*path_to_west_texture;
	char			*path_to_east_texture;

	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;

}	t_textures;

typedef struct s_data
{
	mlx_t		*window;
	mlx_image_t	*window_image;
	mlx_image_t	*minimap_image;

	t_map		*map;

	t_player	player;
	t_ray		ray[NUMB_RAYS];

	t_minimap	minimap;

	t_textures	textures;

	uint64_t	floor_colour;
	uint64_t	ceiling_colour;
	uint64_t	walls_colour;
}	t_data;

// draw_minimap_player.c
void	draw_player(t_data *data);

// draw_minimap.c
void	draw_2D_map(t_data *data);

// draw_shapes.c
void		draw_filled_rectangle(mlx_image_t *image, t_vector_i start_pos, t_vector_i end_pos, uint64_t colour);
void		draw_filled_circle(mlx_image_t		*image, t_vector_f centre, int radius, int colour);
void		draw_circle(mlx_image_t *image, t_vector_f centre, int radius, int colour);
void		draw_line(mlx_image_t *image, t_vector_f start, t_vector_f end, uint64_t colour);
void		draw_ceiling_and_floor(t_data *data);

// error_clear_exit.c    
void		error_and_exit(char *str);
void		clear_everything(t_data *data);

// fake_parsing.c        
void		fake_parsing(t_data *data); // TAKE OUT

// init_game.c           
void		game(t_data *data);
void		cub3d(t_data *data);

// init_walls.c
void init_wall_sagment(t_data *data, t_ray *ray);

// keys.c                
void		is_key_pressed(void *data);

// minimap.c
void		minimap(t_data *data);

// player_collision.c
void		check_collision(t_data *data, t_vector_f step);

// raycasting.c
void 		raycasting(t_data *data);

// render_3d_scene.c
void render_3d_wall_sagment(t_data *data, t_ray *ray, int ray_i);

#endif