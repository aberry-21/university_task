/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:45:29 by olebedev          #+#    #+#             */
/*   Updated: 2021/02/11 00:22:26 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

# define BIN "01"
# define HEX "0123456789ABCDEF"
# define ONE_POS "00000000000000000000000000000001"
# define ONE_NEG "11111111111111111111111111111111"

typedef struct		s_bin_elem
{
	int				origin_number;
	char			*unsigned_bin;
	char			*direct_code_bin;
	char			*reverse_bin;
	char			*additional_bin;
}					t_bin_elem;

typedef struct		s_conversion_bin_elem
{
	t_bin_elem		*num;
	t_bin_elem		*inversion_num;
}					t_conversion_bin_elem;
typedef struct		s_conversion_bin
{
	t_bin_elem		*sum;
	t_bin_elem		*first_difference;
	t_bin_elem		*second_difference;
}					t_conversion_bin;


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

char	*ft_addition(char *first_term, char *second_term, int base, char *alpha)
{
	char	arr[32 + 1];
	int		counter;
	int		addition;
	int		remainder;

	counter = 0;
	bzero(arr, 33);
	while (first_term[counter] && second_term[counter])
	{
		addition = (first_term[counter] - '0') + (second_term[counter] - '0');
		if (addition >= 44)
		{
			addition -=14;
		}
		arr[counter] = addition + '0';
		counter++;
	}
	remainder = 0;
	counter--;
	while (counter > -1)
	{
		addition = alpha[((arr[counter] - '0' + remainder) % base)];
		remainder = ((arr[counter] - '0' + remainder) / base);
		arr[counter] = addition;
		counter--;
	}
	return (strdup(arr));
}

char	*ft_inversion_bin(char *bin)
{
	int			i;
	char		*inv_bin;

	i = -1;
	inv_bin = strdup(bin);
	while (bin[++i])
		inv_bin[i] = (bin[i] == '0') ? '1' : '0';
	return (inv_bin);
}

char	*ft_additional_code_bin(char *bin)
{
	char		*inv_bin;
	char		*tmp;

	tmp = ft_inversion_bin(bin);
	inv_bin = ft_addition(tmp, ONE_POS, 2, BIN);
	free(tmp);
	return (inv_bin);
}

char	*ft_itoa_base(long num, int base, char *alpha)
{
	char	arr[32 + 1];
	int		counter_arr;
	int		positive;

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
	printf("%s\n", arr);
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
	if (number_2 + number_1 > INT_MAX || number_2 - number_1 < INT_MIN)
		printf("Возможно переполнение при сложении или вычитании которое вызовет неопределенное поведение\n");
}

t_bin_elem		*ft_bin_new(long number)
{
	t_bin_elem		*bin_elem;
	char			*tmp;

	if (!(bin_elem = (t_bin_elem *)malloc(sizeof(t_bin_elem))))
		exit (1);
	bin_elem->origin_number = number;
	tmp = ft_itoa_base(number, 2, BIN);
	if (number > -1)
	{
		bin_elem->direct_code_bin = strdup(tmp);
		bin_elem->unsigned_bin = strdup(tmp);
		bin_elem->reverse_bin = strdup(tmp);
		bin_elem->additional_bin = strdup(tmp);
	}
	else
	{
		bin_elem->direct_code_bin = ft_itoa_base(number, 2, BIN);
		bin_elem->unsigned_bin = ft_itoa_base(labs(number), 2, BIN);
		bin_elem->reverse_bin = ft_inversion_bin(bin_elem->unsigned_bin);
		bin_elem->additional_bin = ft_additional_code_bin(bin_elem->unsigned_bin);
	}
	free(tmp);
	return (bin_elem);
}

t_conversion_bin_elem	*ft_conversion_bin_elem_new(long number)
{
	t_conversion_bin_elem		*conversion_bin_elem;

	if (!(conversion_bin_elem = (t_conversion_bin_elem *)malloc(sizeof(t_conversion_bin_elem))))
		exit (1);
	conversion_bin_elem->num = ft_bin_new(number);
	conversion_bin_elem->inversion_num = ft_bin_new(-number);
	return (conversion_bin_elem);
}


t_bin_elem		*ft_create_conversion_bin_content(char *first_elem, char *second_elem)
{
	t_bin_elem		*content;
	char			*direct_code;

	if (!(content = (t_bin_elem *)malloc(sizeof(t_bin_elem))))
		exit (1);
	content->additional_bin = ft_addition(first_elem, second_elem, 2, BIN);
	if (content->additional_bin[0] == '1')
	{
		content->reverse_bin = ft_addition(content->additional_bin, ONE_NEG, 2, BIN);
		content->direct_code_bin = ft_inversion_bin(content->reverse_bin);
		content->direct_code_bin[0] = '1';
	}
	else
	{
		content->reverse_bin = strdup(content->additional_bin);
		content->direct_code_bin = strdup(content->additional_bin);
	}
	return (content);
}

t_conversion_bin		*ft_conversion_bin_new(t_conversion_bin_elem *first_elem, t_conversion_bin_elem	*second_elem)
{
	t_conversion_bin		*conversion_bin;

	if (!(conversion_bin = (t_conversion_bin *)malloc(sizeof(t_conversion_bin))))
		exit (1);
	conversion_bin->sum = ft_create_conversion_bin_content(first_elem->num->additional_bin, second_elem->num->additional_bin);
	conversion_bin->first_difference = ft_create_conversion_bin_content(first_elem->num->additional_bin, second_elem->inversion_num->additional_bin);
	conversion_bin->second_difference = ft_create_conversion_bin_content(first_elem->inversion_num->additional_bin, second_elem->num->additional_bin);
	return (conversion_bin);
}

void	ft_print(char *name, t_bin_elem *content)
{
	printf("%s\n", name);
	printf("%s\n", content->additional_bin);
	printf("%s\n", content->reverse_bin);
	printf("%s\n", content->direct_code_bin);
}


int		ft_find_index(char ch, char *alpha)
{
	int		i;

	i = 0;
	while (alpha[i])
	{
		if (ch == alpha[i])
			return (i);
		i++;
	}
	return (0);
}

char	*ft_difference_hex(char *first_term, char *second_term, char *alpha)
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


typedef struct		s_hex_elem
{
	int				origin_number;
	char			*direct_code_hex;
	char			*unsigned_hex;
	char			*str_hex;
}					t_hex_elem;

typedef struct		s_conversion_hex_elem
{
	t_hex_elem		*num;
	t_hex_elem		*inversion_num;
}					t_conversion_hex_elem;



typedef struct		s_conversion_hex
{
	char			*sum;
	char			*first_difference;
	char			*second_difference;
}					t_conversion_hex;

char			*ft_createstr_hex(char *str)
{
	char	add[2];

	add[1] = '\0';
	add[0] = (str[0] == '1') ? '-' : '\0' ;
	str++;
	while (*str == '0')
		str++;
	return (ft_strjoin(add, str));
}

t_hex_elem		*ft_hex_new(long number)
{
	t_hex_elem		*hex_elem;
	char			*tmp;

	if (!(hex_elem = (t_hex_elem *)malloc(sizeof(t_hex_elem))))
		exit (1);
	hex_elem->origin_number = number;
	hex_elem->direct_code_hex = ft_itoa_base(number, 16, HEX);
	hex_elem->unsigned_hex = ft_itoa_base(labs(number), 16, HEX);
	hex_elem->str_hex = ft_createstr_hex(hex_elem->direct_code_hex);
	return (hex_elem);
}

t_conversion_hex_elem	*ft_conversion_hex_elem_new(long number)
{
	t_conversion_hex_elem		*conversion_hex_elem;

	if (!(conversion_hex_elem = (t_conversion_hex_elem *)malloc(sizeof(t_conversion_hex_elem))))
		exit (1);
	conversion_hex_elem->num = ft_hex_new(number);
	conversion_hex_elem->inversion_num = ft_hex_new(-number);
	return (conversion_hex_elem);
}

//доделать 
int						ft_choose_sign(int first, int second)
{
	int			flag;

	flag = 0;
	if (second < 0)
		flag = 1;
	// if (flag)
	// {
		if (second > first)
			return (flag);
		else
			return (!flag);
	// }
	// else
	// {

	// }
	
}

char					*ft_sum_hex(t_conversion_hex_elem *first_elem, t_conversion_hex_elem *second_elem)
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
		add = ft_difference_hex(first_elem->num->unsigned_hex, second_elem->num->unsigned_hex, HEX);
	}
	else
		add = ft_addition(first_elem->num->direct_code_hex, second_elem->num->direct_code_hex, 16, HEX);
	tmp = add;
	add = ft_createstr_hex(add);
	free(tmp);
	return(add);
}

t_conversion_hex		*ft_conversion_hex_new(t_conversion_hex_elem *first_elem, t_conversion_hex_elem *second_elem)
{
	t_conversion_hex		*conversion_hex;

	if (!(conversion_hex = (t_conversion_hex *)malloc(sizeof(t_conversion_hex))))
		exit (1);
	conversion_hex->sum = ft_sum_hex(first_elem, second_elem);
	printf("%s\n", conversion_hex->sum);
	return (conversion_hex);
}

int		main(int argc, char const *argv[])
{
	long				number_1;
	long				number_2;
	int					base;
	// t_conversion_bin_elem	*first_elem;
	// t_conversion_bin_elem	*second_elem;
	// t_conversion_bin		*conversion_bin;
	
	t_conversion_hex_elem	*first_elem;
	t_conversion_hex_elem	*second_elem;
	t_conversion_hex		*conversion_hex;

	// (void)argc;
	// (void)argv;
	printf("Введите первое число в пределах int:");
	scanf("%ld", &number_1);
	printf("Введите второе число в пределах int:");
	scanf("%ld", &number_2);
	// printf("Введите систему счисления (2 или 16): ");
	// scanf("%d", &base);
	// ft_check_value(base, number_1, number_2);
	// if (base == 2)
	// {
	// 	first_elem = ft_conversion_bin_elem_new(number_1, base);
	// 	second_elem = ft_conversion_bin_elem_new(number_2, base);
	// 	conversion_bin = ft_conversion_bin_new(first_elem, second_elem);
	// 	ft_print("SUM", conversion_bin->sum);
	// 	ft_print("FDIF", conversion_bin->first_difference);
	// 	ft_print("SDIF", conversion_bin->second_difference);
	// }

	// printf("%s\n", ft_addition(ft_itoa_base(255, 16, HEX), ft_itoa_base(255, 16, HEX), 16, HEX));
	// printf("%s\n", ft_create_dif(ft_itoa_base(306, 16, HEX), ft_itoa_base(255, 16, HEX), HEX));

		first_elem = ft_conversion_hex_elem_new(number_1);
		second_elem = ft_conversion_hex_elem_new(number_2);
		conversion_hex = ft_conversion_hex_new(first_elem, second_elem);


	// printf("%ld\n", number_1);
	// printf("%ld\n", number_2);
	return 0;
}