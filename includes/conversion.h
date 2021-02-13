/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 21:20:07 by aberry            #+#    #+#             */
/*   Updated: 2021/02/13 03:21:26 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

# define BIN "01"
# define HEX "0123456789ABCDEF"
# define ONE_POS "00000000000000000000000000000001"
# define ONE_NEG "11111111111111111111111111111111"

typedef struct			s_bin_elem
{	
	long				origin_number;
	char				*unsigned_bin;
	char				*direct_code_bin;
	char				*inverse_bin;
	char				*complement_bin;
}						t_bin_elem;

typedef struct			s_conversion_bin_elem
{	
	t_bin_elem			*num;
	t_bin_elem			*inversion_num;
}						t_conversion_bin_elem;

typedef struct			s_conversion_bin
{	
	t_bin_elem			*sum;
	t_bin_elem			*first_difference;
	t_bin_elem			*second_difference;
}						t_conversion_bin;

typedef struct			s_hex_elem
{	
	long				origin_number;
	char				*direct_code_hex;
	char				*unsigned_hex;
	char				*str_hex;
}						t_hex_elem;

typedef struct			s_conversion_hex_elem
{	
	t_hex_elem			*num;
	t_hex_elem			*inversion_num;
}						t_conversion_hex_elem;

typedef struct			s_conversion_hex
{	
	char				*sum;
	char				*first_difference;
	char				*second_difference;
}						t_conversion_hex;

char					*ft_create_str_hex(char *str);
char					*ft_strjoin(char const *str_1, char const *str_2);
char					*ft_itoa_base(long num, int base, char *alpha);
int						ft_choose_sign(int first, int second);

char					*ft_create_str_hex(char *str);
char					*ft_sum_hex(t_conversion_hex_elem *first_elem, t_conversion_hex_elem *second_elem);
char					*ft_addition(char *first_term, char *second_term, int base, char *alpha);
char					*ft_difference_hex(char *first_term, char *second_term, char *alpha);


char					*ft_inversion_bin(char *bin);
t_bin_elem				*ft_bin_new(long number);
void					ft_bin_elem_destructor(t_bin_elem *bin_elem);

t_conversion_bin_elem	*ft_conversion_bin_elem_new(long number);
void					ft_conversion_bin_destructor(t_conversion_bin *conversion_bin);

t_conversion_bin		*ft_conversion_bin_new(t_conversion_bin_elem *first_elem, t_conversion_bin_elem	*second_elem);
void					ft_conversion_bin_elem_destructor(t_conversion_bin_elem *conversion_bin_elem);

t_hex_elem				*ft_hex_elem_new(long number);
void					ft_hex_elem_destructor(t_hex_elem *hex_elem);

t_conversion_hex_elem	*ft_conversion_hex_elem_new(long number);
void					ft_conversion_hex_elem_destructor(t_conversion_hex_elem *conversion_hex_elem);

t_conversion_hex		*ft_conversion_hex_new(t_conversion_hex_elem *first_elem, t_conversion_hex_elem *second_elem);
void					ft_conversion_hex_destructor(t_conversion_hex *conversion_hex);

void					ft_conversion_decimal_to_hex(int number_1, int number_2);

void					ft_conversion_decimal_to_bin(int number_1, int number_2);
#endif
