/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** ai_command.h
*/

#pragma once
#include "ftp.h"

typedef struct server_s server_t;

typedef struct call_server_form_ia_s {
    char *command;
    void (*func)(char **, server_t *);
} call_server_form_ia_t;

void forward_command(char **args, server_t *server);

static const call_server_form_ia_t call_server_form_ia[] = {
    {"Forward", forward_command},
    {NULL, NULL}
};