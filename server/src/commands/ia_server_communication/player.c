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
    char *cmd = NULL;

    asprintf(&cmd, "pbc_%d_%s\n", CURR_CLI->player->id, args[0]);
    send_to_gui(cmd, main->server);
    send_ok(main);
}

void connect_nbr(char **args, main_t *main)
{
    char *cmd = NULL;
    // asprintf(&cmd, "%d\n", main->nb_client - main->nb_gui);
    send_to_ia(cmd, main);
}

void move_player_from_tile(main_t *main, int i)
{
    if (main->server->client_fd[i]->player->orientation == 0)
        main->server->client_fd[i]->player->coord.y--;
    else if (main->server->client_fd[i]->player->orientation == 1)
        main->server->client_fd[i]->player->coord.x++;
    else if (main->server->client_fd[i]->player->orientation == 2)
        main->server->client_fd[i]->player->coord.y++;
    else if (main->server->client_fd[i]->player->orientation == 3)
        main->server->client_fd[i]->player->coord.x--;
}

void eject(char **args, main_t *main)
{
    char *cmd;

    CURR_CLI->player->coord.x;
    for (int i = 0; i < main->server->nbr_client_connected; i++) {
        if (main->server->client_fd[i]->player->coord.x
                == CURR_CLI->player->coord.x &&
            main->server->client_fd[i]->player->coord.y
                == CURR_CLI->player->coord.y) {
            asprintf(&cmd, "pex_%d\n", main->server->client_fd[i]->player->id);
            send_to_gui(cmd, main->server);
            move_player_from_tile(main, i);
            dprintf(main->server->client_fd[i]->fd, "eject: %d\n",
                CURR_CLI->player->orientation);
        }
    }
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

