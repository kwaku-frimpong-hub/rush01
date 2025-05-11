/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baffour <baffour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:27:33 by bkusi-fr          #+#    #+#             */
/*   Updated: 2025/05/11 06:43:05 by baffour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void 	disp_array(int grid[10][10], int side);
int 	check_board(int grid[10][10], int side, int *user_input);
// void write_output_to_file(int grid[10][10], int side);

// map[0] row
// map[1] cols
// map[2] user input
// r = i / side
// c = i % side
long	backtracking(int i, int map[3][100], int grid[10][10], int side)
{
	int		num;
	long	total;

	if (i >= side * side)
	{
		if (check_board(grid, side, map[2]))
			disp_array(grid, side);
		return (1);
	}
	num = 0;
	total = 0;
	while (++num <= side)
	{
		if ((map[0][i / side] & (1 << num)) || (map[1][i % side] & (1 << num)))
			continue ;
		map[0][i / side] = map[0][i / side] | (1 << num);
		map[1][i % side] = map[1][i % side] | (1 << num);
		grid[i / side][i % side] = num;
		total += backtracking(i + 1, map, grid, side);
		grid[i / side][i % side] = 0;
		map[0][i / side] = map[0][i / side] ^ (1 << num);
		map[1][i % side] = map[1][i % side] ^ (1 << num);
	}
	return (total);
}
