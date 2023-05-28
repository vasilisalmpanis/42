NAME	=	libftprintf.a
SRC		=	ft_printf.c ft_utilities.c ft_auxiliary.c\

LIBFT	=	./LIBFT
OBJ		=	${SRC:.c=.o}
LIBC	=	ar	-rc
RM		=	rm -rf
INCS	=	"ft_printf.h"
CC		=	gcc
CFLAGS	=	-g	-Wall -Wextra -Werror 

all : ${LIBFT} ${NAME}

${NAME} : ${OBJ}
		cp libft/libft.a .
		mv libft.a ${NAME}
		${LIBC} ${NAME} ${OBJ}

${OBJ}	:
		${CC} ${CFLAGS} -c ${SRC}

${LIBFT}:
		${MAKE} -C $@

clean :
		${RM} ${OBJ}
		${MAKE} clean -C libft

fclean : clean
		${RM} ${NAME}
		${MAKE} fclean -C libft
		
re :	fclean all

.PHONY: all clean fclean re ${LIBFT}