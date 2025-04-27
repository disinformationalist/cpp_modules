NAME := bureaucrat

SRCS := main.cpp Bureaucrat.cpp \
AForm.cpp \
ShrubberyCreationForm.cpp \
RobotomyRequestForm.cpp \
PresidentialPardonForm.cpp \
Intern.cpp

CFLAGS := -Werror -Wextra -Wall -std=c++98

CXX := c++

OBS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBS)
	$(CXX) $(OBS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

