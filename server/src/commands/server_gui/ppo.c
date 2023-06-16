/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** ppo_command.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void ppo_command(char **args, main_t *server)
{
    char cmd[100];
    sprintf(cmd, "ppo %s %s %s %s\n", args[0], args[1], args[2], args[3]);
    send_to_gui(cmd, server->server);
}
