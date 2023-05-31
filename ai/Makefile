##
## EPITECH PROJECT, 2022
## zappy ia
## File description:
## Makefile zappy ia
##

CC	=	g++

RM	=	rm -f

CPPFLAGS	=	-I ./include

CFLAGS	=	-Wall -Wextra -g3 -std=c++17

CLIENT		=	zappy_ai

SRC_CLIENT	=	src/main.cpp	\
				src/Client.cpp	\
				src/Ai.cpp		\

OBJ_CLIENT	=	$(SRC_CLIENT:.cpp=.o)

all:		$(CLIENT)

$(CLIENT):	$(OBJ_CLIENT)
	$(CC) -o $(CLIENT) $(OBJ_CLIENT) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ_CLIENT)

fclean:	clean
	$(RM) $(CLIENT)
	$(RM) *~ #*# vgcore*

re:	fclean all

debug: CFLAGS += -g3
debug: re

%.o: %.cpp
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ && \
		echo -e "\033[1;32m[OK]\033[0m" $< || \
		echo -e "\033[1;31m[KO]\033[0m" $<

.PHONY: all clean fclean re debug