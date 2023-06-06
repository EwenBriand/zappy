/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** pin
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void pin_gui_command(char **args, main_t *server)
{
    char **cmd = malloc(sizeof(char *) * 12);
    cmd[0] = "pin";
    cmd[1] = args[1];
    cmd[2] = args[2];
    cmd[3] = args[3];

    for (int i = 0; i < MAX_CLI + 1; i++)
        if (server->server->client_fd[i] != NULL
            && server->server->client_fd[i]->player != NULL
            && server->server->client_fd[i]->player->id == atoi(args[1])) {
            cmd[3 + 1] = my_itoa(server->server->client_fd[i]->player->inventory[0]);
            cmd[4 + 1] = my_itoa(server->server->client_fd[i]->player->inventory[1]);
            cmd[5 + 1] = my_itoa(server->server->client_fd[i]->player->inventory[2]);
            cmd[6 + 1] = my_itoa(server->server->client_fd[i]->player->inventory[3]);
            cmd[7 + 1] = my_itoa(server->server->client_fd[i]->player->inventory[4]);
            cmd[8 + 1] = my_itoa(server->server->client_fd[i]->player->inventory[5]);
            cmd[9 + 1] = my_itoa(server->server->client_fd[i]->player->inventory[6]);
            cmd[10 + 1] = NULL;
        }
    pin_command(cmd, server);
    free(cmd);
}
