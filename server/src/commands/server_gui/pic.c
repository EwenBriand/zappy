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
    char *cmd = malloc(sizeof(char) * 1000);
    char *tmp;

    sprintf(cmd, "pic %s %s %s ", args[0], args[1], args[2]);
    for (int i = 3; args[i]; i++) {
        tmp = my_strdup(cmd);
        sprintf(cmd, "%s%s ", tmp, args[i]);
        free(tmp);
    }
    tmp = my_strdup(cmd);
    sprintf(cmd, "%s\n", tmp);
    free(tmp);
    send_to_gui(cmd, server->server);
    free(cmd);
}
