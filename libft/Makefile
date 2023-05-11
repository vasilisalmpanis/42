NAME	=	libft.a
SRC	=	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_memset.c ft_strlen.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_toupper.c\
		ft_tolower.c ft_strchr.c

OBJS	=	${SRC:.c=.o}
INCS	=	"libft.h"
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