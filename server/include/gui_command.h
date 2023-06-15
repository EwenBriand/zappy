/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** gui_command
*/

#pragma once

#include <stdio.h>
#include "struct.h"

// gui commands:
void pdr_command(char **args, main_t *main);
void pgt_command(char **args, main_t *main);
void msz_gui_command(char **args, main_t *server);
void bct_gui_command(char **args, main_t *server);
void mct_gui_command(char **args, main_t *server);
void tna_gui_command(char **args, main_t *server);
void ppo_gui_command(char **args, main_t *server);
void plv_gui_command(char **args, main_t *server);
void pin_gui_command(char **args, main_t *main);
void sgt_gui_command(char **args, main_t *server);
void sst_gui_command(char **args, main_t *server);

static const call_command_t commands_gui[] = {{"msz", msz_gui_command},
    {"bct", bct_gui_command}, {"mct", mct_gui_command},
    {"tna", tna_gui_command}, {"ppo", ppo_gui_command},
    {"plv", plv_gui_command}, {"pin", pin_gui_command},
    {"sgt", sgt_gui_command}, {"sst", sst_gui_command}, {"pdr", pdr_command},
    {"pgt", pgt_command}, {NULL, NULL}};
