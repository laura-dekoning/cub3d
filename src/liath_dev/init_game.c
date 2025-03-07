/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/07 14:41:53 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/07 17:45:31 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

void	fill_canvas(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < data->image->height)
	{
		x = 0;
		while (x < data->image->width)
		{
			if (x < data->image->width && y < data->image->height)
				mlx_put_pixel(data->image, x, y, COLOUR_GRAY);
			x++;
		}
		y++;
	}
}

void	put_pixels(t_data *data, uint32_t pos_x, uint32_t pos_y, uint32_t width, uint32_t height, uint64_t colour)
{
	uint32_t	x;
	uint32_t	y;

	y = pos_y;
	while (y < pos_y + height)
	{
		x = pos_x;
		while (x < pos_x + width)
		{
			if (x < data->image->width && y < data->image->height)
				mlx_put_pixel(data->image, x, y, colour);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	put_pixels(data, data->player->x, data->player->y, 10, 10, COLOUR_YELLOW);
}


// void drawMap2D()
// {
//  int x,y,xo,yo;
//  for(y=0;y<mapY;y++)
//  {
//   for(x=0;x<mapX;x++)
//   {
//    if(map[y*mapX+x]==1){ glColor3f(1,1,1);} else{ glColor3f(0,0,0);}
//    xo=x*mapS; yo=y*mapS;
//    glBegin(GL_QUADS); 
//    glVertex2i( 0   +xo+1, 0   +yo+1); 
//    glVertex2i( 0   +xo+1, mapS+yo-1); 
//    glVertex2i( mapS+xo-1, mapS+yo-1);  
//    glVertex2i( mapS+xo-1, 0   +yo+1); 
//    glEnd();
//   } 
//  } 


void	draw_2D_map(t_data *data)
{
	int x;
	int y;
	int x_o;
	int y_o;
	uint64_t colour;
	
	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
			x_o = x * data->map->size;
			y_o = y * data->map->size;
			if (data->map->map[y * data->map->cols + x] == 1)
				colour = COLOUR_WHITE;
			else 
				colour = COLOUR_BLACK;
			put_pixels(data, x_o, y_o, data->map->size, data->map->size, colour);
			x++;
		}
		y++;
	}
}

void	game(t_data *data)
{
	draw_2D_map(data);
	draw_player(data);
}

void	init_window(t_data *data)
{
	data->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);
	if (data->window == NULL)
	{
		error_and_exit("Window could not be created\n");
	}
	data->image = mlx_new_image(data->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (data->image == NULL)
	{
		mlx_terminate(data->window);
		error_and_exit("Image could not be created\n");
	}
	mlx_image_to_window(data->window, data->image, 0, 0);
	fill_canvas(data); // we now have a gray empty screen!
	// ------------------------------------------------------------------------------

	game(data);

	mlx_loop_hook(data->window, key_is_pressed, data);
	printf("TEST1\n");
	mlx_loop(data->window);
	printf("TEST2\n");
	mlx_terminate(data->window);
}