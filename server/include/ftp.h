/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** ftp
*/
#pragma once

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "args.h"
#include "error_code.h"
#include "ai_command.h"

#define GUI "helloGui\r\n"
#define CURR_CLI server->client_fd[server->current_client_index]

#define CHECK_IF_GUI_SETUP(server, i, str)             \
    do {                                               \
        if (strcmp(str, GUI) == 0) {                   \
            printf("GUI connected and setup!\n");      \
            server->gui_fd = server->client_fd[i]->fd; \
            msz_command(NULL, server);                 \
            return;                                    \
        }                                              \
    } while (0)

// #define CALL_COMMAND(tab, server)                           \
//     do {                                                    \
//         for (int i = 0; commands[i].command; i++) {         \
//             if (strcmp(tab[0], commands[i].command) == 0) { \
//                 commands[i].func(tab, server);              \
//                 return;                                     \
//             }                                               \
//         }                                                   \
//     } while (0)

//do the same with the ai_commands: call_server_form_ia

#define CALL_AI_COMMAND(tab, server)                           \
    do {                                                    \
        for (int i = 0; call_server_form_ia[i].command; i++) {         \
            if (strcmp(tab[0], call_server_form_ia[i].command) == 0) { \
                call_server_form_ia[i].func(tab, server);              \
                return;                                     \
            }                                               \
        }                                                   \
    } while (0)

static const int ERROR_VALUE = 84;
static const int END_VALUE = 0;
static const int MAX_CLI = 100;

// enum coord { X, Y };

enum orientation { NORTH, EAST, SOUTH, WEST };

enum ressource { Q0, Q1, Q2, Q3, Q4, Q5, Q6 };

typedef struct coord_s { //x and y coord
    int x;
    int y;
} coord_t;

typedef struct player_s {
    int id;
    coord_t coord;
    int orientation;
    int level;
    int inventory[7]; // use enum ressource
    int food;
} player_t;

typedef struct tile_s {
    // coord_t coord;
    int inventory[7]; // use enum ressource
} tile_t;

typedef struct map_s {
    int width;
    int height;
    tile_t ***tiles; // 2D array
} map_t;

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
    map_t *map;
    int current_client_index;
    fd_set *readfds;
    fd_set *copy;
    int gui_fd;
    args_t *args;
} server_t;

typedef struct call_command_s {
    char *command;
    void (*func)(char **, server_t *);
} call_command_t;

server_t *init_server(args_t *args);
void destroy_server(server_t *server);
int accept_client(server_t *server);
void read_client(server_t *server);
void loop_server(server_t *server);
client_t *client_init(int fd);
void destroy_client(client_t *client);

void send_to_gui(char *cmd, server_t *server);

// commands:
void pnw_command(char **args, server_t *server);
void msz_command(char **args, server_t *server);
void bct_command(char **args, server_t *server);
void ppo_command(char **args, server_t *server);
static const call_command_t commands[] = {
    {"msz", msz_command},
    {"bct", bct_command},
    {"pnw", pnw_command},
    {"ppo", ppo_command},
    {NULL, NULL}
};
/* C7BD7286_8BB1_4478_8F44_9B46CFC8ED37 */
