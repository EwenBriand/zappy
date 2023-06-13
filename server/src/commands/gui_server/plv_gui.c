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

void plv_gui_command(char **args, main_t *server)
{
    for (int i = 0; i < MAX_CLI; i++)
        if (server->server->client_fd[i] != NULL
            && server->server->client_fd[i]->player != NULL
            && server->server->client_fd[i]->player->id == atoi(args[1])) {
            plv_command(
                (char *[]){my_itoa(atoi(args[1])),
                    my_itoa(server->server->client_fd[i]->player->level)},
                server);
        }
}
