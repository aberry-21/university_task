/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference_addition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:17:40 by aberry            #+#    #+#             */
/*   Updated: 2021/02/13 03:13:45 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

char		*ft_create_str_hex(char *str)
{
	char	add[2];

	add[1] = '\0';
	add[0] = (str[0] == '1') ? '-' : '\0' ;
	str++;
	while (*str == '0')
		str++;
	return (ft_strjoin(add, str));
}

int		ft_choose_sign(int first, int second)
{
	int			flag;

	flag = 0;
	if (labs(second) == labs(first))
		return (flag);
	if (second < 0)
		flag = 1;
	if (labs(second) > labs(first))
		return (flag);
	else
		return (!flag);
}

static int		ft_find_index(char ch, char *alpha)
{
	int			i;

	i = 0;
	while (alpha[i])
	{
		if (ch == alpha[i])
			return (i);
		i++;
	}
	return (0);
}

char			*ft_addition(char *first_term, char *second_term, int base, char *alpha)
{
	int		sum_array[32];
	char	array[32 + 1];
	int		counter;
	int		remainder;

	counter = 0;
	bzero(sum_array, 33);
	bzero(array, 33);
	while (first_term[counter] && second_term[counter])
	{
		sum_array[counter] = ft_find_index(first_term[counter], alpha) + ft_find_index(second_term[counter], alpha);
		counter++;
	}
	remainder = 0;
	counter--;
	while (counter > -1)
	{
		array[counter] = alpha[(sum_array[counter] + remainder) % base];
		remainder = ((sum_array[counter] + remainder) / base);
		counter--;
	}
	return (strdup(array));
}

char			*ft_difference_hex(char *first_term, char *second_term, char *alpha)
{
	char	arr[32 + 1];
	int		counter;
	int		loan;
	int		index;

	counter = 31;
	bzero(arr, 33);
	loan = 0;
	while (first_term[counter] && second_term[counter])
	{
		
		index = ft_find_index(first_term[counter], alpha) - ft_find_index(second_term[counter], alpha) - loan;
		if (index < 0)
		{
			loan = 1;
			index += 16;
		}
		else
			loan = 0;
		arr[counter] = alpha[index];
		counter--;
	}
	return (strdup(arr));
}

char		*ft_sum_hex(t_conversion_hex_elem *first_elem, t_conversion_hex_elem *second_elem)
{
	char		*add;
	char		*tmp;

	if (first_elem->num->origin_number < 0 && second_elem->num->origin_number < 0)
	{
		add = ft_addition(first_elem->num->direct_code_hex, second_elem->num->direct_code_hex, 16, HEX);
		add[0] = '1';
	}
	else if (first_elem->num->origin_number < 0 || second_elem->num->origin_number < 0)
	{
		if (labs(first_elem->num->origin_number) > labs(second_elem->num->origin_number))
			add = ft_difference_hex(first_elem->num->unsigned_hex, second_elem->num->unsigned_hex, HEX);
		else
			add = ft_difference_hex(second_elem->num->unsigned_hex, first_elem->num->unsigned_hex, HEX);
		if(ft_choose_sign(first_elem->num->origin_number, second_elem->num->origin_number))
			add[0] = '1';
	}
	else
		add = ft_addition(first_elem->num->direct_code_hex, second_elem->num->direct_code_hex, 16, HEX);
	tmp = add;
	add = ft_create_str_hex(add);
	free(tmp);
	return(add);
}