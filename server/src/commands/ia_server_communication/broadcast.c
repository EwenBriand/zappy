/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** broadcast.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "asprintf.h"
#include "ai_command.h"

#include <math.h>

static int casesNorth[3][3] = {{2, 1, 8}, {3, 0, 7}, {4, 5, 6}};

static int casesEast[3][3] = {{4, 3, 2}, {5, 0, 1}, {6, 7, 8}};

static int casesSouth[3][3] = {{6, 7, 8}, {5, 0, 1}, {4, 3, 2}};

static int casesWest[3][3] = {{4, 5, 6}, {3, 0, 7}, {2, 1, 8}};

static int get_closest_tile(main_t *main, int x, int y)
{
    int orientation = CURR_CLI->player->orientation;
    int tile = 0;

    x = x - CURR_CLI->player->coord->x;
    y = y - CURR_CLI->player->coord->y;

    if (y < 0)
        y = 2;
    if (x < 0)
        x = 2;

    switch (orientation) {
        case 0: tile = casesNorth[y - 1][x + 1]; break;
        case 1: tile = casesEast[y + 1][x + 1]; break;
        case 2: tile = casesSouth[y + 1][x + 1]; break;
        case 3: tile = casesWest[y + 1][x - 1]; break;
        default: break;
    }
    return tile;
}

static int get_tile(main_t *main, client_t *client)
{
    int x = CURR_CLI->player->coord->x;
    int y = CURR_CLI->player->coord->y;
    int x2 = client->player->coord->x;
    int y2 = client->player->coord->y;

    int tile_n_x = 0;
    int tile_n_y = 0;
    for (int tiles = 0; tiles < 9; tiles++)
        broadcast_sec(
            main, (int[]){x, y, x2, y2, tiles}, &tile_n_x, &tile_n_y);

    int res = get_closest_tile(main, tile_n_x, tile_n_y);
    printf("THE TILE IS : %d\n", res);
    return res;
}

void broadcast(char **args, main_t *main)
{
    char *cmd = NULL;
    char *cmd2 = NULL;
    for (int i = 0; i < main->server->nbr_client_connected; i++) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL
            && main->server->client_fd[i]->player->id
                != CURR_CLI->player->id) {
            printf("main->server->client_fd[i]->player->id = %d\n",
                main->server->client_fd[i]->player->id);
            asprintf(&cmd, "message %d, %s\n",
                get_tile(main, main->server->client_fd[i]), args[1]);
            dprintf(main->server->client_fd[i]->fd, "%s", cmd);
            asprintf(&cmd2, "pbc %d %s\n",
                main->server->client_fd[i]->player->id, args[1]);
            send_to_gui(cmd2, main->server);
        }
    }
    send_ok(main);
    free(cmd);
    free(cmd2);
}
