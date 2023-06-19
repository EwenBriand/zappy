/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** ftp
*/
#pragma once
#define _GNU_SOURCE
#pragma GCC diagnostic ignored "-Wunused-parameter"

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
#include "string.h"
#include "struct.h"
#include "tools.h"
#include "ai_command.h"
#include "error_code.h"

#define GUI         "helloGui\r\n"
#define GUI_FORMAT  "helloGui\r"
#define GUI_FORMAT2 "helloGui\n"
#define GUI_FORMAT3 "helloGui"

#define CURR_CLI main->server->client_fd[main->server->current_client_index]

static const int ERROR_VALUE = 84;
static const int END_VALUE = 0;
static const int MAX_CLI = 100;

enum orientation { NORTH, EAST, SOUTH, WEST };
enum ressource { Q0, Q1, Q2, Q3, Q4, Q5, Q6 };

typedef struct foodCost_s {
    char *command;
    int cost;
} foodCost_t;

static const foodCost_t foodCost[] = {{"Forward", 7}, {"Right", 7},
    {"Left", 7}, {"Look", 7}, {"Inventory", 1}, {"Broadcast", 7},
    {"Connect_nbr", 0}, {"Fork", 42}, {"Eject", 7}, {"Take", 7}, {"Set", 7},
    {"Incantation", 10}, {NULL, 0}};

bool check_food(main_t *main, int cost, char *cmd);

int get_team_by_name(main_t *main, char *team_name);
int accept_client(main_t *main);
void read_client(main_t *main);
void loop_server(main_t *main);

void add_ressources(main_t *main);
void add_ressources_if_its_time(main_t *main);

void send_to_gui(char *cmd, server_t *server);
void send_to_ia(char *cmd, main_t *main);
void call_ai_command(char **tab, main_t *main);
void check_coord_player(main_t *main);

void welcome_protocole(main_t *main, char **tab);
int *get_random_pos(main_t *main, int *pos);

// commands:
void exec_player_command(main_t *main);
void pnw_command(char **args, main_t *main);
void msz_command(char **args, main_t *main);
void bct_command(char **args, main_t *main);
void tna_command(char **args, main_t *main);
void ppo_command(char **args, main_t *main);
void plv_command(char **args, main_t *main);
void pin_command(char **args, main_t *main);
void sgt_command(char **args, main_t *main);
void pex_command(char **args, main_t *main);
void pbc_command(char **args, main_t *main);
void pic_command(char **args, main_t *main);
void pie_command(char **args, main_t *main);
void pfk_command(char **args, main_t *main);
void pdr_command(char **args, main_t *main);
void pgt_command(char **args, main_t *main);
void pdi_command(char **args, main_t *main);
void enw_command(char **args, main_t *main);
void eht_command(char **args, main_t *main);
void ebo_command(char **args, main_t *main);
void edi_command(char **args, main_t *main);
void sst_command(char **args, main_t *main);
void seg_command(char **args, main_t *main);
void smg_command(char **args, main_t *main);
void suc_command(char **args, main_t *main);
void sbp_command(char **args, main_t *main);

// static const call_command_t commands[] = {{"msz", msz_command},
//     {"bct", bct_command}, {"tna", tna_command}, {"pnw", pnw_command},
//     {"ppo", ppo_command}, {"plv", plv_command}, {"pin", pin_command},
//     {"sgt", sgt_command}, {"tna", tna_command}, {"pex", pex_command},
//     {"pbc", pbc_command}, {"pic", pic_command}, {"pie", pie_command},
//     {"pfk", pfk_command}, {"pdr", pdr_command}, {"pgt", pgt_command},
//     {"pdi", pdi_command}, {"enw", enw_command}, {"eht", eht_command},
//     {"ebo", ebo_command}, {"edi", edi_command}, {"seg", seg_command},
//     {"smg", smg_command}, {"suc", suc_command}, {"sbp", sbp_command},
//     {NULL, NULL}};

void call_gui_command(main_t *main, char **tab);
void win_cond(main_t *main);

void case_0(main_t *main, int i);
void case_1(main_t *main, int i, int act_time);
void case_2(main_t *main, int i);
