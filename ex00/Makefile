NAME			:= Mommy,-when-I-grow-up,-I-want-to-be-a-bureaucrat!

CXX				:= c++
CXXFLAGS		:= -Wall -Wextra -Werror -std=c++98
RM				:= rm -f

SRCS	:= \
				main.cpp \
				Bureaucrat.cpp

OBJS		= $(SRCS:.cpp=.o)

.PHONY:	all clean fclean re

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:	clean
				$(RM) $(NAME)

re:				fclean all

$(NAME):	$(OBJS)
					$(CXX) $(CXXFLAGS) $^ -o $@
