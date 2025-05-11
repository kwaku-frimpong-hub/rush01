/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baffour <baffour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 01:17:56 by baffour           #+#    #+#             */
/*   Updated: 2025/05/11 02:07:35 by baffour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *get_input(const char *input_txt)
{
    int *ptr; 
    int i;
    int j;

    ptr = malloc(sizeof(int) * 100);
    if (ptr == 0)
        return 0;
    i = -1;
    while(++i < 100)
        ptr[i] = -1;
    i = -1;
    j = 0;
    while(input_txt[++i])
    {
        if ('0' <= input_txt[i] && input_txt[i] <= '9')
            ptr[j++] = input_txt[i] - '0';
    }
    return ptr;
}

int process_input(const char* str, int map[3][100], int side)
{
    int i;
    int *arr;

    arr = get_input(str);
    i = -1;
    while(arr[++i] > -1)
        map[2][i] = arr[i];
    if (i < side*4 || i % side)
        return -1;
    free(arr);
    return 0;
}
