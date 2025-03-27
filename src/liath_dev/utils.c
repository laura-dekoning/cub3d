/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/26 12:55:32 by livliege      #+#    #+#                 */
/*   Updated: 2025/03/27 14:59:55 by livliege      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../../incl/liath.h"

// single ascii to unsigned int. returns positive int on succes, returns -1 on error
int satoui(const char c)
{
	if (ft_isdigit(c))
	{
		return (c - '0');
	}
	else 
		return (-1);
}


void	check_angle(float *angle)
{
	if (*angle > (2 * PI))
		*angle -= (2 * PI);
	if (*angle < 0)		
		*angle += (2 * PI);
}
