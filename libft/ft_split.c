/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:07:56 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/19 16:50:11 by valmpani         ###   ########.fr       */
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

void	ft_free(char **b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(b[i]);
		i++;
	}
	free(b);
}

char	**ft_cs(char *n, char **b, char c, int wc)
{
	int		i;
	char	*s;
	int		str_len;

	i = 0;
	while (i < wc)
	{
		str_len = 0;
		while (*n == c)
			n++;
		while (*n != c && *n != '\0')
		{
			str_len++;
			n++;
		}
		s = (char *)malloc((str_len + 1) * sizeof(char));
		if (s == NULL)
		{
			ft_free(b, i + 1);
			return (NULL);
		}
		ft_strlcpy(s, n - str_len, str_len + 1);
		b[i++] = s;
	}
	return (b);
}

char	**ft_split(char const *s, char c)
{
	char	**b;
	int		wc;
	char	*n;

	n = (char *)s;
	wc = ft_find_wc(n, c);
	b = (char **)ft_calloc((wc + 1), sizeof(char *));
	if (b == NULL)
		return (NULL);
	b = ft_cs(n, b, c, wc);
	return (b);
}

// Create on function to find the word count
// allocate to the 2 pointer for at least one + the wc and guard it
// the iterate throuth the array and and use the third function to
// jump the delimiters and use that to create the copy of the str and guard it
// !! in the exam you need to recreate strlcpy or substr but the first is better
// if you find more delimiters jump them
// NULLify the last element and return the 2-D array of strings.