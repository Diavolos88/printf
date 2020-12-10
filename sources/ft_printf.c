/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:49:45 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 19:44:57 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		param_init(t_param *params, char *s, va_list *ap)
{
	int		i;

	params->ap = ap;
	i = 0;
	ft_init_flag(params, s[i], &i);
	while (s[i] == '-' || s[i] == '0')
		params->flag = s[i++];
	if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '*')
		i += init_nums(params, (s + i));
	else
	{
		params->width = -1;
		params->precision = -1;
	}
	if (!(check_specifier(params, s[i++], "cspdiuxX%")))
		return (i);
	return (i + 1);
}

int		ft_printf_while(const char *format,
	t_param *params, int *res, va_list *ap)
{
	int		i;
	int		add;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if ((add = param_init(params, ((char*)(format + i + 1)), ap)) == -1)
				return (-1);
			i += add;
			(*res) += ft_print_arg(params);
			ft_bzero(params, sizeof(t_param));
		}
		else
		{
			(*res)++;
			write(1, &(format[i++]), 1);
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_param		*params;
	int			res;

	res = 0;
	if (!format)
		return (-1);
	if (!(params = malloc(sizeof(t_param))))
		return (-1);
	ft_bzero(params, sizeof(t_param));
	va_start(ap, format);
	ft_printf_while(format, params, &res, &ap);
	free(params);
	va_end(ap);
	return (res);
}
