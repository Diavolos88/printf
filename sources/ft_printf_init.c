/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:33:12 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 19:44:10 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init_flag(t_param *params, char c, int *i)
{
	if (c == '-' || c == '0' || c == ' ')
	{
		if (c == ' ')
			params->flag_empty = '1';
		if (c == '-')
			params->flag_minus = c;
		params->flag_char = c;
		params->flag = c;
		(*i)++;
	}
	else
	{
		params->flag = ' ';
		params->flag_char = ' ';
	}
}

int		check_specifier(t_param *params, char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
		{
			params->specifier = c;
			return (1);
		}
	params->specifier = c;
	return (0);
}

int		init_nums(t_param *params, char *s)
{
	char	buff[100];
	int		i;
	int		j;

	init_nums_width(params, &i, &j, s[0]);
	while ((s[i] >= '0' && s[i] <= '9'))
		buff[j++] = s[i++];
	buff[j] = '\0';
	if (j == 0 && params->width == 0)
		params->width = ft_atoi("-1");
	else if (j != 0)
		params->width = ft_atoi(buff);
	if (s[i] == '.')
		init_nums_prec(s, params, &i, buff);
	else
		params->precision = ft_atoi("-1");
	return (i);
}

void	init_nums_width(t_param *params, int *i, int *j, char c)
{
	*i = 0;
	*j = 0;
	if (c == '*')
	{
		if ((params->width = va_arg(*(params->ap), int)) < 0)
		{
			params->flag_char = '-';
			params->flag = '-';
			params->width = -params->width;
		}
		(*i)++;
	}
}

void	init_nums_prec(char *s, t_param *params, int *i, char *buff)
{
	int	j;

	j = 0;
	if (s[++(*i)] == '*')
	{
		if ((params->precision = va_arg(*(params->ap), int)) < 0)
			params->precision = -1;
		(*i)++;
	}
	while (s[*i] >= '0' && s[*i] <= '9')
		buff[j++] = s[(*i)++];
	buff[j] = '\0';
	if (j == 0 && params->precision == 0)
		params->precision = ft_atoi("0");
	else if (j != 0)
		params->precision = ft_atoi(buff);
}
