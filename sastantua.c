/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcapers <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:31:06 by dcapers           #+#    #+#             */
/*   Updated: 2019/06/08 21:26:37 by dcapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		get_width(int n)
{
	int size;
	int d;
	int i;

	size = 0;
	d = 2;
	i = 2;
	while (i <= n)
	{
		if (i % 2 == 0)
		{
			d++;
		}
		size = size + (i + d + 1) * 2;
		i++;
	}
	size += 7;
	return (size);
}

void	print_nsym(char c, int n)
{
	int i = 0;

	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
}

void	print_line_door(int size, int door, int k, int cur_h)
{
	int p;

	p = 2;
	print_nsym('*', (k - door) / 2 - 1);
	if (size % 2 == 0)
		p++;
	if (cur_h - p != (door / 2 + 1) || door <= 3)
	{
		print_nsym('|', door);
	}
	else
	{
		print_nsym('|', door - 2);
		ft_putchar('$');
		ft_putchar('|');
	}
	print_nsym('*', (k - door) / 2 - 1);
}

void	print_line(int door, int space, int k, int cur_h, int sh_d)
{
	int i;

	i = 0;
	print_nsym(' ', space - k / 2);
	ft_putchar('/');
	if (sh_d == 0 || cur_h <= 2 || (cur_h == 3 && door == 1 && k > 7))
	{
		print_nsym('*', k - 2);
	}
	else
	{
		print_nsym('*', (k - door) / 2 - 1);
		if (cur_h > 2 && (cur_h + 2) != (door/2 + 1))
		{
			print_nsym('|', door);						
		}
		else
		{
			print_nsym('|', door - 2);
			ft_putchar('$');
			ft_putchar('|');
		}
		print_nsym('*', (k - door) / 2 - 1);
	}
	ft_putchar('\\');
	ft_putchar('\n');
}
	
void	print_pyramid(int n, int space, int d)
{
	int i;
	int w;
	int door;

	w = get_width(n);
	i = 1;
	door = n;
	if (n % 2 == 0)
	{ 
		door--;
	}
	while (i <= n + 2)
	{
		print_nsym(' ', space - (w - (n + 2 - i) * 2) / 2);
		ft_putchar('/');
		if (d == 1 && ((i > 2 && n % 2 == 1) || (i > 3 && n % 2 == 0)))
		{
			print_line_door(n, door, (w - (n + 2 - i) * 2) , i);
		}
		else
		{
			print_nsym('*', (w - (n + 2 - i) * 2) - 2);
		}
		ft_putchar('\\');
		ft_putchar('\n');
		i++;
	}
}	

void	sastantua(int size)
{
	int i;
	int space;

	i = 1;
	space = (get_width(size) - 1) / 2;
	if (i > 0)
	{
		while (i <= size)
		{
			if (i == size)	
			{
				print_pyramid(i, space,  1);
			}
			else
			{
				print_pyramid(i, space, 0);
			}
			i++;
		}
	}
}
