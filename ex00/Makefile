NAME = BitcoinExchange

SRCS = main.cpp BitcoinExchange.cpp

Include = BitcoinExchange.hpp

OBJS = $(SRCS:.cpp=.o)
CC = c++
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o : %.cpp ${Include}
		$(CC) $(CFLAGS) -g -c $< -o $@

all:		$(NAME) 

$(NAME): $(OBJS)
			$(CC) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) 
			
fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY: all fclean clean re