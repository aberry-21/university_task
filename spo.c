/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olebedev <olebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:45:29 by olebedev          #+#    #+#             */
/*   Updated: 2021/02/10 11:40:33 by olebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct		s_bin_elem
{
	int				origin_number;
	char			*bin_number;
	char			*inv_bin_number;
}					t_bin_elem;

char	*ft_inversion_bin(char *bin)
{
	int			i;
	char		*inv_bin;

	i = 0;
	inv_bin = strdup(bin);
	while (bin[++i])
		inv_bin[i] = (bin[i] == '0') ? '1' : '0';
	return (inv_bin);
}



char	*ft_itoa(long num)
{
	char	arr[32 + 1];
	int		counter_arr;
	int		positive;

	memset(arr, '0', 32);
	if (num < 0)
	{
		arr[0] = '1';
		num =  -num;
	}
	counter_arr = 31;
	while (num)
	{
		arr[counter_arr--] = num % 2 + '0';
		num /= 2;
	}
	arr[32] = '\0';
	return (strdup(arr));
}

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
}

int		main(int argc, char const *argv[])
{
	long	number_1;
	long	number_2;
	int		base;

	(void)argc;
	(void)argv;
	char *str = ft_itoa(-7);
	printf("%s\n", str);
	printf("%s\n", ft_inversion_bin(str));
	// printf("Введите первое число в пределах int:");
	// scanf("%ld", &number_1);
	// printf("Введите второе число в пределах int: ");
	// scanf("%ld", &number_2);
	// printf("Введите систему счисления (2 или 16): ");
	// scanf("%d", &base);
	// ft_check_value(base, number_1, number_2);



	// printf("%ld\n", number_1);
	// printf("%ld\n", number_2);
	// printf("%d\n", base);
	return 0;
}
