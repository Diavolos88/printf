/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:17:59 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 19:09:31 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_tohex_other_x(t_param *params, int j, char *hex, char *buf)
{
	while (params->point)
	{
		buf[params->i++] = hex[params->point % 16];
		params->point /= 16;
	}
	while (--params->i != -1)
		params->buf_hex[j++] = buf[params->i];
	params->buf_hex[j] = '\0';
}

int		ft_print_hex_small(t_param *params)
{
	int		res;

	if (params->flag_minus == '-')
		params->flag = '-';
	ft_add_buffhex_small(params);
	params->digit = 1;
	params->length = ft_strlen(params->buf_hex);
	params->buffer = params->buf_hex;
	if (params->precision == 0 && params->point == 0)
		res = ft_print_digit_zero(params);
	else if (params->precision == -1)
		res = ft_print_digit_not_pris(params);
	else
		res = ft_print_digit_with_pris(params);
	return (res);
}

int		ft_print_hex_upper(t_param *params)
{
	int		res;

	if (params->flag_minus == '-')
		params->flag = '-';
	ft_add_buffhex_upper(params);
	params->length = ft_strlen(params->buf_hex);
	params->buffer = params->buf_hex;
	if (params->precision == 0 && params->point == 0)
		res = ft_print_digit_zero(params);
	else if (params->precision == -1)
		res = ft_print_digit_not_pris(params);
	else
		res = ft_print_digit_with_pris(params);
	return (res);
}
