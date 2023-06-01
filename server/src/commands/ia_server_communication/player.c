/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** player.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"

void broadcast(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "pbc_%d_%s\n", CURR_CLI->player->id, args[0]);
    send_to_gui(cmd, main->server);
    send_ok(main);
}

void connect_nbr(char **args, main_t *main)
{
    char *cmd;

    // asprintf(&cmd, "%d\n", main->nb_client - main->nb_gui);
    send_to_ia(cmd, main);
}

void eject(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "pex_%d\n", CURR_CLI->player->id);
    send_to_gui(cmd, main->server);
    send_ok(main);
}

void incantation(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "pie_%d_%d_%d\n", CURR_CLI->player->coord.x,
        CURR_CLI->player->coord.y, 0);
    send_to_gui(cmd, main->server);
    send_ok(main);
}

