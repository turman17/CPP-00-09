NAME = ClapTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp ClapTrap.cpp
OBJ =  $(SRC:.cpp=.o)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

fclean:
	rm $(NAME)

re: fclean all
