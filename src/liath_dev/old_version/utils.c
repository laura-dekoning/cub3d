/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/14 13:31:30 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/17 13:59:57 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/liath.h"

float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	get_min(float a, float b)
{
	if (a > b)
		return (b);
	else
		return (a);
}
