/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealexa <ealexa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:02:36 by ealexa            #+#    #+#             */
/*   Updated: 2020/11/15 19:36:22 by ealexa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct			s_param
{
	long long int		unsigned_int;
	long long int		digit;
	long long int		point;
	char				specifier;
	char				flag;
	char				flag_empty;
	char				flag_minus;
	char				flag_char;
	int					width;
	int					i;
	int					precision;
	int					length;
	char				upper_sym;
	char				*buffer;
	char				buf_hex[100];
	va_list				*ap;
	char				buf_char;
}						t_param;

int						init_nums(t_param *params, char *s);
int						check_specifier(t_param *params, char c, char *str);
void					ft_init_flag(t_param *params, char c, int *i);
void					ft_add_buffhex_upper(t_param *params);
void					ft_tohex_other_x(t_param *params,
	int j, char *hex, char *buf);
void					ft_add_buffhex_small(t_param *params);
void					ft_write_minus(t_param *params);
void					ft_write_zero(t_param *params);
int						ft_print_hex_upper(t_param *params);
int						ft_print_digit_zero(t_param *params);
int						ft_print_digit_with_pris_min(t_param *params);
int						ft_print_digit_not_pris(t_param *params);
int						ft_print_digit_with_pris(t_param *params);
char					*ft_itoa_long(unsigned long n);
void					ft_tohex_other(t_param *params,
	int j, char *hex, char *buf);
int						ft_print_hex_small(t_param *params);
int						ft_print_unsigned(t_param *params);
int						ft_print_digit(t_param *params);
int						ft_print_pointer(t_param *params);
int						ft_print_arg(t_param *params);
int						ft_printf(const char *format, ...);
int						ft_print_char(t_param *params);
int						ft_print_char_proc(t_param *params);
int						ft_print_string_with_prec_min(t_param *params);
int						ft_print_string_with_prec(t_param *params);
int						ft_print_string(t_param *params);
int						ft_t_min(t_param *params);
int						ft_t_max(t_param *params);
int						ft_print_digit_not_pris(t_param *params);
int						ft_print_digit_with_pris_min(t_param *params);
void					ft_init_flag(t_param *params, char c, int *i);
void					init_nums_width(t_param *params,
	int *i, int *j, char c);
void					init_nums_prec(char *s,
	t_param *params, int *i, char *buff);
int						ft_print_digit_with_pris(t_param *params);

#endif
