/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:07:56 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/14 19:20:31 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int	ft_find_wc(char *n, char c)
{
	int	iw;
	int	i;
	int	wc;

	iw = 0;
	i = 0;
	wc = 0;
	if (!n)
		return (0);
	while (n[i])
	{
		if (n[i] == c)
			iw = 0;
		if (n[i] != c && !iw)
		{
			wc++;
			iw = 1;
		}
		i++;
	}
	return (wc);
}

char	*ft_cs(char *n, char c)
{
	int		i;
	char	*s;

	i = 0;
	while (n[i] != c && n[i])
		i++;
	s = malloc((i + 1) * sizeof(char));
	ft_strlcpy(s, n, i + 1);
	if (!s)
	{
		free(s);
		return (NULL);
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**b;
	int		wc;
	int		i;
	char	*n;

	n = (char *)s;
	wc = ft_find_wc(n, c);
	b = (char **)malloc((wc + 1) * sizeof(char *));
	if (!b)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		while (*n == c)
			n++;
		b[i] = ft_cs(n, c);
		if (!b[i])
			return (NULL);
		i++;
		while (*n != c && *n)
			n++;
	}
	b[i] = NULL;
	return (b);
}

// Create on function to find the word count
// allocate to the 2 pointer for at least one + the wc and guard it
// the iterate throuth the array and and use the third function to
// jump the delimiters and use that to create the copy of the str and guard it
// !! in the exam you need to recreate strlcpy or substr but the first is better
// if you find more delimiters jump them
// NULLify the last element and return the 2-D array of strings.