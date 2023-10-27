NAME	=	libft.a
SRC	=	src/ft_putchar.c src/ft_putstr.c src/ft_strcmp.c src/ft_strlen.c src/ft_swap.c

OBJS	=	${SRC:.c=.o}
INCS	=	includes
LIBC	=	ar rc
LIBR	=	ranlib
CC	=	cc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CXX}	${CXXFLAGS}	-c	$<	-o	${<:.c=.o}	-I ${INCS}

${NAME}:	${OBJS}
	${LIBC}	${NAME}	${OBJS}
	${LIBR}	${NAME}

all:	${NAME}

clean:
	${RM}	${OBJS}

fclean:
	${RM}	${NAME}

re:
	fclean all

.PHONY:	all	clean	fclean	re