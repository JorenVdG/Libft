/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:45:32 by jvan-der          #+#    #+#             */
/*   Updated: 2025/04/18 16:26:20 by jvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (little_len <= len-- && *big)
	{
		if (!ft_memcmp(big, little, little_len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
/*
int main ()
{
	char *big = NULL;
	char *little = NULL;
	size_t i = 10;

	ft_strnstr(big, little, i);
}*/
