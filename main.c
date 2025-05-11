/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkusi-fr <bkusi-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:47:39 by bkusi-fr          #+#    #+#             */
/*   Updated: 2025/05/11 11:56:14 by bkusi-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	backtracking(int i, int map[3][100], int grid[10][10], int side);
void	init_grid(int map[10][10]);
void	init_map(int map[3][100]);
int		process_input(const char *str, int map[3][100], int side);

int	solve_puzzle(const char *txt, int map[3][100], int side, int grid[10][10])
{
	if (process_input(txt, map, side) == 0)
		return (0);
	if (backtracking(0, map, grid, side) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	map[3][100];
	int	grid[10][10];
	int	side;

	init_grid(grid);
	init_map(map);
	side = 4;
	if (argc == 2)
	{
		if (solve_puzzle(argv[1], map, side, grid) == 0)
			write(1, "ERROR\n", 6);
	}
	else
		write(1, "ERROR\n", 6);
	return (0);
}
