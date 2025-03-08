
#ifndef LIATH_H
# define LIATH_H

# define WINDOW_WIDTH	1750
# define WINDOW_HEIGHT	1750
# define WINDOW_TITLE	"L&L Cub3d"

# define MOVING_SPEED	5

# define SUCCESS 0
# define FAILURE 1

# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

# define COLOUR_PINK		0xCC99FFFF  // R=CC, G=99, B=FF, A=FF
# define COLOUR_YELLOW		0xFFFF66FF  // R=FF, G=FF, B=66, A=FF
# define COLOUR_ORANGE		0xFF9933FF  // R=FF, G=99, B=33, A=FF
# define COLOUR_MAGENTA		0x660033FF  // R=66, G=00, B=33, A=FF
# define COLOUR_RED			0xFF0000FF  // R=FF, G=00, B=00, A=FF
# define COLOUR_GREEN		0x00CC00FF  // R=00, G=CC, B=00, A=FF
# define COLOUR_CYAN		0x00FFFFFF  // R=00, G=FF, B=FF, A=FF
# define COLOUR_PURPLE		0x6600FFFF  // R=66, G=00, B=FF, A=FF
# define COLOUR_BLUE		0x0099CCFF  // R=00, G=99, B=CC, A=FF
# define COLOUR_GRAY		0x333333FF  // R=33, G=33, B=33, A=FF
# define COLOUR_BLACK		0x000000FF  // R=00, G=00, B=00, A=FF
# define COLOUR_WHITE		0xFFFFFFFF  // R=FF, G=FF, B=FF, A=FF



# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/incl/libft.h"
# include <math.h>

#endif

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		size;

} t_map;

typedef struct s_vector
{
	int x;
	int y;
} t_vector;

typedef struct s_player
{
	t_vector	pos;
	int			dir;
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


void	fake_parsing(t_data *data); // TAKE OUT

void	error_and_exit(char *str);
void	clear_everything(t_data *data);
void	init_window(t_data *data);
void	fill_canvas(t_data *data);
void	key_is_pressed(void *data);
void	game(t_data *data);

