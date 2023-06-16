/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** pic
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void pic_command(char **args, main_t *server)
{
    char *cmd = NULL;

    asprintf(&cmd, "pic %s %s %s ", args[0], args[1], args[2]);
    for (int i = 3; args[i]; i++)
        asprintf(&cmd, "%s%s ", cmd, args[i]);
    asprintf(&cmd, "%s\n", cmd);
    send_to_gui(cmd, server->server);
    free(cmd);
}
