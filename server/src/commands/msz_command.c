/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** msz_command.c
*/

#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <stdio.h>
#include <stdlib.h>
// #include "commands.h"
#include "ftp.h"
#include "server.h"

void send_to_gui(char *cmd, server_t *server)
{
    printf("sendin to gui: %s\n", cmd);
    send(server->gui_fd, cmd, strlen(cmd), 0);
}

void send_to_ia(char *cmd, main_t *main)
{
    printf("sendin to ia: %s\n", cmd);
    send(CURR_CLI->fd, cmd, strlen(cmd), 0);
}

void msz_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "msz_%d_%d\n", server->args->width, server->args->height);
    send_to_gui(cmd, server->server);
}
