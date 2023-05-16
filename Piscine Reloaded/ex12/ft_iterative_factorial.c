/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valmpani <valmpani@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:08:22 by valmpani          #+#    #+#             */
/*   Updated: 2023/05/09 18:16:05 by valmpani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nbr)
{
	int	temp;

	if (nbr < 0)
		return (0);
	temp = nbr;
	if (nbr == 0)
	{
		return (1);
	}
	while (temp > 1)
	{
		nbr = nbr * (temp - 1);
		temp--;
	}
	return (nbr);
}

// int main(void)
// {
// 	int nbr = 5;
// 	ft_iterative_factorial(nbr);
// }