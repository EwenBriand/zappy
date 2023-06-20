##
## EPITECH PROJECT, 2022
## teams
## File description:
## Makefile
##

CPPFLAGS	=	-I ./include

CFLAGS	=	-Wall -Wextra -g3 -std=c17 -lm -std=gnu99

CLIENT		=	zappy_server

SRC_CLIENT	=	src/main.c	\
				src/help.c	\
				src/create_server.c	\
				src/ftp/accept_client.c	\
				src/ftp/loop_server.c	\
				src/ftp/read_client.c	\
				src/circular_buf.c	\
				src/commands/server_gui/msz.c	\
				src/commands/server_gui/btc.c	\
				src/commands/server_gui/tna.c	\
				src/commands/server_gui/ppo.c	\
				src/commands/server_gui/plv.c	\
				src/commands/server_gui/pin.c	\
				src/commands/server_gui/pex.c	\
				src/commands/server_gui/pbc.c	\
				src/commands/server_gui/sgt.c	\
				src/commands/server_gui/pic.c	\
				src/commands/server_gui/pie.c	\
				src/commands/server_gui/pfk.c	\
				src/commands/server_gui/pdr.c	\
				src/commands/server_gui/pgt.c	\
				src/commands/server_gui/pdi.c	\
				src/commands/server_gui/enw.c	\
				src/commands/server_gui/eht.c	\
				src/commands/server_gui/ebo.c	\
				src/commands/server_gui/edi.c	\
				src/commands/server_gui/sst.c	\
				src/commands/server_gui/seg.c	\
				src/commands/server_gui/smg.c	\
				src/commands/server_gui/suc.c	\
				src/commands/server_gui/sbp.c	\
				src/commands/server_gui/pnw.c	\
				src/parser.c	\
				src/send_response.c	\
				src/commands/gui_server/msz_gui.c	\
				src/commands/gui_server/bct_gui.c	\
				src/commands/gui_server/mct_gui.c	\
				src/commands/gui_server/tna_gui.c	\
				src/commands/gui_server/ppo_gui.c	\
				src/commands/gui_server/plv_gui.c	\
				src/commands/gui_server/pin_gui.c	\
				src/commands/gui_server/sgt_gui.c	\
				src/commands/gui_server/sst_gui.c	\
				src/tools.c	\
				src/commands/ia_server_communication/forward.c	\
				src/commands/ia_server_communication/send_response_to_ia.c	\
				src/commands/ia_server_communication/inventory.c	\
				src/commands/ia_server_communication/turn.c \
				src/commands/ia_server_communication/take_object.c \
				src/commands/ia_server_communication/player.c \
				src/commands/ia_server_communication/ai_utils.c \
				src/commands/ia_server_communication/look_command.c \
				src/commands/ia_server_communication/start_incantation.c \
				src/commands/ia_server_communication/broadcast.c \
				src/commands/ia_server_communication/broadcast2.c \
				src/game/add_ressources.c	\
				src/game/win_cond.c	\
				src/init/init_dest_player.c	\
				src/init/init_dest_main.c	\
				src/init/init_and_destroy.c	\
				src/init/init_team.c	\
				src/init/init_egg.c	\
				src/commands/execute_player.c	\
				src/commands/exec_case.c	\
				src/commands/incant_tool.c	\
				src/commands/gui_commands.c	\

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
