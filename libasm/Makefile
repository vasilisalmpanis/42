NAME	=	libasm.a
SRC	=	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s  \
		ft_read.s   \
		ft_strdup.s

OBJS	=	${SRC:.s=.o}
#BOBJS	=	${BSRC:.c=.o}
LIBC	=	ar -rc
NASM	=	nasm
RM	=	rm -f
FLAGS	=	-f elf64 -F dwarf -g

all : ${NAME}

${NAME}:	${OBJS}
	${LIBC}	${NAME}	${OBJS}

%.o: %.s
		${NASM} ${FLAGS} $< -o $@
#${BOBJS} : ${BSRC}
#	${CXX} ${CXXFLAGS} -c ${BSRC} -I ${INCS}


#bonus: ${BOBJS} ${OBJS}
#	${LIBC}	${NAME}	${BOBJS}

fclean : clean
	${RM} ${NAME}

clean :
	${RM}	${OBJS}	
	
re: fclean all

.PHONY: all fclean clean re
