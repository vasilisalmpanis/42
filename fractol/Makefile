NAME    =   fractol
SRC     =   mandatory/main.c\
			mandatory/calculations.c\
			mandatory/draw.c\
			mandatory/errors.c\
			mandatory/initialize.c\
			mandatory/colours.c\
			mandatory/mouse_hooks.c\
			mandatory/keyboard_hooks.c\
			mandatory/burning_ship.c\
			mandatory/julia_set.c\


LIBFT   =   ./libft
RM      =   rm -rf
CC      =   gcc
CFLAGS  =   -g -Wall -O2 -Werror -Wextra

OBJ     =   $(SRC:.c=.o)
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
PINK = \033[95m
END=\033[0m
MAKE = make

all: norm ${LIBFT} ${NAME}

${NAME}: ${OBJ} ${LIBFT}
		@if [[ ! -f mlx/libmlx.a ]]; then \
    		make -C mlx; \
		fi
		@$(CC) ${CFLAGS} $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a
		@${RM} libft.a
		@echo "${RED}${NAME} completed${RED}"

${LIBFT}:
		@make -q -C libft || make -C libft
		@cp ${LIBFT}/libft.a .
		@echo "${GREEN}libft completed\n${END}"

%.o: %.c
		${CC} ${CFLAGS} -I includes/fractol.h -Imlx -c $< -o $@

norm :
		@norminette mandatory > /tmp/norminette_output.txt 2>&1
		@rm -rf /tmp/norminette_output.txt
		@echo "${BLUE}\nnorminette completed\n${END}"

clean:
		@make clean -C libft
		@${RM} mandatory/libft.a
		@${RM} ${OBJ}
		@echo "${RED}Clean completed${END}"

fclean: clean
		@echo ""
		@${RM} ${NAME}
		@make fclean -C libft
		@echo "${RED}Fclean completed${END}"

space:
		@echo ""

re: fclean all

.PHONY: all clean fclean re ${LIBFT}