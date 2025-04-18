/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb_to_hex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 18:11:06 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 17:14:46 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint64_t	rgb_to_hex(int red, int green, int blue, int alpha)
{
	uint64_t	hex_color;

	hex_color = (red << 24) | (green << 16) | (blue << 8) | alpha;
	return (hex_color);
}
