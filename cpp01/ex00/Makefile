NAME := zombie

SRCS := main.cpp  Zombie.cpp randomChump.cpp newZombie.cpp
  
CFLAGS := -Wall -Wextra -Werror -std=c++98

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
	rm -rf	$(NAME)
	
re: fclean all

.PHONY: all clean fclean re