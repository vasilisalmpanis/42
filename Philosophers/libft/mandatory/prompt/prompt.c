/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamesser <mamesser@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:43:49 by valmpani          #+#    #+#             */
/*   Updated: 2023/08/24 16:55:34 by mamesser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_git_head(char *w)
{
	char	buf[100];
	char	*temp;
	int		fd;
	int		i;
	size_t	bytes;

	fd = open(w, O_RDONLY);
	if (!fd)
		return (NULL);
	bytes = read(fd, buf, 100);
	i = 0;
	buf[bytes] = 0;
	while (buf[i])
		++i;
	while (buf[i] != '/' && i > 0)
		--i;
	if (i == 0)
		return (ft_substr(w, 0, 7));
	i++;
	temp = ft_substr(buf, i, ft_strlen(buf) - (size_t)i);
	temp[ft_strlen(temp) - 1] = '\0';
	return (temp);
}

void	get_repo(char **input, char *head, char *w)
{
	char	*temp;
	char	*last_str;

	if (!head)
		temp = get_git_head(w);
	else
		temp = ft_strdup(head);
	if (!temp)
		return ;
	last_str = ft_strjoin(*input, LIGHT_BLUE"git:("RED);
	free(*input);
	*input = ft_strdup(last_str);
	free(last_str);
	last_str = ft_strjoin(*input, temp);
	free(*input);
	free(temp);
	*input = ft_strjoin(last_str, LIGHT_BLUE") "ESCAPE);
	free(last_str);
}

char	*current_dir(void)
{
	char	**temp;
	char	*buf;
	char	*string;
	int		i;

	i = 0;
	buf = getcwd(NULL, 0);
	if (!buf)
		return (ft_strdup("  minishell "));
	if (ft_strncmp(buf, "/", ft_strlen(buf)) == 0)
	{
		free(buf);
		return (ft_strdup("/"));
	}
	temp = ft_split(buf, '/');
	if (!temp)
	{
		string = ft_strdup("  minishell ");
		return (free (buf), string);
	}
	while (temp[i])
		i++;
	free(buf);
	string = ft_strdup(temp[i - 1]);
	return (ft_free(temp), string);
}

char	*git_traversal(void)
{
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	path = ft_strdup(".git/HEAD");
	while (access(path, O_RDONLY) != 0 && i < 10)
	{
		temp = ft_strjoin("../", path);
		free(path);
		if (!temp)
			return (NULL);
		path = ft_strdup(temp);
		free(temp);
		if (!path)
			return (NULL);
		++i;
	}
	if (access(path, O_RDONLY) != 0 && i == 10)
		return (free(path), NULL);
	return (path);
}

char	*prompt(void)
{
	char	*temp[3];

	temp[0] = current_dir();
	temp[1] = getcwd(NULL, 0);
	if (!temp[1])
		return (ft_strdup(GREEN"→" BLUE"  / "ESCAPE));
	if ((ft_strncmp(temp[1], "/", ft_strlen(temp[1])) == 0) != 0)
	{
		free(temp[1]);
		return (free(temp[0]), ft_strdup(GREEN"→" BLUE"  / "ESCAPE));
	}
	free(temp[1]);
	temp[2] = ft_strjoin(GREEN"→" BLUE"  ", temp[0]);
	free(temp[0]);
	if (!temp[2])
		return (ft_strdup(GREEN"→" BLUE"  minishell "ESCAPE));
	temp[0] = ft_strjoin(temp[2], " "ESCAPE);
	free(temp[2]);
	if (temp[0] == NULL)
		return (ft_strdup(GREEN"→" BLUE"  minishell "ESCAPE));
	temp[2] = git_traversal();
	if (!temp[2])
		return (temp[0]);
	get_repo(&temp[0], NULL, temp[2]);
	return (free(temp[2]), temp[0]);
}
