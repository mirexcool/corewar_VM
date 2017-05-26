/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:08:57 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/15 21:27:25 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_ceil(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr <= i)
		return (i);
	return (i + 1);
}

long double	ft_floor(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr >= i)
		return (i);
	return (i - 1);
}

long double	ft_r_nbr(long double nbr)
{
	if (nbr - ft_floor(nbr) == 0.5 && (long long)ft_floor(nbr) % 2 == 0)
		return (ft_floor(nbr));
	else if (ft_ceil(nbr) - nbr == 0.5)
		return (ft_ceil(nbr));
	return ((nbr - ft_floor(nbr) >= 0.5 ? ft_ceil(nbr) : ft_floor(nbr)));
}

char		*ft_round(long double nbr, t_arg *head, char *str)
{
	int			i;
	int			p;

	p = head->precision;
	while (p > 0)
	{
		nbr *= 10;
		if (p == 1)
			nbr = ft_r_nbr(nbr);
		i = (int)nbr;
		*str = i + '0';
		nbr = nbr - i;
		p--;
		str++;
	}
	return (str);
}

void		ft_round_d(long double nbr, t_arg *head, char *str)
{
	int			p;
	long long	nbr_l;

	p = head->precision;
	while (p > 0)
	{
		nbr *= 10;
		p--;
	}
	nbr_l = ft_r_nbr(nbr);
	p = head->precision - ft_nbrlen_base(nbr_l, 10);
	while (p > 0)
	{
		*str = '0';
		str++;
		p--;
	}
	nbr_to_str(nbr_l, 10, &str, 0);
}
