/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_bin_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:42:18 by aberry            #+#    #+#             */
/*   Updated: 2021/02/13 03:13:33 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

void					ft_conversion_bin_elem_destructor(t_conversion_bin_elem *conversion_bin_elem)
{
	if (conversion_bin_elem)
	{
		ft_bin_elem_destructor(conversion_bin_elem->num);
		ft_bin_elem_destructor(conversion_bin_elem->inversion_num);
		free(conversion_bin_elem);
	}
	conversion_bin_elem = (t_conversion_bin_elem *)NULL;
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
