NAME	= libftpp.a
CXX	= c++
SRC	= ./src/data_buffer.cpp \
	  ./src/memento.cpp

OBJS	= ${SRC:.cpp=.o}
RM	= rm -rf
AR	= ar rcs
CXXFLAGS = -Wall -Wextra -Werror -std=c++11
INCS	= ./include

all : ${NAME}

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
	@echo "Finished"

${BOBJS} : ${BSRC}
	${CXX} ${CXXFLAGS} -c ${BSRC} -I ${INCS}

%.o: %.cpp
		${CXX} ${CXXFLAGS} -c $< -o $@


clean :
	${RM}	${OBJS}	${BOBJS}

fclean : clean
	${RM} ${NAME}
	
re: fclean all

.PHONY: all fclean clean re
