/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** pnw_command.c
*/


#include "ftp.h"
#include "server.h"

// pnw #n X Y O L N\n

void pnw_command(char **args, server_t *server)
{
    char *cmd;

    CURR_CLI->player->id = atoi(args[1]);
    CURR_CLI->player->coord.x = atoi(args[2]);
    CURR_CLI->player->coord.y = atoi(args[3]);
    CURR_CLI->player->orientation = atoi(args[4]);
    CURR_CLI->player->level = atoi(args[5]);
    CURR_CLI->name = strdup(args[6]);

    asprintf(&cmd, "pnw_%d_%d_%d_%d_%d_%s\n", CURR_CLI->player->id,
        CURR_CLI->player->coord.x, CURR_CLI->player->coord.y,
        CURR_CLI->player->orientation, CURR_CLI->player->level,
        CURR_CLI->name);
    send_to_gui(cmd, server);
}