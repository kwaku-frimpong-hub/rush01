/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkusi-fr <bkusi-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:16:35 by bkusi-fr          #+#    #+#             */
/*   Updated: 2025/05/11 10:16:43 by bkusi-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_map(int map[3][100])
{
	int	r;
	int	c;

	r = 0;
	while (r < 3)
	{
		c = 0;
		while (c < 100)
		{
			map[r][c] = 0;
			c++;
		}
		r++;
	}
}

void	init_grid(int map[10][10])
{
	int	r;
	int	c;

	r = 0;
	while (r < 10)
	{
		c = 0;
		while (c < 10)
		{
			map[r][c] = 0;
			c++;
		}
		r++;
	}
}
