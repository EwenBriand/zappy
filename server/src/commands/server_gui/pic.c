/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** pic
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void pic_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "pic %d %d %d", atoi(args[1]), atoi(args[2]), atoi(args[3]));
    for (int i = 4; args[i]; i++)
        sprintf(cmd + strlen(cmd), "#%d", atoi(args[i]));

    sprintf(cmd + strlen(cmd), "\n");
    send_to_gui(cmd, server->server);
}
