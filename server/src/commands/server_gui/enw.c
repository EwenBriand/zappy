/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** enw
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void enw_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "enw %s %s %s %s\n", args[0], args[1], args[2], args[3]);
    send_to_gui(cmd, server->server);
}
