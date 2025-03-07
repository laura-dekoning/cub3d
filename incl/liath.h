
#ifndef LIATH_H
# define LIATH_H

# define WINDOW_WIDTH	1750
# define WINDOW_HEIGHT	1750
# define WINDOW_TITLE	"L&L Cub3d"

# define SUCCESS 0
# define FAILURE 1

# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/incl/libft.h"
# include <math.h>

#endif

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
} t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	dir;
} t_player;

typedef struct s_data
{
	mlx_t		*window;
	mlx_image_t	*image;

	t_map		*map;
	t_player	*player;

	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;

	int			*floor;
	int			*ceiling;
} t_data;


void	error_and_exit(char *str);
void	clear_everything(t_data *data);
void	init_window(t_data *data);
void	fill_canvas(t_data *data);
void	key_is_pressed(void *data);
void	game(t_data *data);

