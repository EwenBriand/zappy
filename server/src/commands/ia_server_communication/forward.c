/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** forward.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"

void forward_command(char **args, main_t *main)
{
    printf("FORWARD\n");
    CHECK_COORD_PLAYER(main);
    send_ok(main);
    char *cmd;
    asprintf(&cmd, "ppo_%d_%d_%d_%d\n", CURR_CLI->player->id,
        CURR_CLI->player->coord.x, CURR_CLI->player->coord.y,
        CURR_CLI->player->orientation);
    send_to_gui(cmd, main->server);
}
