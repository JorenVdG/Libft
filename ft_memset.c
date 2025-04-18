/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:31:34 by jvan-der          #+#    #+#             */
/*   Updated: 2025/04/17 16:38:42 by jvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}
/*
int	main()
{
	int	i = 0;
	char	array[10] = "Hello Iam";
	long long	nbrs[10];
	ft_memset(array, '1', 3);
	printf("%s\n", array);
	ft_memset(nbrs, 5, sizeof(nbrs));
	while (i < 10)
		printf("%lld ", nbrs[i++]);
	return (1);
}*/
