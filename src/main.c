/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:45:29 by olebedev          #+#    #+#             */
/*   Updated: 2021/02/12 23:10:47 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"


void	ft_check_value(int base, long number_1, long number_2)
{
	if (base != 2 && base != 16)
	{
		printf("Error base\n");
		exit(1);
	}
	if ((number_1 > INT_MAX && number_1 < INT_MIN)\
		|| (number_2 > INT_MAX && number_2 < INT_MIN))
	{
		printf("Error number\n");
		exit(1);
	}
	if (number_2 + number_1 > INT_MAX || number_2 - number_1 < INT_MIN)
		printf("Возможно переполнение при сложении или вычитании которое вызовет неопределенное поведение\n");
}



void	ft_print(char *name, t_bin_elem *content)
{
	printf("%s\n", name);
	printf("%s\n", content->additional_bin);
	printf("%s\n", content->reverse_bin);
	printf("%s\n", content->direct_code_bin);
}



/*

src/conversion_hex/conversion_hex.c:31:6: warning: implicit declaration of function 'ft_choose_sign' is invalid in C99
      [-Wimplicit-function-declaration]
                if(ft_choose_sign(first_elem->origin_number, second_elem->origin_number))
                   ^
src/conversion_hex/conversion_hex.c:37:8: warning: implicit declaration of function 'ft_createstr_hex' is invalid in C99
      [-Wimplicit-function-declaration]
        add = ft_createstr_hex(add);
              ^
src/conversion_hex/conversion_hex.c:37:6: warning: incompatible integer to pointer conversion assigning to 'char *' from 'int'
      [-Wint-conversion]
        add = ft_createstr_hex(add);
            ^ ~~~~~~~~~~~~~~~~~~~~~

			*/

int		main(int argc, char const *argv[])
{
	long				number_1;
	long				number_2;
	int					base;
	t_conversion_bin_elem	*first_elem;
	t_conversion_bin_elem	*second_elem;
	t_conversion_bin		*conversion_bin;
	
	// t_conversion_hex_elem	*first_elem;
	// t_conversion_hex_elem	*second_elem;
	// t_conversion_hex		*conversion_hex;

	(void)argc;
	(void)argv;
	printf("Введите первое число в пределах int:");
	scanf("%ld", &number_1);
	printf("Введите второе число в пределах int:");
	scanf("%ld", &number_2);
	printf("Введите систему счисления (2 или 16): ");
	scanf("%d", &base);
	ft_check_value(base, number_1, number_2);
	if (base == 2)
	{
		first_elem = ft_conversion_bin_elem_new(-6);
		ft_print("", first_elem->num);
		ft_print("", first_elem->inversion_num);
		second_elem = ft_conversion_bin_elem_new(number_2);
		conversion_bin = ft_conversion_bin_new(first_elem, second_elem);
		ft_print("SUM", conversion_bin->sum);
		ft_print("FDIF", conversion_bin->first_difference);
		ft_print("SDIF", conversion_bin->second_difference);
	}

	// printf("%s\n", ft_addition(ft_itoa_base(255, 16, HEX), ft_itoa_base(255, 16, HEX), 16, HEX));
	// printf("%s\n", ft_create_dif(ft_itoa_base(306, 16, HEX), ft_itoa_base(255, 16, HEX), HEX));

		// first_elem = ft_conversion_hex_elem_new(number_1);
		// second_elem = ft_conversion_hex_elem_new(number_2);
		// printf("%s\n", first_elem->num->str_hex);
		// printf("%s\n", second_elem->num->str_hex);
		// conversion_hex = ft_conversion_hex_new(first_elem, second_elem);


	// printf("%ld\n", number_1);
	// printf("%d\n", ft_choose_sign(19, -13));
	// printf("%ld\n", number_2);
	printf("HEH");
	return 0;
}


//614    == 1556
//1FE0     == 8160