NAME			:= Form-up-maggots!

CXX				:= c++
CXXFLAGS		:= -Wall -Wextra -Werror -std=c++98  
RM				:= rm -f

SRCS	:= \
				main.cpp \
				Bureaucrat.cpp \
				Form.cpp

OBJS		= $(SRCS:.cpp=.o)

.PHONY:	all clean fclean re

all:		$(NAME)

clean:
				$(RM) $(OBJS)

fclean:	clean
				$(RM) $(NAME)

re:				fclean all

$(NAME):	$(OBJS)
					$(CXX) $(CXXFLAGS) $^ -o $@
