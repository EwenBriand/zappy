/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** broadcast.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"

int manhattanDistance(coord_t p1, coord_t p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int get_tile(main_t *main, client_t *client)
{
    int x = CURR_CLI->player->coord.x;
    int y = CURR_CLI->player->coord.y;
    int x2 = client->player->coord.x;
    int y2 = client->player->coord.y;

    printf("x : %d\n", x);
    printf("y : %d\n", y);
    printf("x2 : %d\n", x2);
    printf("y2 : %d\n", y2);

    // use the manhattan distance to get closest tile


    // printf("distance : %d\n", distance);

    return 1;

}

void broadcast(char **args, main_t *main)
{
    char *cmd = NULL;

    for (int i = 0; i < main->server->nbr_client_connected; i++) {
        if (main->server->client_fd[i] != NULL &&
            main->server->client_fd[i]->player != NULL
            && main->server->client_fd[i]->player->id !=
                CURR_CLI->player->id) {
            asprintf(&cmd, "message %d, %s\n", get_tile(main,
                main->server->client_fd[i]), args[1]);
            dprintf(main->server->client_fd[i]->fd, "%s", cmd);
        }
    }

    asprintf(&cmd, "pbc %d %s\n", CURR_CLI->player->id, args[1]);
    send_to_gui(cmd, main->server);
    send_ok(main);
}