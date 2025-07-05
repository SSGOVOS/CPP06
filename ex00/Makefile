NAME = program

CC = c++
CFLAGS = -Wall -Wextra --std=c++98

SRCS = 	main.cpp ScalarConverter.cpp \
		utils.cpp 

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.PHONEY:
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all