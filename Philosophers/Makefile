NAME = philo
SRC =   main.c \
		init_prog.c \
		routine.c \
		eat.c \
		check_philo.c \
		ft_calloc.c \
		ft_atoi.c \
		time.c \

RM = rm -rf
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
PINK = \033[95m
END = \033[0m
MAKE = make

all: norm ${NAME}

${NAME}: ${OBJ}
		@$(CXX) ${CXXFLAGS} $(OBJ) -o $(NAME)
		@echo ""
		@echo "${RED}${NAME} completed${END}"

%.o: %.c
		${CXX} ${CXXFLAGS} -I./readline -I./libft -c $< -o $@

norm:
		@norminette . > /tmp/norminette_output.txt 2>&1
		@rm -rf /tmp/norminette_output.txt
		@echo "${BLUE}\nnorminette completed\n${END}"

clean:
		@${RM} ${OBJ}
		@echo "${RED}Clean completed${END}"

fclean: clean
		@echo ""
		@${RM} ${NAME}
		@echo "${RED}Fclean completed${END}"

re: fclean all

.PHONY: all clean fclean re ${LIBFT}
