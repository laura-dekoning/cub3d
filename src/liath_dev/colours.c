/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colours.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/19 19:26:28 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/19 19:26:28 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"


uint64_t darken_colour(uint64_t colour, int shift)
{
	uint64_t darker_colour;

	uint64_t r = (colour >> 24) & 0xFF;
	uint64_t g = (colour >> 16) & 0xFF;
	uint64_t b = (colour >> 8) & 0xFF;
	uint64_t a = (colour) & 0xFF;

	r = r >> shift;
	g = g >> shift;
	b = b >> shift;

	darker_colour = (r << 24) | (g << 16) | ( b << 8) | a;
	return (darker_colour);
}