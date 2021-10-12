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

char	*c_to_s(int c);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_hextoa_int(unsigned int n, char c);
char	*ft_strjoin_dbfree(char *s1, char *s2);
int		ft_printf(const char *format, ...);
//char	*ft_strjoin_free(char *s1, char const *s2);
//size_t	ft_strlen(const char *s);
//size_t	strlen_c(char *s, char c);
int		ft_printf_bonus(const char *format, ...);

#endif