/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** pbc
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void pbc_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "pbc #%d %s\n", atoi(args[1]), args[2]);
    send_to_gui(cmd, server->server);
}