/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** pin
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void pin_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "pin #%d %d %d %d %d %d %d %d %d %d\n", atoi(args[1]),
        atoi(args[2]), atoi(args[3]), atoi(args[4]), atoi(args[5]),
        atoi(args[6]), atoi(args[7]), atoi(args[8]), atoi(args[9]),
        atoi(args[10]));
    send_to_gui(cmd, server->server);
}