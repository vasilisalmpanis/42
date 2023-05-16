NAME	=	ft_display_file
SRC	=	src/ft_display_file.c
OBJS	=	${SRC:.c=.o}
INCS	=	includes
LIBC	=	ar rc
LIBR	=	ranlib
CC	=	cc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC}	${CFLAGS}	-c	$<	-o	${<:.c=.o}	-I ${INCS}

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