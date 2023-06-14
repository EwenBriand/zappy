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

static char *str_append(char *str1, char *str2)
{
    char *new_str = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
    int i = 0;
    for (; str1[i]; i++)
        new_str[i] = str1[i];
    for (int j = 0; str2[j]; j++, i++)
        new_str[i] = str2[j];
    new_str[i] = '\0';
    return new_str;
}

void send_to_gui(char *cmd, server_t *server)
{
    if (cmd[strlen(cmd) - 1] == '\n' && cmd[strlen(cmd) - 2] == '\r')
        send(server->gui_fd, cmd, strlen(cmd), 0);
    else {
        char *new_cmd = str_append(cmd, "\r\n");
        send(server->gui_fd, new_cmd, strlen(new_cmd), 0);
        free(new_cmd);
    }
}

void send_to_ia(char *cmd, main_t *main)
{
    printf("sendin to ia: %s\n", cmd);
    send(CURR_CLI->fd, cmd, strlen(cmd), 0);
}

void msz_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "msz %d %d\n", server->args->width, server->args->height);
    send_to_gui(cmd, server->server);
}
