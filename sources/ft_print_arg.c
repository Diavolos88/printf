/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:45:36 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 19:34:50 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_print_spaces(t_param *params)
{
	params->buffer = "";
	params->length = 1;
	if (params->precision != -1)
		return (ft_print_string_with_prec(params) - 1);
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
	return (params->length - 1);
}

int		ft_print_arg(t_param *params)
{
	if (params->specifier == 'c')
		return (ft_print_char(params));
	else if (params->specifier == 's')
		return (ft_print_string(params));
	else if (params->specifier == '%')
		return (ft_print_char_proc(params));
	else if (params->specifier == 'p')
		return (ft_print_pointer(params));
	else if (params->specifier == 'd' || params->specifier == 'i')
		return (ft_print_digit(params));
	else if (params->specifier == 'u')
		return (ft_print_unsigned(params));
	else if (params->specifier == 'x')
		return (ft_print_hex_small(params));
	else if (params->specifier == 'X')
		return (ft_print_hex_upper(params));
	else
		return (ft_print_spaces(params));
	return (0);
}
