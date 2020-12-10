/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_for_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:14:07 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 18:05:08 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_t_min(t_param *params)
{
	return ((params->length > params->precision ?
		params->length : params->precision + 1));
}

int		ft_t_max(t_param *params)
{
	return ((params->length > params->precision ?
		params->length : params->precision));
}

int		ft_print_digit_not_pris(t_param *params)
{
	if (params->flag != '-')
	{
		if (params->digit < 0 && params->flag == '0')
			write(1, "-", 1);
		while (params->width > params->length)
		{
			write(1, &(params->flag), 1);
			params->length++;
		}
		ft_putstr_fd(params->digit >= 0 || params->flag != '0'
			? params->buffer : (params->buffer + 1), 1);
		return (params->length);
	}
	if (params->digit < 0 && params->flag == '0')
		write(1, "-", 1);
	ft_putstr_fd(params->digit >= 0 || params->flag != '0' ?
		params->buffer : (params->buffer + 1), 1);
	while (params->width > params->length)
	{
		write(1, " ", 1);
		params->length++;
	}
	return (params->length);
}

int		ft_print_digit_with_pris_min(t_param *params)
{
	params->i = 0;
	if (params->precision > params->width)
	{
		ft_write_minus(params);
		while (params->precision > (params->digit >= 0
			? params->length : params->length - 1))
			ft_write_zero(params);
		ft_putstr_fd(params->digit >= 0 ?
			params->buffer : (params->buffer + 1), 1);
		return (params->length);
	}
	ft_write_minus(params);
	while (params->precision > (params->digit >= 0
		? params->length : params->length - 1))
		ft_write_zero(params);
	ft_putstr_fd(params->digit >= 0 ? params->buffer : (params->buffer + 1), 1);
	while (params->width - params->i++ >
		(params->digit >= 0 ? ft_t_max(params) : ft_t_min(params)))
		write(1, " ", 1);
	return (params->length + params->i - 1);
}

int		ft_print_digit_with_pris(t_param *params)
{
	if (params->flag != '-')
	{
		if (params->precision > params->width)
		{
			ft_write_minus(params);
			while (params->precision > (params->digit >= 0
				? params->length : params->length - 1))
				ft_write_zero(params);
			ft_putstr_fd(params->digit >= 0
				? params->buffer : (params->buffer + 1), 1);
			return (params->length);
		}
		params->i = 0;
		while (params->width - params->i++ > (params->digit >= 0
			? ft_t_max(params) : ft_t_min(params)))
			write(1, " ", 1);
		ft_write_minus(params);
		while (params->precision > (params->digit >= 0
			? params->length : params->length - 1))
			ft_write_zero(params);
		ft_putstr_fd(params->digit >= 0
			? params->buffer : (params->buffer + 1), 1);
		return (params->length + params->i - 1);
	}
	return (ft_print_digit_with_pris_min(params));
}
