NAME = oldie_phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Contact.cpp Phonebook.cpp
OBJ =  $(SRC:.cpp=.o)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

fclean:
	rm $(NAME)

re: fclean all
