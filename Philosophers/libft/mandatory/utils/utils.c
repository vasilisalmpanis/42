/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:52:47 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/24 10:59:17 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**split_args(char *input)
{
	int		j;
	char	buf;
	char	**split;

	j = -1;
	while (input[++j])
	{
		if (ft_isspace(input[j]))
			input[j] = 26;
		if (input[j] == '"' || input[j] == '\'')
		{
			buf = input[j];
			++j;
			while (input[j] && input[j] != buf)
				j++;
		}
	}
	input = handle_redirects(input);
	if (!input)
		return (NULL);
	split = ft_split(input, 26);
	free(input);
	return (split);
}

char	*ft_charjoin_mod(char *s1, char s2)
{
	char	*ret;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + 1;
	ret = malloc((len + 1) * sizeof(*ret));
	if (!ret)
		return (free(s1), NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i++] = s2;
	ret[i] = '\0';
	free(s1);
	return (ret);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc((len + 1) * sizeof(*ret));
	if (!ret)
		return (free(s1), NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}

void	rm_newline(char **str)
{
	size_t	i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	(*str)[i] = '\0';
}

void	ft_putstr_fd_mod(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
