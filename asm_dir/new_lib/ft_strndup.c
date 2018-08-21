/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismus <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:41:55 by ismus             #+#    #+#             */
/*   Updated: 2017/10/24 14:48:51 by ismus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*c;

	i = 0;
	c = (char *)malloc(sizeof(char) * (n + 1));
	if (!c)
		return (0);
	while (src[i] && i < n)
	{
		c[i] = src[i];
		i++;
	}
	while (i <= n)
		c[i++] = '\0';
	return (c);
}
