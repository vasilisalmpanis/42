NAME	= libftpp.a
CXX	= c++
SRC	= ./src/data_buffer.cpp			\
	  ./src/memento.cpp			\
	  ./src/thread_safe_iostream.cpp	\
	  ./src/thread.cpp			\
	  ./src/worker_pool.cpp			\
	  ./src/message.cpp			\
	  ./src/client.cpp			\
	  ./src/persistent_worker.cpp

OBJS	= ${SRC:.cpp=.o}
RM	= rm -rf
AR	= ar rcs
CXXFLAGS = -Wall -Wextra -std=c++11 #-Werror 
INCS	= ./include

all : ${NAME}

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
	@echo "Finished"

${BOBJS} : ${BSRC}
	${CXX} ${CXXFLAGS} -c ${BSRC} -I ${INCS}

%.o: %.cpp
		${CXX} ${CXXFLAGS} -I $(INCS) -c $< -o $@


clean :
	${RM}	${OBJS}	${BOBJS}

fclean : clean
	${RM} ${NAME}
	
re: fclean all

clang-format:
	find ./include/ -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -exec clang-format -i {} +
	find ./src/ -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -exec clang-format -i {} +

.PHONY: all fclean clean re
