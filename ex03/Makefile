NAME			:= At-least-this-beats-coffee-making

CXX				:= c++
CXXFLAGS		:= -Wall -Wextra -Werror -std=c++98  
RM				:= rm -f

SRCS	:= \
				main.cpp \
				Bureaucrat.cpp \
				Form.cpp \
				ShrubberyCreationForm.cpp \
				RobotomyRequestForm.cpp \
				PresidentialPardonForm.cpp \
				Intern.cpp

OBJS		= $(SRCS:.cpp=.o)

.PHONY:	all clean fclean re

all:		$(NAME)

clean:
				$(RM) $(OBJS) *_shrubbery

fclean:	clean
				$(RM) $(NAME)

re:				fclean all

$(NAME):	$(OBJS)
					$(CXX) $(CXXFLAGS) $^ -o $@
