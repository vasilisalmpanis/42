NAME    =   fractol
SRC     =   mandatory/main.c\
			mandatory/calculations.c\
			mandatory/draw.c\
			mandatory/errors.c\
			mandatory/initialize.c\
			mandatory/colours.c\
			mandatory/mouse_hooks.c\


LIBFT   =   ./libft
RM      =   rm -rf
CC      =   gcc
CFLAGS  =   -g -Wall

OBJ     =   $(SRC:.c=.o)
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

all: norm ${LIBFT} ${NAME}

${NAME}: ${OBJ} ${LIBFT}
		@echo "${RED}------FRACTOL------${END}"
		make -C mlx
		$(CC) ${CFLAGS} $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a
		${RM} libft.a
		@echo "${RED}----COMPLETED----${END}"

${LIBFT}:
		@echo "${GREEN}----LIBFT----${END}"
		make -C libft
		cp ${LIBFT}/libft.a .
		@echo "${GREEN}----COMPLETED----${END}"
		@echo "\n\n\n\n"

%.o: %.c
		${CC} ${CFLAGS} -Imlx -c $< -o $@

norm :
		@echo "${BLUE}******************${END}"
		@echo "${BLUE}    NORMINETTE    ${END}"
		norminette mandatory
		@echo "${BLUE}----COMPLETED----\n\n\n\n${END}"

clean:
		@echo "${RED}----CLEAN----${END}"
		make clean -C libft
		${RM} mandatory/libft.a
		${RM} ${OBJ}
		@echo "${RED}----COMPLETED----${END}"

fclean: clean
		@echo "${RED}----FCLEAN----${END}"
		${RM} ${NAME}
		make fclean -C libft
		@echo "${RED}----COMPLETED----${END}"

re: fclean all

.PHONY: all clean fclean re ${LIBFT}