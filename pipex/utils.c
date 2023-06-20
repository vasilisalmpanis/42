/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:47:09 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 17:39:38 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*environment(t_data object)
{
	int		j;

	j = -1;
	while (object.env[++j])
	{
		if (strnstr(object.env[j], "PATH", ft_strlen(object.env[j])))
			return (object.env[j] + 5);
	}
	return ("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/opt/X11/bin:/Library/Apple/usr/bin");
}

int	has_access(t_data object)
{
	if (access(object.argv[1], R_OK) != -1)
		return (open(object.argv[1], O_RDONLY));
	else
		return (-1);
}

char	*command_access(char *env, char *cmd)
{
	char	**split;
	char	*buf;
	char	*final;
	int		i;

	i = -1;
	split = ft_split(env, ':');
	while (split[++i])
	{
		buf = ft_strjoin(split[i], "/");
		final = ft_strjoin(buf, cmd);
		free(buf);
		if (access(final, X_OK) == 0)
		{
			ft_free(split);
			return (final);
		}
		free(final);
	}
	ft_free(split);
	return (NULL);
}

char	*find_command(t_data object, int i)
{
	char	*buf;
	char	*path;
	char	**cmd;

	cmd = split_args(object, i);
	if (!*cmd)
		return (NULL);
	path = environment(object);
	buf = command_access(path, cmd[0]);
	ft_free(cmd);
	return (buf);
}

char	**split_args(t_data object, int i)
{
	int		j;
	char	buf;
	char	**split;

	j = -1;
	while (object.argv[i][++j])
	{
		if (object.argv[i][j] == ' ')
			object.argv[i][j] = 26;
		if (object.argv[i][j] == 39 || object.argv[i][j] == 34)
		{
			buf = object.argv[i][j];
			object.argv[i][j] = 26;
			while (object.argv[i][j] != buf && object.argv[i][j])
				j++;
			object.argv[i][j] = 26;
		}
	}
	split = ft_split(object.argv[i], 26);
	return (split);
}
