NAME := zombie

SRCS := main.cpp
  
CFLAGS := -Wall -Wextra -Werror -std=c++98

CXX := c++

OBS := $(SRCS:.cpp=.o)

COLOR_RESET = \033[0m
COLOR_GREEN = \033[1;92m
COLOR_BLUE = \033[1;96m

MAKEFLAGS += --no-print-directory

define print_colored
	@echo "$(COLOR_GREEN)$(1)$(COLOR_BLUE)$(2)$(COLOR_RESET)$(3)"
endef

.SILENT:
$(call print_colored, "[SUCCESS]", "./$(NAME)", "Ready")

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