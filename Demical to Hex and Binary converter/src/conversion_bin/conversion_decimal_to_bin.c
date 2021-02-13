/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_decimal_to_bin.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:42:18 by aberry            #+#    #+#             */
/*   Updated: 2021/02/13 03:21:26 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

static void	ft_print_bin(char *text_message, t_bin_elem *content)
{
	printf("%s", text_message);
	printf("%ld\n", content->origin_number);
	printf("Дополнительный код равен: \t%s\n", content->complement_bin);
	printf("Обратный код равен:\t\t%s\n", content->inverse_bin);
	printf("Прямой код равен:\t\t%s\n\n", content->direct_code_bin);
}

void		ft_conversion_decimal_to_bin(int number_1, int number_2)
{
	int						base;
	t_conversion_bin_elem	*first_elem;
	t_conversion_bin_elem	*second_elem;
	t_conversion_bin		*conversion_bin;

	base = 2;
	first_elem = ft_conversion_bin_elem_new(number_1);
	second_elem = ft_conversion_bin_elem_new(number_2);
	conversion_bin = ft_conversion_bin_new(first_elem, second_elem);
	ft_print_bin("\t\tПервое число в 2ой системе счисления\t\t\nЧисло в 10ой системе счисления:\t", first_elem->num);
	ft_print_bin("\t\tВторое число в 2ой системе счисления\t\t\nЧисло в 10ой системе счисления:\t", second_elem->num);
	ft_print_bin("\t\tСумма чисел\t\t\nИтог в 10ой системе счисления:\t", conversion_bin->sum);
	ft_print_bin("\t\tРазность первого числа со вторым\t\nИтог в 10ой системе счисления:\t", conversion_bin->first_difference);
	ft_print_bin("\t\tРазность второго числа с первым\t\nИтог в 10ой системе счисления:\t", conversion_bin->second_difference);
	ft_conversion_bin_destructor(conversion_bin);
	ft_conversion_bin_elem_destructor(first_elem);
	ft_conversion_bin_elem_destructor(second_elem);
}
