NAME	=	libft.a
SRC		=	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
			ft_memset.c ft_strlen.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_toupper.c\
			ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
			ft_strnstr.c ft_atoi.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c\
			ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_printf.c ft_auxiliary.c\
			ft_utilities.c ft_datoi.c ft_isspace.c\

BSRC	=	ft_lstnew.c	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\

GNL_DIR = ./gnl/

GNL_SRCS := $(addprefix $(GNL_DIR),get_next_line_bonus.c get_next_line_utils_bonus.c)

GNL_OBJS := $(GNL_SRCS:$(GNL_DIR)%.c=$(GNL_DIR)%.o)

OBJS	=	${SRC:.c=.o}
BOBJS	=	${BSRC:.c=.o}
INCS	=	"libft.h"
LIBC	=	ar -rc
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror

all : ${NAME}

${NAME}:	${OBJS} $(GNL_OBJS)
	@${LIBC}	${NAME}	${OBJS} $(GNL_OBJS)

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

$(GNL_DIR)%.o: $(GNL_DIR)%.c $(HEADERS)
	cc $(CFLAGS) -I . -c $< -o $@

${BOBJS} : ${BSRC}
	@${CC} ${CFLAGS} -c ${BSRC}


bonus: ${BOBJS} ${OBJS} $(GNL_OBJS)
	@${LIBC}	${NAME}	${BOBJS}

fclean : clean
	@${RM} ${NAME}

clean :
	@${RM}	${OBJS}	${BOBJS} $(GNL_OBJS)
	
re: fclean all

.PHONY: all fclean clean re bonus