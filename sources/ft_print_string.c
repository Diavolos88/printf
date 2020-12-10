/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:08:21 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 15:32:56 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_print_char(t_param *params)
{
	int		i;

	if (params->flag_char == '+')
		params->flag_char = ' ';
	params->buf_char = va_arg(*(params->ap), int);
	i = 0;
	if (params->flag_char != '-')
	{
		while (i < params->width - 1)
		{
			write(1, &(params->flag_char), 1);
			i++;
		}
		write(1, &params->buf_char, 1);
	}
	else
	{
		write(1, &params->buf_char, 1);
		while (i < params->width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i + 1);
}

int		ft_print_char_proc(t_param *params)
{
	int		i;

	if (params->flag_char == '+')
		params->flag_char = ' ';
	params->buf_char = '%';
	i = 0;
	if (params->flag_char != '-')
	{
		while (i < params->width - 1)
		{
			write(1, &(params->flag_char), 1);
			i++;
		}
		write(1, &params->buf_char, 1);
	}
	else
	{
		write(1, &params->buf_char, 1);
		while (i < params->width - 1)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i + 1);
}

int		ft_print_string_with_prec_min(t_param *params)
{
	params->flag_char = ' ';
	if (params->precision < params->length)
	{
		write(1, params->buffer, params->precision);
		while (params->precision + params->i < params->width)
		{
			write(1, &(params->flag_char), 1);
			params->i++;
		}
		return (params->precision + params->i);
	}
	ft_putstr_fd(params->buffer, 1);
	while (params->length < params->width)
	{
		write(1, &(params->flag_char), 1);
		params->length++;
	}
	return (params->length);
}

int		ft_print_string_with_prec(t_param *params)
{
	if (params->precision == 0)
		write(1, 0, 1);
	if (params->flag_char != '-')
	{
		if (params->precision < params->length)
		{
			while (params->precision + params->i < params->width)
			{
				write(1, &(params->flag_char), 1);
				params->i++;
			}
			write(1, params->buffer, params->precision);
			return (params->precision + params->i);
		}
		while (params->length < params->width)
		{
			write(1, &(params->flag_char), 1);
			params->length++;
		}
		ft_putstr_fd(params->buffer, 1);
		return (params->length);
	}
	return (ft_print_string_with_prec_min(params));
}

int		ft_print_string(t_param *params)
{
	if (!(params->buffer = va_arg(*(params->ap), char*)))
		params->buffer = "(null)";
	params->length = ft_strlen(params->buffer);
	if (params->precision != -1)
		return (ft_print_string_with_prec(params));
	if (params->flag_char != '-')
	{
		while (params->length < params->width)
		{
			write(1, &(params->flag_char), 1);
			params->length++;
		}
		ft_putstr_fd(params->buffer, 1);
	}
	else
	{
		ft_putstr_fd(params->buffer, 1);
		while (params->length < params->width)
		{
			write(1, " ", 1);
			params->length++;
		}
	}
	return (params->length);
}
