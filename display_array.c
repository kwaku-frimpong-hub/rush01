/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkusi-fr <bkusi-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:28:54 by baffour           #+#    #+#             */
/*   Updated: 2025/05/11 09:25:32 by bkusi-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	disp_array(int grid[10][10], int side)
{
	int		r;
	int		c;
	char	ch;

	r = -1;
	while (++r < side)
	{
		c = -1;
		while (++c < side)
		{
			ch = '0' + grid[r][c];
			write(1, &ch, 1);
		}
		write(1, "\n", 1);
	}
}

// void write_output_to_file(int grid[10][10], int side)
// {
//     FILE *fptr;
//     fptr = fopen("possible.txt", "a");
//     int r;
//     int c;
//     char ch;

//     r = -1;
//     while(++r < side)
//     {
//         c = -1;
//         while(++c < side)
//         {
//             ch = '0' + grid[r][c];
//             fprintf(fptr, "%c", ch);
//         }
//     }
//     fprintf(fptr, "\n\n");
//     fclose(fptr);
// }
