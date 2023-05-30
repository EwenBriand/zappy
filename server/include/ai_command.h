/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** ai_command.h
*/

#pragma once
#define _GNU_SOURCE
#include "ftp.h"

typedef struct main_s main_t;

typedef struct call_server_form_ia_s {
    char *command;
    void (*func)(char **, main_t *);
} call_server_form_ia_t;

void forward_command(char **args, main_t *main);
void send_ok(main_t *main);
void send_ko(main_t *main);
void send_response_to_ia(char *response, main_t *main);
void pnw_command(char **args, main_t *main);
static const call_server_form_ia_t call_server_form_ia[] = {
    {"Forward", forward_command},
    {"pnw", pnw_command},
    {NULL, NULL}
};