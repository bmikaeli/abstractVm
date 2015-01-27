NAME = avm
SRC = main.cpp\
    Comands.class.cpp

OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Werror -Wextra
all : $(NAME)
$(NAME) : $(OBJ)
	clang++ $(FLAG) $(OBJ) -o $(NAME)
%.o: %.cpp
	clang++ $(FLAG) -c $^
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
