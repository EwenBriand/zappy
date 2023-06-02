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
// #include "args.h"
#include "struct.h"
#include "tools.h"
#include "ai_command.h"
#include "error_code.h"

// define to use asprintf
#define _GNU_SOURCE

#define GUI "helloGui\r\n"
// #define CURR_CLI server->client_fd[server->current_client_index]
#define CURR_CLI main->server->client_fd[main->server->current_client_index]

#define CHECK_IF_GUI_SETUP(main, i, str)                           \
    do {                                                           \
        if (strcmp(str, GUI) == 0) {                               \
            printf("GUI connected and setup!\n");                  \
            main->server->gui_fd = main->server->client_fd[i]->fd; \
            msz_command(NULL, main);                               \
            return;                                                \
        }                                                          \
    } while (0)

#define CALL_AI_COMMAND(tab, main)                                     \
    do {                                                               \
        for (int i = 0; call_server_form_ia[i].command; i++) {         \
            printf("tab[0] = %s\n", tab[0]);                           \
            printf("call_server_form_ia[i].command = %s\n",            \
                call_server_form_ia[i].command);                       \
            if (strcmp(tab[0], call_server_form_ia[i].command) == 0) { \
                call_server_form_ia[i].func(tab, main);                \
                return;                                                \
            }                                                          \
        }                                                              \
    } while (0)

#define CHECK_COORD_PLAYER(main)                                \
    do {                                                        \
        if (CURR_CLI->player->orientation == NORTH)             \
            CURR_CLI->player->coord.y -= 1;                     \
        if (CURR_CLI->player->coord.y < 0)                      \
            CURR_CLI->player->coord.y = main->args->height - 1; \
        if (CURR_CLI->player->orientation == SOUTH)             \
            CURR_CLI->player->coord.y += 1;                     \
        if (CURR_CLI->player->coord.y >= main->args->height)    \
            CURR_CLI->player->coord.y = 0;                      \
        if (CURR_CLI->player->orientation == EAST)              \
            CURR_CLI->player->coord.x += 1;                     \
        if (CURR_CLI->player->coord.x >= main->args->width)     \
            CURR_CLI->player->coord.x = 0;                      \
        if (CURR_CLI->player->orientation == WEST)              \
            CURR_CLI->player->coord.x -= 1;                     \
        if (CURR_CLI->player->coord.x < 0)                      \
            CURR_CLI->player->coord.x = main->args->width - 1;  \
    } while (0)

static const int ERROR_VALUE = 84;
static const int END_VALUE = 0;
static const int MAX_CLI = 100;

enum orientation { NORTH, EAST, SOUTH, WEST };

enum ressource { Q0, Q1, Q2, Q3, Q4, Q5, Q6 };

int accept_client(server_t *server);
void read_client(main_t *main);
void loop_server(main_t *main);

void destroy_server(server_t *server);
server_t *init_server(args_t *args);
void destroy_client(client_t *client);
client_t *client_init(int fd);
void destroy_main(main_t *main);
main_t *init_main(int argc, char **argv);
void destroy_player(player_t *player);
player_t *init_player(egg_t *egg);
void destroy_egg(egg_t *egg);
egg_t *init_egg(main_t *main, int i);

void send_to_gui(char *cmd, server_t *server);
void send_to_ia(char *cmd, main_t *main);

// commands:
void execute_player_command(main_t *main);
void pnw_command(char **args, main_t *main);
void msz_command(char **args, main_t *main);
void bct_command(char **args, main_t *main);
void ppo_command(char **args, main_t *main);
static const call_command_t commands[] = {{"msz", msz_command},
    {"bct", bct_command}, {"pnw", pnw_command}, {"ppo", ppo_command},
    {NULL, NULL}};
/* C7BD7286_8BB1_4478_8F44_9B46CFC8ED37 */
