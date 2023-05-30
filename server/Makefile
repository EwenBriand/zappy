##
## EPITECH PROJECT, 2022
## teams
## File description:
## Makefile
##

CPPFLAGS	=	-I ./include

CFLAGS	=	-Wall -Wextra -g3

CLIENT		=	zappy_server

SRC_CLIENT	=	src/main.c	\
				src/help.c	\
				src/create_server.c	\
				src/ftp/accept_client.c	\
				src/ftp/init_and_destroy.c	\
				src/ftp/loop_server.c	\
				src/ftp/read_client.c	\
				src/circular_buf.c	\
				src/commands/msz_command.c	\
				src/commands/btc_command.c	\
				src/commands/pnw_command.c	\
				src/parser.c	\
				src/commands/ia_server_communication/forward.c	\

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

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

%.o: %.c
	@$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -c $< -o $@ && \
		echo -e "\033[1;32m[OK]\033[0m" $< || \
		echo -e "\033[1;31m[KO]\033[0m" $<

.PHONY: all clean fclean re debug
