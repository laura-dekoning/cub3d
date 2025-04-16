/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_to_rgb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 19:52:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/16 17:17:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_correct_rgb(t_data *data, char *str, int i)
{
	while (!ft_isdigit(str[i]) && str[i])
	{
		if (ft_isalpha(str[i]))
			error_free_data(data, ALPHA);
		if (str[i] == '-')
			error_free_data(data, NEG);
		i++;
	}
	return (i);
}

void	string_to_rgb(t_data *data, int **target, char *str, int i)
{
	int	n;
	int	diff;
	int found;

	n = 0;
	while (n < 3)
	{
		i = is_correct_rgb(data, str, i);
		diff = i;
		found = 0;
		while (ft_isdigit(str[i]) && str[i])
		{
			(*target)[n] = (*target)[n] * 10 + (str[i] - '0');
			i++;
			found = 1;
		}
		if (!found)
			error_free_data(data, "One or more RGB colors are missing =(");
		if (i - diff > 3)
			error_free_data(data, BIG);
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
