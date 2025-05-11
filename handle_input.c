/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkusi-fr <bkusi-fr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 01:17:56 by baffour           #+#    #+#             */
/*   Updated: 2025/05/11 11:54:51 by bkusi-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_digit(char ch);

int	validate_input(const char *str)
{
	int	i;

	if (!is_digit(str[0]))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!(is_digit(str[i]) && str[i - 1] == ' ') && !(str[i] == ' '
				&& is_digit(str[i - 1])))
			return (0);
		i++;
	}
	if (str[i - 1] == ' ')
		return (0);
	return (1);
}

int	*get_input(const char *input_txt)
{
	int	*ptr;
	int	i;
	int	j;

	if (!validate_input(input_txt))
		return (0);
	ptr = malloc(sizeof(int) * 100);
	if (ptr == 0)
		return (0);
	i = -1;
	while (++i < 100)
		ptr[i] = -1;
	i = -1;
	j = 0;
	while (input_txt[++i])
	{
		if ('0' <= input_txt[i] && input_txt[i] <= '9')
			ptr[j++] = input_txt[i] - '0';
	}
	return (ptr);
}

int	process_input(const char *str, int map[3][100], int side)
{
	int	i;
	int	*arr;

	arr = get_input(str);
	if (arr == 0)
		return (0);
	i = -1;
	while (arr[++i] > -1)
		map[2][i] = arr[i];
	if (i < side * 4 || i % side)
		return (0);
	free(arr);
	return (1);
}
