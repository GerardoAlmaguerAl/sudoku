/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galmague <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:13:48 by galmague          #+#    #+#             */
/*   Updated: 2020/01/19 20:44:46 by galmague         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		**findanswer(int **res);

int		**get_number(char **str)
{
	int		**arr;
	int		i;
	int		j;

	i = 0;
	arr = (int**)malloc(sizeof(int*) * 10);
	while (i < 9)
	{
		arr[i] = (int*)malloc(sizeof(int) * 10);
		j = 0;
		while (j < 9)
		{
			if (str[i][j] >= '1' && str[i][j] <= '9')
			{
				arr[i][j] = str[i][j] - '0';
				j++;
			}
			else if (str[i][j] == '.')
				arr[i][j++] = 0;
			else
				return (0);
		}
		i++;
	}
	return (arr);
}

void	ft_print(int **argv)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			c = argv[i][j] + '0';
			write(1, &c, 1);
			if (j < 8)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		**arr;

	if (argc == 10)
	{
		arr = get_number(&argv[1]);
		if (!arr)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		arr = findanswer(arr);
		if (arr)
			ft_print(arr);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
