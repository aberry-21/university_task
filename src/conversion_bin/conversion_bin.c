/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:27:24 by aberry            #+#    #+#             */
/*   Updated: 2021/02/12 22:42:35 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "conversion.h"

static t_bin_elem		*ft_create_conversion_bin_content(char *first_elem, char *second_elem)
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

void					ft_conversion_bin_destructor(t_conversion_bin *conversion_bin)
{
	if (conversion_bin)
	{
		ft_bin_elem_destructor(conversion_bin->first_difference);
		ft_bin_elem_destructor(conversion_bin->second_difference);
		ft_bin_elem_destructor(conversion_bin->sum);
	}
	conversion_bin = (t_conversion_bin *)NULL;
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
