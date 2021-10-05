#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_arg
{
	int				arg_number;
	char			*output;
	char			*flags;
	struct s_arg	*next;
} t_arg;


//char	*ft_strjoin_free(char *s1, char const *s2);
//size_t	ft_strlen(const char *s);
//size_t	strlen_c(char *s, char c);

#endif