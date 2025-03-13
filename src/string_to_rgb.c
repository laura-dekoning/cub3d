/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_to_rgb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 19:52:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/13 14:08:47 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	*string_to_rgb(t_data *data, char *str, int i)
{
	int	*rgb;
	int	n;

	rgb = (int *)safe_calloc(data, 3, sizeof(int));
	n = 0;

	while (n < 3)
	{
		while (!ft_isdigit(str[i]))
		{
			if (str[i] == '-')
				error_message(NULL, NEG); //Misschien even check of data meegegeven moet worden, zodat hier clean_exit gedaan kan worden. 
			i++;
		}
		while (ft_isdigit(str[i]))
		{
			rgb[n] = rgb[n] * 10 + (str[i] - '0');
			i++;
		}
		n++;
	}
	return (rgb);
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
// 		printf("rbg[%i] = %i\n", n, rgb[n]);
// 		n++;
// 	}
// 	return (0);
// }
