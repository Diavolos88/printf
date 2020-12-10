/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:27:47 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 18:22:16 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_print_digit_zero(t_param *params)
{
	if (params->width != -1)
		while (params->width >= params->length)
		{
			write(1, " ", 1);
			params->length++;
		}
	return (params->length - 1);
}

int		ft_print_digit(t_param *params)
{
	int	res;

	if (params->flag_minus == '-')
		params->flag = '-';
	params->digit = va_arg(*params->ap, int);
	params->buffer = ft_itoa(params->digit);
	params->length = ft_strlen(params->buffer);
	if (params->flag_empty == '1')
		params->width = params->length > params->precision
			? params->length + 1 : params->precision + 1;
	if (params->precision == 0 && params->digit == 0)
		res = ft_print_digit_zero(params);
	else if (params->precision == -1)
		res = ft_print_digit_not_pris(params);
	else
		res = ft_print_digit_with_pris(params);
	free(params->buffer);
	return (res);
}

size_t	ft_itoa_size_2(unsigned long n, unsigned long int *num)
{
	size_t	res;
	long	tmp_n;

	res = 0;
	if (n < 0)
	{
		*num = n * (-1);
		res++;
		tmp_n = n * (-1);
	}
	else
	{
		*num = n;
		tmp_n = n;
	}
	while (tmp_n != 0)
	{
		tmp_n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa_long(unsigned long n)
{
	unsigned long int	tmp_n;
	size_t				i;
	char				*res;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_itoa_size_2(n, &tmp_n);
	res = malloc(sizeof(char) * (i + 1));
	if (res != NULL)
	{
		res[i] = '\0';
		while (tmp_n != 0)
		{
			res[--i] = ((tmp_n % 10) + '0');
			tmp_n = tmp_n / 10;
		}
		if (i != 0)
			res[0] = '-';
	}
	return (res);
}

int		ft_print_unsigned(t_param *params)
{
	int res;

	if (params->flag_minus == '-')
		params->flag = '-';
	params->digit = va_arg(*params->ap, unsigned int);
	params->buffer = ft_itoa_long(params->digit);
	params->length = ft_strlen(params->buffer);
	if (params->precision == 0 && params->digit == 0)
		res = ft_print_digit_zero(params);
	else if (params->precision == -1)
		res = ft_print_digit_not_pris(params);
	else
		res = ft_print_digit_with_pris(params);
	free(params->buffer);
	return (res);
}
