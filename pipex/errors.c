/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:58:45 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 14:07:39 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_files(char *object, char *argv)
{
	ft_printf("Pipex: ");
	perror(object);
	if (ft_strncmp(object, argv, ft_strlen(object)) == 0)
		exit(1);
}
