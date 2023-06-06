/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** plv
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void plv_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "plv #%d %d\n", args[1], args[2]);
    send_to_gui(cmd, server->server);
}
