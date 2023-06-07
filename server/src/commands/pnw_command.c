/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** pnw_command.c
*/

#include "ftp.h"
#include "server.h"

// pnw #n X Y O L N\n

void pnw_command(char **args, main_t *main)
{
    char *cmd;
    char *freq;
    printf("PNW\n");

    CURR_CLI->player = init_player_pnw(args);
    asprintf(&freq, "%d", main->args->freq);
    send_response_to_ia(freq, main);

    asprintf(&cmd, "pnw %d %d %d %d %d %s\n", CURR_CLI->player->id,
        CURR_CLI->player->coord.x, CURR_CLI->player->coord.y,
        CURR_CLI->player->orientation, CURR_CLI->player->level,
        CURR_CLI->team_name);
    send_to_gui(cmd, main->server);
}
