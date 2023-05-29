/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** msz_command.c
*/

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

void msz_command(char **args, server_t *server)
{
    send_to_gui("msz aaaaa\n", server);
}