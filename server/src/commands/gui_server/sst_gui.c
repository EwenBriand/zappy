/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** sst
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void sst_gui_command(char **args, main_t *server)
{
    server->args->freq = atoi(args[1]);
    sst_command(args, server);
}
