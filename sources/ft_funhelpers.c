/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funhelpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:18:56 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 16:38:33 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_write_zero(t_param *params)
{
	write(1, "0", 1);
	params->length++;
}

void	ft_write_minus(t_param *params)
{
	if (params->digit < 0)
		write(1, "-", 1);
}

void	ft_add_buffhex_small(t_param *params)
{
	char	buf[100];
	char	*hex;
	int		j;

	hex = "0123456789abcdef";
	j = 0;
	if (!(params->point = va_arg(*params->ap, unsigned int)))
	{
		params->buf_hex[0] = '0';
		params->buf_hex[1] = '\0';
	}
	else
		ft_tohex_other_x(params, j, hex, buf);
}

void	ft_add_buffhex_upper(t_param *params)
{
	char	buf[100];
	char	*hex;
	int		j;

	j = 0;
	hex = "0123456789ABCDEF";
	params->digit = 1;
	if (!(params->point = va_arg(*params->ap, unsigned int)))
	{
		params->buf_hex[0] = '0';
		params->buf_hex[1] = '\0';
	}
	else
		ft_tohex_other_x(params, j, hex, buf);
}
