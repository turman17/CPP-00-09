NAME = bureaucrat
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
SRC = main.cpp Bureaucrat.cpp
OBJ =  $(SRC:.cpp=.o)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

fclean:
	rm $(NAME)

re: fclean all
