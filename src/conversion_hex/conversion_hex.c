/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:43:22 by aberry            #+#    #+#             */
/*   Updated: 2021/02/13 03:13:42 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

static char			*ft_create_conversion_hex_content(t_hex_elem *first_elem, t_hex_elem *second_elem, int num_1, int num_2)
{
	char		*add;
	char		*tmp;

	if (num_1 < 0 && num_2 < 0)
	{
		add = ft_addition(first_elem->direct_code_hex, second_elem->direct_code_hex, 16, HEX);
		add[0] = '1';
	}
	else if (num_1 < 0 || num_2 < 0)
	{
		if (labs(first_elem->origin_number) > labs(second_elem->origin_number))
			add = ft_difference_hex(first_elem->unsigned_hex, second_elem->unsigned_hex, HEX);
		else
			add = ft_difference_hex(second_elem->unsigned_hex, first_elem->unsigned_hex, HEX);
		if(ft_choose_sign(first_elem->origin_number, second_elem->origin_number))
			add[0] = '1';
	}
	else
		add = ft_addition(first_elem->direct_code_hex, second_elem->direct_code_hex, 16, HEX);
	tmp = add;
	add = ft_create_str_hex(add);
	free(tmp);
	return(add);
}

void					ft_conversion_hex_destructor(t_conversion_hex *conversion_hex)
{
	if (conversion_hex)
	{
		free(conversion_hex->first_difference);
		free(conversion_hex->second_difference);
		free(conversion_hex->sum);
		free(conversion_hex);
	}
	conversion_hex = (t_conversion_hex *)NULL;
}

t_conversion_hex		*ft_conversion_hex_new(t_conversion_hex_elem *first_elem, t_conversion_hex_elem *second_elem)
{
	t_conversion_hex		*conversion_hex;

	if (!(conversion_hex = (t_conversion_hex *)malloc(sizeof(t_conversion_hex))))
		exit (1);
	conversion_hex->sum = ft_create_conversion_hex_content(first_elem->num, second_elem->num, first_elem->num->origin_number, second_elem->num->origin_number);
	conversion_hex->first_difference = ft_create_conversion_hex_content(first_elem->num, second_elem->inversion_num, first_elem->num->origin_number, -second_elem->num->origin_number);
	conversion_hex->second_difference = ft_create_conversion_hex_content(first_elem->inversion_num, second_elem->num, -first_elem->num->origin_number, second_elem->num->origin_number);
	return (conversion_hex);
}