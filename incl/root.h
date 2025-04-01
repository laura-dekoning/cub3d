/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   root.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 16:44:06 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/01 16:48:15 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROOT_H
# define ROOT_H

# include "cub3d.h"

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
	t_vector_i			step_dir;
	t_vector_f			step_size;
	t_vector_f			collision_point;
	t_vector_f			end_pos;
	float				distance;
	bool				wall_hit;
	t_wall_segment_3d	wall_3d;
}	t_ray;

typedef struct s_player
{
	t_vector_f	pos;
	t_vector_f	dir;
	float		angle;
	bool		wall_hit;
	uint16_t	size; //waarom een uint16_t?
}	t_player;

typedef struct s_mm_border
{
	t_vector_i	top_line_start;
	t_vector_i	top_line_end;
	t_vector_i	bottom_line_start;
	t_vector_i	bottom_line_end;
	t_vector_i	left_line_start;
	t_vector_i	left_line_end;
	t_vector_i	right_line_start;
	t_vector_i	right_line_end;
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
	char			*path_to_north_texture;
	char			*path_to_south_texture;
	char			*path_to_west_texture;
	char			*path_to_east_texture;

	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
}	t_textures;

typedef struct s_festival_textures
{
	char			*path_to_drink_shop;
	char			*path_to_food_shop;
	char			*path_to_merch_shop;
	char			*path_to_dixies;
	char			*path_to_wall;
	char			*path_to_stage;

	mlx_texture_t	*drink_shop_texture;
	mlx_texture_t	*food_shop_texture;
	mlx_texture_t	*merch_shop_texture;
	mlx_texture_t	*dixies_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*stage_texture;
}	t_festival_textures;


//Misschien kunnen we 2 structs maken? De data struct die ik meegeef. En dan daarna de game struct waar uiteindelijk de game mee wordt uitgevoerd?
typedef struct s_root
{
	mlx_t				*window;

	mlx_image_t			*window_image;
	mlx_image_t			*minimap_image;
	mlx_image_t			*minimap_border_image;

	t_map				*map;
	bool				festival_map;

	t_player			player;
	t_ray				ray[NUMB_RAYS];

	t_minimap			minimap;

	t_textures			textures;
	t_festival_textures	festival_textures;

	uint64_t			floor_colour;
	uint64_t			ceiling_colour;
	// uint64_t			walls_colour;
}	t_root;

#endif