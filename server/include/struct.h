/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** struct
*/

#pragma once

#include <stdbool.h>
#include <sys/select.h>
#include "args.h"

static const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

#define DX directions[orientation][0]
#define DY directions[orientation][1]

typedef struct coord_s {
    int x;
    int y;
} coord_t;

typedef struct player_s {
    int id;
    coord_t *coord;
    int orientation;
    int level;
    int *inventory; // ICI
    int living_time;
    char **cmd_buf;
    int time;
    int command_time;
    char *act_cmd;
    int status_cmd;
    int *id_player_inc;
    bool locked;
} player_t;

typedef struct tile_s {
    coord_t *coord;
    int *inventory; // ICI
} tile_t;

typedef struct map_s {
    int width;
    int height;
    tile_t ***tiles;
    int *deleted_element; // ICI
} map_t;

typedef struct egg_s {
    int id;
    coord_t *coord;
    char *team;
    int orientation;
} egg_t;

typedef struct team_s {
    char *name;
    int max_player;
    int current_player;
    egg_t **eggs;
    int win;
} team_t;

typedef struct client_s {
    int fd;
    int data_socket;
    int connected;
    char *team_name;
    player_t *player;
    int teams;
    bool is_welcome_protocole_done;
} client_t;

typedef struct server_s {
    int fd;
    int port;
    int max;
    client_t **client_fd;
    int current_client_index;
    fd_set *readfds;
    fd_set *copy;
    int gui_fd;
    int nbr_client_connected;
} server_t;

typedef struct main_s {
    team_t **teams_list;
    server_t *server;
    args_t *args;
    map_t *map;
    int time;
    bool this_is_the_end;
    int id_act;
} main_t;

typedef struct call_command_s {
    char *command;
    void (*func)(char **, main_t *);
} call_command_t;
