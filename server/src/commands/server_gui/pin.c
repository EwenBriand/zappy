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
    sprintf(cmd, "pin %s %s %s %s %s %s %s %s %s %s\n", args[0],
        args[1], args[2], args[3], args[4],
        args[5], args[6], args[7], args[8],
        args[9]);
    send_to_gui(cmd, server->server);
}
