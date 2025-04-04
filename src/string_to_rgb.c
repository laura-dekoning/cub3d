/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_to_rgb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 19:52:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 18:19:43 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	is_correct_rgb(t_data *data, char c)
{
	if (ft_isalpha(c))
		error_message(data, ALPHA);
	if (c == '-')
		error_message(data, NEG);
}

void	string_to_rgb(t_data *data, int **target, char *str, int i)
{
	int	n;
	int	diff;

	n = 0;
	while (n < 3)
	{
		while (!ft_isdigit(str[i]))
		{
			is_correct_rgb(data, str[i]);
			i++;
		}
		diff = i;
		while (ft_isdigit(str[i]))
		{
			(*target)[n] = (*target)[n] * 10 + (str[i] - '0');
			i++;
		}
		if (i - diff > 3)
			error_message(data, BIG);
		n++;
	}
}

// int	main()
// {
// 	char *int_str;
// 	int	*rgb;
// 	int	n;

// 	n = 0;
// 	int_str = "F 255,100,33";
// 	rgb = string_to_rgb(int_str, 0);
// 	while (n < 3)
// 	{
// 		printf("rgb[%i] = %i\n", n, rgb[n]);
// 		n++;
// 	}
// 	return (0);
// }
