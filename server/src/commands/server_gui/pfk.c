/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** pfk
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void pfk_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "pfk %s\n", args[0]);
    send_to_gui(cmd, server->server);
}
