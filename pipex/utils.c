/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpanis@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:47:09 by valmpani          #+#    #+#             */
/*   Updated: 2023/06/19 11:53:51 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	has_access(t_data object)
{
	if (access(object.argv[1], R_OK) != -1)
		return (open(object.argv[1], O_RDONLY));
	else
		return (-1);
}
