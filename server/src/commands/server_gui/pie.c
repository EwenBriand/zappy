/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** pie
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void pie_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(
        cmd, "pie %d %d %d\n", atoi(args[1]), atoi(args[2]), atoi(args[3]));
    send_to_gui(cmd, server->server);
}
