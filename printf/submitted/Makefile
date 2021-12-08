NAME	=	libftprintf.a

CFILES	=	ft_printf.c \
			ft_print_cs.c \
			ft_print_pdiux.c \
			ft_printf_utils.c \
			ft_printf_struct.c \
			ft_padding.c \
			ft_parsing.c
#			ft_printf.c \
#			ft_printf_utils.c \
#			ft_printf_utils2.c

SRC_DIR	=	src

SRCS	=	${addprefix ${SRC_DIR}/, ${CFILES}}
#OBJS	=	${SRCS:.c=.o}

OBJ_DIR	=	obj

OBJS	=	${addprefix ${OBJ_DIR}/, ${CFILES:.c=.o}}

H_DIR	=	incl

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar

ARFLAGS	=	rcs

RM		=	rm -f

#.c.o:
#	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${H_DIR}/ft_printf.h
	@mkdir -p obj
	${CC} ${CFLAGS} -I${H_DIR} -o $@ -c $<

all:	${NAME}

libft: 
		${MAKE} -C ./libft
		cp ./libft/libft.a ${NAME}

#NOTE : cd is relative in Makefile and will return to main root folder 

${NAME}:	libft ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS} 

clean:	
	${RM} ${OBJS}
	${RM} -r ${OBJ_DIR}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

bonus:	all

.PHONY: all clean fclean re bonus libft

#to add:
#Directories for srcs and for .o