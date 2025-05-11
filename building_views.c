/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_views.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkusi-fr <bkusi-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:56:19 by baffour           #+#    #+#             */
/*   Updated: 2025/05/11 09:25:39 by bkusi-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	vert_view(int grid[10][10], int side, int start_col, int dxn)
{
	int	cur_max;
	int	cnt;
	int	r;

	cnt = 0;
	cur_max = -99;
	r = 0;
	if (dxn < 0)
		r = side - 1;
	while (0 <= r && r < side)
	{
		if (cur_max < grid[r][start_col])
		{
			cur_max = grid[r][start_col];
			cnt++;
		}
		r += dxn;
	}
	return (cnt);
}

int	hort_view(int grid[10][10], int side, int start_row, int dxn)
{
	int	cur_max;
	int	cnt;
	int	c;

	cnt = 0;
	c = 0;
	cur_max = -99;
	if (dxn < 0)
		c = side - 1;
	while (0 <= c && c < side)
	{
		if (cur_max < grid[start_row][c])
		{
			cur_max = grid[start_row][c];
			cnt++;
		}
		c += dxn;
	}
	return (cnt);
}

int	check_board(int grid[10][10], int side, int *user_input)
{
	int	i;

	i = -1;
	while (++i < side * 4)
	{
		if (0 <= i && i < side)
			if (vert_view(grid, side, i % side, 1) != user_input[i])
				return (0);
		if (side <= i && i < 2 * side)
			if (vert_view(grid, side, i % side, -1) != user_input[i])
				return (0);
		if (2 * side <= i && i < 3 * side)
			if (hort_view(grid, side, i - 2 * side, 1) != user_input[i])
				return (0);
		if (3 * side <= i && i < 4 * side)
			if (hort_view(grid, side, i - 3 * side, -1) != user_input[i])
				return (0);
	}
	return (1);
}
