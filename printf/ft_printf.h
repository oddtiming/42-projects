#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_arg
{
	char	*format;
	int		index;
	int		n_bytes;
	int		width;
	int		precision;
	char	var_type;
} t_arg;

//static const char *g_flags = {"+.0 #-"}

char	*c_to_s(int c);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_hextoa_int(unsigned int n, char c);
char	*ft_strjoin_dbfree(char *s1, char *s2);
int		ft_printf(const char *format, ...);
//char	*ft_strjoin_free(char *s1, char const *s2);
//size_t	ft_strlen(const char *s);
//size_t	strlen_c(char *s, char c);
int		ft_printf_bonus(const char *format, ...);
void	printf_struct_init(t_arg *holder, char const *format);
int		ft_putchar_ret(const char c);
int		ft_putstr_ret(const char *s);
int		ft_putnbr_ret(int n);
int		ft_putnbr_unsigned_ret(unsigned int n);
int		ft_putaddress_ret(unsigned long address);
void	ft_puthex_long(long i, t_arg *holder);
void	ft_puthex_long_long(long long i, t_arg *holder);
void	ft_puthex_size_t(size_t i, t_arg *holder);
void	ft_puthex_int(unsigned int i, t_arg *holder);
void	ft_puthex_upperx_int(unsigned int i, t_arg *holder);

#endif