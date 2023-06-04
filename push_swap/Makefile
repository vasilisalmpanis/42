NAME	=	push_swap
SRC		=	push_swap.c error_handling.c s_list.c s_list_aux.c s_list_utils.c\
			push_swap_utils.c ft_argcount.c swap_commands.c rotate_commands.c rrotate_commands.c\
			push_commands.c finishing_funcs.c
LIBFT	=	./LIBFT
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