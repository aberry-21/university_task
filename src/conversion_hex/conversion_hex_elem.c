/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_hex_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:48:13 by aberry            #+#    #+#             */
/*   Updated: 2021/02/12 23:05:53 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

void					ft_conversion_hex_elem_destructor(t_conversion_hex_elem *conversion_hex_elem)
{
	if(conversion_hex_elem)
	{
		ft_hex_elem_destructor(conversion_hex_elem->inversion_num);
		ft_hex_elem_destructor(conversion_hex_elem->num);
	}
	conversion_hex_elem = (t_conversion_hex_elem *)NULL;
}

t_conversion_hex_elem	*ft_conversion_hex_elem_new(long number)
{
	t_conversion_hex_elem		*conversion_hex_elem;

	if (!(conversion_hex_elem = (t_conversion_hex_elem *)malloc(sizeof(t_conversion_hex_elem))))
		exit (1);
	conversion_hex_elem->num = ft_hex_elem_new(number);
	conversion_hex_elem->inversion_num = ft_hex_elem_new(-number);
	return (conversion_hex_elem);
}
