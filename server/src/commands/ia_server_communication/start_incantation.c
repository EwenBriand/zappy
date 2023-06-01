/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** start_incantation.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"

void start_incantation(char **args, main_t *main)
{
    printf("START INCANTATION\n");
    send_ok(main);
    char *cmd;
    asprintf(&cmd, "pic_%d_%d_%d\n", CURR_CLI->player->coord.x,
        CURR_CLI->player->coord.y, CURR_CLI->player->level);
    send_to_gui(cmd, main->server);
}