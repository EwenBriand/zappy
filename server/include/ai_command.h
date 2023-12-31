/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** ai_command.h
*/

#pragma once
#define _GNU_SOURCE
#include "ftp.h"
#define __STDC_WANT_LIB_EXT2__ 1

typedef struct main_s main_t;

typedef struct call_server_form_ia_s {
    char *command;
    void (*func)(char **, main_t *);
} call_server_form_ia_t;

// tools
char *get_object_name(int i);

void forward_command(char **args, main_t *main);
void send_ok(main_t *main);
void send_ko(main_t *main);
void send_response_to_ia(char *response, main_t *main);
void pnw_command(char **args, main_t *main);
void inventory_command(char **args, main_t *main);
void turn_right(char **args, main_t *main);
void turn_left(char **args, main_t *main);
void take_object(char **args, main_t *main);
void look_command(char **args, main_t *main);
void broadcast(char **args, main_t *main);
void broadcast_sec(main_t *main, int *int_val, int *tile_n_x, int *tile_n_y);
void connect_nbr_command(char **args, main_t *main);
void fork_command(char **args, main_t *main);
void eject(char **args, main_t *main);
void incantation_command(char **args, main_t *main);
void set_command(char **args, main_t *main);
void start_incantation(char **args, main_t *main, bool res);
bool check_tile(main_t *main, int x, int y);

static const call_server_form_ia_t call_server_form_ia[] = {
    {"Forward", forward_command}, {"pnw", pnw_command},
    {"Inventory", inventory_command}, {"Right", turn_right},
    {"Left", turn_left}, {"Take", take_object}, {"Look", look_command},
    {"Set", set_command}, {"Broadcast", broadcast},
    {"Connect_nbr", connect_nbr_command}, {"Fork", fork_command},
    {"Eject", eject}, {"Incantation", incantation_command},
    // {"PlayersLevel", players_level_command},
    {NULL, NULL}};
