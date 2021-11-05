NAME	=	libftprintf.a

SRCS	=	ft_printf_bonus.c \
			ft_printf_print_dev.c \
			ft_printf_utils_bonus.c
#			ft_printf.c \
#			ft_printf_utils.c \
#			ft_printf_utils2.c

SRCS_B	=	ft_printf_bonus.c \
			ft_printf_print_dev.c \
			ft_printf_utils_bonus.c

OBJS	=	${SRCS:.c=.o}

OBJS_B	=	${SRCS_B:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I.

AR		=	ar

ARFLAGS	=	rcs

#LDFLAGS	=	-lft

RM		=	rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

all:	${NAME}

libft: 
#		${MAKE} -C ../libft re &&
		cd ./libft && make
		mv ./libft/libft.a ${NAME}

#NOTE : cd is relative in Makefile and will return to main root folder 

${NAME}:	libft ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS} 

clean:	
	${RM} ${OBJS} ${OBJS_B}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

bonus:	libft ${OBJS} ${OBJS_B}
	${AR} ${ARFLAGS} ${NAME} ${OBJS_B}

.PHONY: all clean fclean re bonus libft

#to add:
#Directories for srcs and for .o