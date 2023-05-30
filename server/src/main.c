/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** main.c
*/

#include <signal.h>
#include "ftp.h"
#include "global.h"
#include "server.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
static void ctrl_c(int sig_no)
{
    HANDLER = ERROR_VALUE;
}

static void fill_inventory(server_t *server, int i, int j)
{
    for (int k = 0; k < 7; k++)
        server->map->tiles[i][j]->inventory[k] = 0;
}

static void create_map(server_t *server)
{
    // create from the size of the map, all the tiles and fill the inventory
    server->map = malloc(sizeof(map_t));
    for (int i = 0; i < server->args->height; i++) {
        server->map->tiles[i] = malloc(sizeof(tile_t *) * server->args->width);
        for (int j = 0; j < server->args->width; j++) {
            server->map->tiles[i][j] = malloc(sizeof(tile_t));
            fill_inventory(server, i, j);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 7)
        return help();

    signal(SIGINT, ctrl_c);
    args_t *args = get_data_from_args(argc, argv);
    server_t *server = init_server(args);
    create_map(server);
    if (server->fd == -1) {
        destroy_server(server);
        return ERROR_VALUE;
    }
    loop_server(server);

    close(server->fd);
    destroy_server(server);

    return (0);
}
