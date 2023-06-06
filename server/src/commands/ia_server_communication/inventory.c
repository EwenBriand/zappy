/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** inventory.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"

static void fill_string(int i, char **cmd, main_t *main)
{
    if (i == 0)
        asprintf(cmd, "%s%s %d", *cmd, get_object_name(i),
            CURR_CLI->player->inventory[i]);
    else {
        asprintf(cmd, "%s, %s %d", *cmd, get_object_name(i),
            CURR_CLI->player->inventory[i]);
    }
}

void inventory_command(char **args, main_t *main)
{
    char *cmd = "[";

    for (int i = 0; i <= Q6; i++) {
        fill_string(i, &cmd, main);
    }
    asprintf(&cmd, "%s]\n", cmd);
    send_to_ia(cmd, main);
}

void incantation_command(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "pie %d %d %d\n", CURR_CLI->player->coord.x,
        CURR_CLI->player->coord.y, 0);
    send_to_gui(cmd, main->server);
    send_ok(main);
}

void fork_command(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "pfk %d\n", CURR_CLI->player->id);
    send_to_gui(cmd, main->server);
    send_ok(main);
}

