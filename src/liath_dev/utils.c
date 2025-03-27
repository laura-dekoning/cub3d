/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/26 12:55:32 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/26 12:57:29 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"


void	check_angle(float *angle)
{
	if (*angle > (2 * PI))
		*angle -= (2 * PI);
	if (*angle < 0)		
		*angle += (2 * PI);
}
