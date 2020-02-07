/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_ispresent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galmague <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:13:48 by galmague          #+#    #+#             */
/*   Updated: 2020/01/19 20:44:46 by galmague         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	exist_row(int **argv, int row, int num)
{
	int j;

	j = 0;
	while (j < 9)
	{
		if (argv[row][j] == num)
		{
			return (1);
		}
		else
		{
			j++;
		}
	}
	return (0);
}

int	exist_column(int **argv, int column, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (argv[i][column] == num)
		{
			return (1);
		}
		else
		{
			i++;
		}
	}
	return (0);
}

int	exist_square(int **argv, int column, int row, int num)
{
	int i;
	int j;
	int t;
	int w;

	i = 0;
	j = 0;
	t = row % 3;
	w = column % 3;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (argv[(row - t) + i][(column - w) + j] == num)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ispresent(int **argv, int row, int column, int num)
{
	if (exist_square(argv, column, row, num) || exist_column(argv, column, num)
			|| exist_row(argv, row, num))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
