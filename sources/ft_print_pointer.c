/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:18:04 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 19:16:09 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_tohex_null(t_param *params, int j)
{
	if (params->precision != 0)
	{
		if (params->precision == -1 && params->flag == '0')
			while (params->width-- > 3)
				params->buf_hex[j++] = '0';
		else
		{
			if (params->precision > params->width)
				while (params->precision > params->length + 1)
				{
					params->buf_hex[j++] = '0';
					params->length++;
				}
			else
				while (params->precision-- > params->length + 1)
				{
					params->buf_hex[j++] = '0';
					params->length++;
				}
		}
		params->buf_hex[j++] = '0';
		params->buf_hex[j] = '\0';
	}
}

void	ft_tohex_other(t_param *params, int j, char *hex, char *buf)
{
	while (params->point)
	{
		buf[params->i++] = hex[params->point % 16];
		params->point /= 16;
	}
	if (params->precision == -1 && params->flag == '0')
		while (params->width > params->i + params->length + 2)
		{
			params->buf_hex[j++] = '0';
			params->length++;
		}
	else
	{
		if (params->precision > params->width && params->flag == '0')
			while (params->precision - params->width >
				params->i + params->digit++)
				params->buf_hex[j++] = '0';
		else
			while (params->precision > params->i + params->digit++)
				params->buf_hex[j++] = '0';
	}
	while (--params->i != -1)
		params->buf_hex[j++] = buf[params->i];
	params->buf_hex[j] = '\0';
}

void	ft_tohex(t_param *params)
{
	char	buf[100];
	char	*hex;
	int		j;

	j = 2;
	params->buf_hex[0] = '0';
	params->buf_hex[1] = 'x';
	hex = "0123456789abcdef";
	if (params->point == 0)
		ft_tohex_null(params, j);
	else
		ft_tohex_other(params, j, hex, buf);
}

int		ft_print_pointer(t_param *params)
{
	params->point = va_arg(*params->ap, long long int);
	ft_tohex(params);
	params->length = ft_strlen(params->buf_hex);
	if (params->flag == '0')
		params->flag = ' ';
	if (params->flag != '-')
	{
		while (params->length < params->width)
		{
			write(1, &(params->flag), 1);
			params->length++;
		}
		ft_putstr_fd(params->buf_hex, 1);
	}
	else
	{
		ft_putstr_fd(params->buf_hex, 1);
		while (params->length < params->width)
		{
			write(1, " ", 1);
			params->length++;
		}
	}
	return (params->length);
}
