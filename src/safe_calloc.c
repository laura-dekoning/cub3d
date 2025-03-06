/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safe_calloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/06 18:08:01 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/06 18:10:36 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*safe_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
		error_message(MALLOC);
	return (ptr);
}
