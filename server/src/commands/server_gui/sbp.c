/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** sbp
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void sbp_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "sbp\n");
    send_to_gui(cmd, server->server);
}
