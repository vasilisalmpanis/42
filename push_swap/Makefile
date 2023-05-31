NAME	=	push_swap
SRC		=	push_swap.c error_handling.c s_list.c\

LIBFT	=	./LIBFT
LIBC	=	ar	-rc
RM		=	rm -rf
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g

all : ${LIBFT} ${NAME}

${NAME} : ${OBJ}
		cp libft/libft.a .
		${CC} ${CFLAGS} ${SRC} -o ${NAME} libft.a

${LIBFT}:
		make -C libft
clean :
		${MAKE} clean -C libft
		${RM} libft.a

fclean : clean
		${RM} ${NAME}
		${MAKE} fclean -C libft

re :	fclean all

.PHONY: all clean fclean re ${LIBFT}