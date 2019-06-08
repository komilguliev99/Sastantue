/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:44:53 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/08 19:30:27 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int		get_width(int n);
void	sastantua(int size);
int		ft_putchar(char c);

int		ft_atoi(char *str)
{
	int num;
	int i;
	int t;

	i = 0;
	num = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) > '9' || *(str + i) < '0')
		{
			return (0);
		}
		t = *(str + i) - 48;
		num = num * 10 + t;
		i++;
	}
	return (num);
}

int		main(int argc, char **argv)
{
	int sz;
	sz = argc;
	sastantua(ft_atoi(argv[1]));
	return (0);
}
