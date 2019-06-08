/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:41:39 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/08 15:54:55 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnchar(int nb)
{
	int		nd;

	if (nb <  0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb != 0)
	{
		nd = nb % 10;
		ft_putnchar(nb / 10);
		ft_putchar('0' + nd);
	}
}
