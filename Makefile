NAME = avm
SRC = main.cpp\
    Comands.class.cpp\
    OpInt8.class.cpp\
    OpInt16.class.cpp\
    OpInt32.class.cpp\
    OpFloat.class.cpp\
    OpDouble.class.cpp\

OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Werror -Wextra -g
all : $(NAME)
$(NAME) : $(OBJ)
	g++ $(FLAG) $(OBJ) -o $(NAME)
%.o: %.cpp
	g++ $(FLAG) -c $^
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
