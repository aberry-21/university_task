/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:29:06 by aberry            #+#    #+#             */
/*   Updated: 2021/02/13 03:21:26 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

char		*ft_inversion_bin(char *bin)
{
	int			i;
	char		*inv_bin;

	i = -1;
	inv_bin = strdup(bin);
	while (bin[++i])
		inv_bin[i] = (bin[i] == '0') ? '1' : '0';
	return (inv_bin);
}

static char		*ft_complement_code_bin(char *bin)
{
	char		*inv_bin;
	char		*tmp;

	tmp = ft_inversion_bin(bin);
	inv_bin = ft_addition(tmp, ONE_POS, 2, BIN);
	free(tmp);
	return (inv_bin);
}

void			ft_bin_elem_destructor(t_bin_elem *bin_elem)
{
	if (bin_elem)
	{
		free(bin_elem->direct_code_bin);
		free(bin_elem->unsigned_bin);
		free(bin_elem->inverse_bin);
		free(bin_elem->complement_bin);
		free(bin_elem);
	}
	bin_elem = (t_bin_elem *)NULL;
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
		bin_elem->inverse_bin = strdup(tmp);
		bin_elem->complement_bin = strdup(tmp);
	}
	else
	{
		bin_elem->direct_code_bin = ft_itoa_base(number, 2, BIN);
		bin_elem->unsigned_bin = ft_itoa_base(labs(number), 2, BIN);
		bin_elem->inverse_bin = ft_inversion_bin(bin_elem->unsigned_bin);
		bin_elem->complement_bin = ft_complement_code_bin(bin_elem->unsigned_bin);
	}
	free(tmp);
	return (bin_elem);
}