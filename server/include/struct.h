/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** struct
*/

#pragma once

#include <sys/select.h>
#include "args.h"

typedef struct coord_s { // x and y coord
    int x;
    int y;
} coord_t;

typedef struct player_s {
    int id;
    coord_t coord;
    int orientation;
    int level;
    int inventory[7]; // use enum ressource
    char *team;
    int food;
    char **cmd_buf;
} player_t;

typedef struct tile_s {
    coord_t coord;
    int inventory[7]; // use enum ressource
} tile_t;

typedef struct map_s {
    int width;
    int height;
    tile_t **tiles; // 2D array
    // tile_t **map;
} map_t;

typedef struct egg_s {
    coord_t coord;
    char *team;
    int orientation;
} egg_t;

typedef struct client_s {
    int fd;
    int data_socket;
    int connected;
    char *name;
    player_t *player;
} client_t;

typedef struct server_s {
    int fd;
    int port;
    int max;
    client_t **client_fd;
    // map_t *map;
    int current_client_index;
    fd_set *readfds;
    fd_set *copy;
    int gui_fd;
    // args_t *args;
} server_t;

typedef struct main_s {
    server_t *server;
    args_t *args;
    map_t *map;
    egg_t **eggs;
} main_t;

typedef struct call_command_s {
    char *command;
    void (*func)(char **, main_t *);
} call_command_t;
