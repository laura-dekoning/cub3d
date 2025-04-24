/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_cub3d.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 15:42:43 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/24 12:21:29 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	str_count(char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == c)
		{
			count++;
			i++;
		}
		while (str[i] && str[i] != c)
			i++;
	}
	if (str[i] == '\0')
		count++;
	return (count);
}

static size_t	str_len(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*free_mem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**fill_arr(char **arr, char *str, char c, size_t strings)
{
	size_t	i;
	size_t	len;
	int		x;

	i = 0;
	x = -1;
	while (++x < (int)strings && str[i])
	{
		if ((str[i]) == c)
		{
			arr[x] = ft_strdup("");
			i++;
		}
		else if ((str[i]) != c)
		{
			len = str_len(&(str[i]), c);
			arr[x] = ft_substr(str, i, len);
			i = i + len;
			if (str[i] == c)
				i++;
		}
		if (arr[x] == NULL)
			return (free_mem(arr));
	}
	return (arr);
}

char	**split_cub3d(char const *s, char c)
{
	char	**arr;
	size_t	strings;
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	strings = str_count((char *)s, c);
	arr = ft_calloc(strings + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = fill_arr(arr, str, c, strings);
	return (arr);
}
