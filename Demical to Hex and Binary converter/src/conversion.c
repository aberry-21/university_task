/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:45:29 by olebedev          #+#    #+#             */
/*   Updated: 2021/02/13 03:38:41 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"
#include <unistd.h>

void	ft_check_value(long number_1, long number_2)
{
	if (number_1 > INT_MAX || number_1 < INT_MIN\
		|| number_2 > INT_MAX || number_2 < INT_MIN)
	{
		printf("Введено число, выходящее за диапозон [-2147483648,2147483647]\n");
		exit(1);
	}
	if (number_2 + number_1 > INT_MAX)
		printf("Сумма чисел больше 2147483647, произойдет переполнение, которое вызовет неопределенное поведение!\n");
	if (number_2 - number_1 < INT_MIN || number_1 - number_2 < INT_MIN)
		printf("Разность чисел меньше -2147483648, произойдет переполнение, которое вызовет неопределенное поведение!\n");
}

int		main(int argc, char const *argv[])
{
	long				number_1;
	long				number_2;

	(void)argc;
	(void)argv;
	printf("Введите первое число в пределах int:");
	scanf("%ld", &number_1);
	printf("Введите второе число в пределах int:");
	scanf("%ld", &number_2);
	ft_check_value(number_1, number_2);
	ft_conversion_decimal_to_bin(number_1, number_2);
	ft_conversion_decimal_to_hex(number_1, number_2);
	return (0);
}
