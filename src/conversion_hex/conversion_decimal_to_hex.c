/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_decimal_to_hex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:42:18 by aberry            #+#    #+#             */
/*   Updated: 2021/02/13 03:13:39 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

static void	ft_print_hex(char *text_message, t_hex_elem *content)
{
	printf("%s", text_message);
	printf("%ld\n", content->origin_number);
	printf("Прямой код равен:\t\t%s\n", content->direct_code_hex);
	printf("Результат преобразований равен:\t%s\n\n", content->str_hex);
}

void		ft_conversion_decimal_to_hex(int number_1, int number_2)
{
	int						base;
	t_conversion_hex_elem	*first_elem;
	t_conversion_hex_elem	*second_elem;
	t_conversion_hex		*conversion_hex;

	base = 16;
	first_elem = ft_conversion_hex_elem_new(number_1);
	second_elem = ft_conversion_hex_elem_new(number_2);
	conversion_hex = ft_conversion_hex_new(first_elem, second_elem);
	ft_print_hex("\t\tПервое число в 16ой системе счисления\t\t\nЧисло в 10ой системе счисления:\t", first_elem->num);
	ft_print_hex("\t\tВторое число в 16ой системе счисления\t\t\nЧисло в 10ой системе счисления:\t", second_elem->num);
	printf("Сумма чисел в 16ой системе счисления:\t\t\t\t%s\n", conversion_hex->sum);
	printf("Разность первого числа со вторым в 16ой системе счисления:\t%s\n", conversion_hex->first_difference);
	printf("Разность второго числа с первым  в 10ой системе счисления:\t%s\n", conversion_hex->second_difference);
	ft_conversion_hex_elem_destructor(first_elem);
	ft_conversion_hex_elem_destructor(second_elem);
	ft_conversion_hex_destructor(conversion_hex);
}
