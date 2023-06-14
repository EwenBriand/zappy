/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** ppo
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void ppo_gui_command(char **args, main_t *server)
{
    for (int i = 0; i < MAX_CLI; i++)
        if (server->server->client_fd[i] != NULL
            && server->server->client_fd[i]->player != NULL
            && server->server->client_fd[i]->player->id == atoi(args[1])) {
            ppo_command(
                (char *[]){my_itoa(atoi(args[1])),
                    my_itoa(server->server->client_fd[i]->player->coord.x),
                    my_itoa(server->server->client_fd[i]->player->coord.y),
                    my_itoa(
                        server->server->client_fd[i]->player->orientation)},
                server);
        }
}
