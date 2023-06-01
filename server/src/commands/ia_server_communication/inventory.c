/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** inventory.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"

void inventory_command(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "%d_%d_%d_%d_%d_%d_%d\n", CURR_CLI->player->inventory[Q0],
        CURR_CLI->player->inventory[Q1], CURR_CLI->player->inventory[Q2],
        CURR_CLI->player->inventory[Q3], CURR_CLI->player->inventory[Q4],
        CURR_CLI->player->inventory[Q5], CURR_CLI->player->inventory[Q6]);

    send_to_ia(cmd, main);
}

void incantation_command(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "pie_%d_%d_%d\n", CURR_CLI->player->coord.x,
        CURR_CLI->player->coord.y, 0);
    send_to_gui(cmd, main->server);
    send_ok(main);
}

void fork_command(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "pfk_%d\n", CURR_CLI->player->id);
    send_to_gui(cmd, main->server);
    send_ok(main);
}

