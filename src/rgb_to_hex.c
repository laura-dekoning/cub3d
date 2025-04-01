/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_to_hex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:11:06 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/01 18:13:59 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	rgb_to_hex(int red, int green, int blue)
{
	unsigned int	hex_color;

	hex_color = (red << 16) | (green << 8) | blue;
	return (hex_color);
}
