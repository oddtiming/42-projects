
#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
//TO REMOVE
# include <limits.h>
# include <stdio.h>

# define CONVERSIONS "cspdiuxX%"
# define FLAGS "-0.# +"

typedef struct s_arg
{
	char			*format;
	int				index;
	int				n_bytes;
	int				width;
	int				precision;
	char			var_type;
	unsigned int	flags;
}	t_arg;

typedef enum e_flags
{
	FLAG_MINUS = 0x1,
	FLAG_ZERO = 0x2,
	FLAG_PREC = 0x4,
	FLAG_HASH = 0x8,
	FLAG_SPACE = 0x10,
	FLAG_PLUS = 0x20,
	FLAG_WIDTH = 0x40
}	t_flags;

char	*c_to_s(int c);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_hextoa_int(unsigned int n, char c);
char	*ft_strjoin_dbfree(char *s1, char *s2);
int		ft_printf(const char *format, ...);
//char	*ft_strjoin_free(char *s1, char const *s2);
//size_t	ft_strlen(const char *s);
//size_t	strlen_c(char *s, char c);
int		ft_printf_bonus(const char *format, ...);
void	printf_struct_init(t_arg *arg, char const *format);
int		ft_putchar_ret(const char c);
int		ft_putstr_ret(const char *s);
int		ft_putnbr_ret(int n);
int		ft_putnbr_unsigned_ret(unsigned int n);
//int		ft_putaddress_ret(unsigned long address);
void	ft_puthex_long(long i, t_arg *arg);
void	ft_puthex_long_long(long long i, t_arg *arg);
void	ft_puthex_size_t(size_t i, t_arg *arg);
void	ft_puthex_int(unsigned int i, t_arg *arg);
void	ft_puthex_upperx_int(unsigned int i, t_arg *arg);
//int		is_set_ret(char const c, char const *set);
int		get_magnitude(int n);
//int		ft_log_calc(int value, int radix);
void	arg_parse(t_arg *arg, va_list ap);
void	arg_parse_dev(t_arg *arg);
void	ft_printf_char(t_arg *arg, va_list ap);
void	ft_printf_str(t_arg *arg, va_list ap);

//NEW FUNCTIONS
int	ft_putstr_n_ret(const char *s, int prec);
int	ft_putnbr_n_ret(int nbr, int prec);
int	ft_putnbr_unsigned_n_ret(unsigned int n, int prec);

//Functions to add:
void	ft_printf_nbr(t_arg *arg, va_list ap);
void	ft_printf_u_nbr(t_arg *arg, va_list ap);
void	ft_printf_addr(t_arg *arg, va_list ap);
void	ft_printf_hex(t_arg *arg, va_list ap);

//DEV FUNCTIONS
void	ft_printf_char_dev(t_arg *arg, char c);
void	ft_printf_str_dev(t_arg *arg, char *arg_to_str);
void	ft_printf_nbr_dev(t_arg *arg, int nbr);
void	ft_printf_u_nbr_dev(t_arg *arg, unsigned int nbr);
void	ft_printf_hex_dev(t_arg *arg, int nbr);
void	ft_printf_addr_dev(t_arg *arg, size_t addr);
const char *byte_to_binary(int x);

#endif