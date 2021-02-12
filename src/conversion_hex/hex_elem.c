/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:45:24 by aberry            #+#    #+#             */
/*   Updated: 2021/02/12 22:48:00 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

void			ft_hex_elem_destructor(t_hex_elem *hex_elem)
{
	if (hex_elem)
	{
		free(hex_elem->direct_code_hex);
		free(hex_elem->unsigned_hex);
		free(hex_elem->str_hex);
	}
	hex_elem = (t_hex_elem *)NULL;
}

t_hex_elem		*ft_hex_elem_new(long number)
{
	t_hex_elem		*hex_elem;
	char			*tmp;

	if (!(hex_elem = (t_hex_elem *)malloc(sizeof(t_hex_elem))))
		exit (1);
	hex_elem->origin_number = number;
	hex_elem->direct_code_hex = ft_itoa_base(number, 16, HEX);
	hex_elem->unsigned_hex = ft_itoa_base(labs(number), 16, HEX);
	hex_elem->str_hex = ft_create_str_hex(hex_elem->direct_code_hex);
	return (hex_elem);
}
