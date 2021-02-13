/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_convertion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:02:53 by aberry            #+#    #+#             */
/*   Updated: 2021/02/13 03:13:46 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

char	*ft_itoa_base(long num, int base, char *alpha)
{
	char	arr[32 + 1];
	int		counter_arr;

	memset(arr, '0', 33);
	if (num < 0)
	{
		arr[0] = '1';
		num =  -num;
	}
	counter_arr = 31;
	while (num)
	{
		arr[counter_arr--] = alpha[num % base];
		num /= base;
	}
	arr[32] = '\0';
	return (strdup(arr));
}

char	*ft_strjoin(char const *str_1, char const *str_2)
{
	size_t	len_1;
	size_t	len_2;
	char	*result;

	if (!str_1 || !str_2)
		return ((char *)0);
	len_1 = strlen(str_1);
	len_2 = strlen(str_2);
	result = (char *)malloc(len_1 + len_2 + 1);
	if (!result)
		return ((char *)0);
	memcpy(result, str_1, len_1);
	memcpy(result + len_1, str_2, len_2);
	result[len_1 + len_2] = '\0';
	return (result);
}
