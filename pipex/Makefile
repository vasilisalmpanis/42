NAME    =   pipex
SRC     =   mandatory/main.c mandatory/utils.c mandatory/errors.c mandatory/execute.c\

BSRC	=	bonus/main.c bonus/execute.c bonus/checking.c bonus/utils.c bonus/errors.c\

LIBFT   =   ./libft
BLIBFT   =   ./libft
RM      =   rm -rf
CC      =   gcc
CFLAGS  =   -g -Wall -Wextra -Werror

OBJ     =   $(SRC:.c=.o)
BOBJ	=	${BSRC:.c=.o}
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: norm ${LIBFT} ${NAME}

${NAME}: ${OBJ} ${LIBFT}
		@echo "${RED}------PIPEX------${END}"
		${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME} libft.a
		${RM} libft.a
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

bonus: ${BOBJ} ${LIBFT}
		@echo "${RED}----PIPEX BONUS----${END}"
		${CXX} ${CXXFLAGS} ${BOBJ} -o ${NAME} libft.a
		${RM} libft.a
		@echo "${RED}----COMPLETED----${END}"

clean:
		@echo "${RED}----CLEAN----${END}"
		make clean -C libft
		${RM} mandatory/libft.a
		${RM} ${OBJ}
		@echo "${RED}----COMPLETED----${END}"

bclean:
		@echo "${RED}----BCLEAN----${END}"
		make clean -C libft
		${RM} bonus/libft.a
		${RM} ${BOBJ}
		@echo "${RED}----COMPLETED----${END}"

fclean: clean
		@echo "${RED}----FCLEAN----${END}"
		${RM} ${NAME}
		make fclean -C libft
		@echo "${RED}----COMPLETED----${END}"

bfclean: bclean
		@echo "${RED}----BFCLEAN----${END}"
		${RM} ${NAME}
		make fclean -C libft
		@echo "${RED}----COMPLETED----${END}"

re: fclean all

.PHONY: all clean fclean re ${LIBFT} ${BLIBFT}
