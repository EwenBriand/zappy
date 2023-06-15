/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** broadcast.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"
#include <math.h>
#include <stdio.h>


float get_distance_btw_two_tiles(int x1, int y1, int x2, int y2)
{
    int x_vector = x2 - x1;
    int y_vector = y2 - y1;
    return sqrt(pow(x_vector, 2) + pow(y_vector, 2));
}

static int casesNorth[3][3] = {
    {2, 1, 8},
    {3, 0, 7},
    {4, 5, 6}
};

static int casesEast[3][3] = {
    {4, 3, 2},
    {5, 0, 1},
    {6, 7, 8}
};

static int casesSouth[3][3] = {
    {6, 7, 8},
    {5, 0, 1},
    {4, 3, 2}
};

static int casesWest[3][3] = {
    {4, 5, 6},
    {3, 0, 7},
    {2, 1, 8}
};

int get_closest_tile(main_t *main, int x, int y)
{

    int orientation = CURR_CLI->player->orientation;
    int tile = 0;

    x = x - CURR_CLI->player->coord.x; // x = 3 - 2 = 1
    y = y - CURR_CLI->player->coord.y; // y = 3 - 3 = 0

    if (y < 0)
        y = 2;
    if (x < 0)
        x = 2;

    if (orientation == 0) {
        tile = casesNorth[y - 1][x + 1];
    } else if (orientation == 1) {
        tile = casesEast[y + 1][x + 1];
    } else if (orientation == 2) {
        tile = casesSouth[y + 1][x + 1];
    } else if (orientation == 3) {
        tile = casesWest[y + 1][x - 1];
    }
    return tile;
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

    //calulate the vector between the two points
    int x_vector = x2 - x;
    int y_vector = y2 - y;
    float distance = sqrt(pow(x_vector, 2) + pow(y_vector, 2));
    float buf = 100000;
    int tile_n_x = 0;
    int tile_n_y = 0;
    for (int tiles = 0; tiles < 9; tiles++) {
        int tile_x = x + (tiles % 3) - 1;
        int tile_y = y + (tiles / 3) - 1;
        if ((tile_x == -1 && tile_y == -1) ||
            (tile_x == main->map->width && tile_y == main->map->height) ||
            (tile_x == main->map->width && tile_y == -1) ||
            (tile_x == -1 && tile_y == main->map->height)) {
            continue;
        }

        if (tile_x < 0) {
            tile_x = main->map->width - 1;
        } else if (tile_x >= main->map->width) {
            tile_x = 0;
        }
        if (tile_y < 0) {
            tile_y = main->map->height - 1;
        } else if (tile_y >= main->map->height) {
            tile_y = 0;
        }
        printf("tile_x = %d, tile_y = %d\n", tile_x, tile_y);
        float dis = get_distance_btw_two_tiles(tile_x, tile_y, x2, y2);
        buf = (dis < buf) ? dis : buf;
        if (dis == buf) {
            tile_n_x = tile_x;
            tile_n_y = tile_y;
        }
        printf("buf = %f\n", buf);
    }
    printf("buffer = %f\n", buf);
    int res = get_closest_tile(main, tile_n_x, tile_n_y);
    printf("THE TILE IS : %d\n", res);
    return res;
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