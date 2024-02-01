NAME = job_of_your_dreams
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Account.cpp tests.cpp
OBJ =  $(SRC:.cpp=.o)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

fclean:
	rm $(NAME)

re: fclean all