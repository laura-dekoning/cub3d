/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 16:44:06 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 17:20:36 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_data t_data;

typedef struct s_vector_f
{
	float	x;
	float	y;
}	t_vector_f;

typedef struct s_vector_s
{
	size_t	x;
	size_t	y;
}	t_vector_s;

typedef struct s_map_ex
{
	char	**map;
	size_t	rows; //rows = if (ft_strlen(map[x][y] > rows) rows = y;
	size_t	cols;
	size_t	map_width_px;
	size_t	map_height_px;
}				t_map_ex;

typedef struct s_wall_segment_3d
{
	bool			n_s_wall;
	int				wall_side;

	float			wall_distance;
	float			corrected_distance;

	float			wall_height;
	int				wall_top;
	int				wall_bottom;
	int				wall_shadow;

	uint8_t			line_width; //waarom hier uint8_t?
	mlx_texture_t	*texture;
	float			wall_hit_screen_x;
	int				texture_x;
	int				texture_y;
	float			texture_y_step;
	float			texture_y_pos;

}	t_wall_segment_3d;

typedef struct s_ray
{
	t_vector_f			start_pos;
	float				angle;
	t_vector_f			direction;
	t_vector_s			step_dir;
	t_vector_f			step_size;
	t_vector_f			collision_point;
	t_vector_f			end_pos;
	float				distance;
	bool				wall_hit;
	t_wall_segment_3d	wall_3d;
}	t_ray;

// HIER MOET NOG IETS MEE GEBEUREN DENK IK
typedef struct s_player_ex
{
	t_vector_f	pos;
	t_vector_f	dir;
	float		angle;
	bool		wall_hit;
	uint16_t	size; //waarom een uint16_t?
}	t_player_ex;

typedef struct s_mm_border
{
	t_vector_s	top_line_start;
	t_vector_s	top_line_end;
	t_vector_s	bottom_line_start;
	t_vector_s	bottom_line_end;
	t_vector_s	left_line_start;
	t_vector_s	left_line_end;
	t_vector_s	right_line_start;
	t_vector_s	right_line_end;
	uint64_t	colour;
}	t_mm_border;

typedef struct s_minimap
{
	uint64_t	back_ground_colour;
	uint64_t	wall_colour;
	uint64_t	floor_colour;
	uint64_t	border_colour;

	uint64_t	player_colour;
	uint64_t	ray_colour;
	uint64_t	arrow_colour;

	uint8_t		border_size;
	uint16_t	minimap_size;
	uint16_t	grid_size;
	uint16_t	player_size;

	t_vector_f	player_pos;
	t_mm_border	border;
}	t_minimap;

typedef struct s_textures
{
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
}	t_textures;

typedef struct s_game
{
	mlx_t				*window;

	mlx_image_t			*window_image;
	mlx_image_t			*minimap_image;
	mlx_image_t			*minimap_border_image;

	t_map_ex			*map;
	bool				festival_map;

	t_player_ex			*player;
	t_ray				ray[NUMB_RAYS];

	t_minimap			minimap;

	t_textures			textures;

	uint64_t			floor_colour;
	uint64_t			ceiling_colour;
}	t_game;

// draw_minimap_player.c
void	draw_player(t_game *game);

// draw_minimap.c
void	draw_border(t_game *game, t_mm_border border);
void	draw_2D_map(t_game *game);

// draw_shapes.c
void	draw_filled_rectangle(mlx_image_t *image, t_vector_s start_pos, t_vector_s end_pos, uint64_t colour);
void	draw_filled_circle(mlx_image_t		*image, t_vector_f centre, int radius, int colour);
void	draw_circle(mlx_image_t *image, t_vector_f centre, int radius, int colour);
void	draw_line(mlx_image_t *image, t_vector_f start, t_vector_f end, uint64_t colour);
void	draw_ceiling_and_floor(t_game *game);

// game.c
void	start_game(t_game *game);
void	cub3d(t_game *game);

// init_window_and_images.c
void	init_window(t_game *game);
void	init_minimap_image(t_game *game);
void	init_wall_textures(t_game *game, t_data *data);

// init_walls.c
void	init_wall_segment(t_game *game, t_ray *ray);

// keys.c
void	is_key_pressed(void *data);
void	normalize_diagonal_movement(float *step_x, float *step_y);

// minimap.c
void	minimap(t_game *game);

// utils.c
// int satoui(const char c);
void	check_angle(float *angle);





/* RAYCASTING AND RENDERING */
// collision_points.c
void	check_collision(t_game *game, t_vector_f step);
void	get_collision_point_negative_x(t_ray *ray, float map_pos_x);
void	get_collision_point_positive_x(t_ray *ray, float map_pos_x);
void	get_collision_point_negative_y(t_ray *ray, float map_pos_y);
void	get_collision_point_positive_y(t_ray *ray, float map_pos_y);

// raycasting.c
void	raycasting(t_game *game);

// render_3d_scene.c
void	render_3d_wall_segment(t_game *game, t_ray *ray, int ray_i);

// rendering_utils.c
void	fix_texture_stretch(t_game *game, t_ray * ray);
void	fix_texture_zoom_to_centre(t_game *game, t_ray * ray);


#endif
