/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solver.c                                      :+:      :+:  :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galmague <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:13:48 by galmague          #+#    #+#             */
/*   Updated: 2020/01/19 20:44:46 by galmague         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ispresent(int **argv, int row, int column, int num);

int		sudoku_solver(int **argv, int num);

int		sudoku_solver(int **argv, int num)
{
	int i;
	int row;
	int column;

	i = 1;
	row = num / 9;
	column = num % 9;
	if (num == 81)
		return (1);
	if (argv[row][column] != 0)
		return (sudoku_solver(argv, num + 1));
	else
	while (i < 10)
	{
		if (!(ispresent(argv,row, column,i)))
		{
			argv[row][column] = i;
			if (sudoku_solver(argv, num + 1))
				return (1);
			else
				argv[row][column] = 0;
		}
		i++;
	}
	return (0);
}

int		**findanswer(int **res)
{
	if (sudoku_solver(res, 0) == 0)
	{
		write(1, "There is no answer\n", 20);
		return (0);
	}
	return (res);
}
