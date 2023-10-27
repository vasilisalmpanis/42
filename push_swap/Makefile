NAME    =   push_swap
SRC     =   push_swap.c error_handling.c s_list.c s_list_aux.c s_list_utils.c \
			push_swap_utils.c ft_argcount.c swap_commands.c rotate_commands.c rrotate_commands.c \
			push_commands.c finishing_funcs.c is_sorted.c auxiliary.c
LIBFT   =   ./libft
RM      =   rm -rf
CC      =   gcc
CFLAGS  =   -Wall -Wextra -Werror

OBJ     =   $(SRC:.c=.o)
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: norm ${LIBFT} ${NAME}

${NAME}: ${OBJ} ${LIBFT}
		@echo "${RED}----PUSH SWAP----${END}"
		${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME} libft.a
		@echo "${RED}----COMPLETED----${END}"

${LIBFT}:
		@echo "${GREEN}----LIBFT----${END}"
		make -C libft
		cp ${LIBFT}/libft.a .
		@echo "${GREEN}----COMPLETED----${END}"
		@echo "\n\n\n\n"

%.o: %.c
		${CXX} ${CXXFLAGS} -c $< -o $@

norm :
		@echo "${BLUE}******************${END}"
		@echo "${BLUE}    NORMINETTE    ${END}"
		norminette
		@echo "${BLUE}----COMPLETED----\n\n\n\n${END}"

clean:
		@echo "${RED}----CLEAN----${END}"
		make clean -C libft
		${RM} libft.a
		${RM} ${OBJ}
		@echo "${RED}----COMPLETED----${END}"

fclean: clean
		@echo "${RED}----FCLEAN----${END}"
		${RM} ${NAME}
		make fclean -C libft
		@echo "${RED}----COMPLETED----${END}"

re: fclean all

.PHONY: all clean fclean re ${LIBFT}
