/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baffour <baffour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:47:39 by bkusi-fr          #+#    #+#             */
/*   Updated: 2025/05/11 06:44:22 by baffour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

long	backtracking(int i, int map[3][100], int grid[10][10], int side);
void	init_grid(int map[10][10]);
void	init_map(int map[3][100]);
int 	process_input(const char* str, int map[3][100], int side);

int	main(int argc, char **argv)
{
	int	map[3][100];
	int	grid[10][10];
	int side;

	init_grid(grid);
	init_map(map);
	side = 4;
	if (argc == 2)
	{
		process_input(argv[1], map, side);
		printf("%ld\n", backtracking(0, map, grid, side));
	}
	else
		write(1, "ERROR\n", 6);
	return (0);
}
