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

static int get_index_user(main_t *main, int id)
{
    for (int i = 0; i < MAX_CLI; i++)
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL
            && main->server->client_fd[i]->player->id == id)
            return i;
    return -1;
}

void pin_gui_command(char **args, main_t *main)
{
    char **cmd = malloc(sizeof(char *) * 12);

    int index_user = get_index_user(main, atoi(args[1]));
    if (index_user == -1)
        return;

    cmd[0] = my_itoa(main->server->client_fd[index_user]->player->id);
    cmd[1] = my_itoa(main->server->client_fd[index_user]->player->coord.x);
    cmd[2] = my_itoa(main->server->client_fd[index_user]->player->coord.y);

    for (int i = 0; i < 7; i++)
        cmd[3 + i] =
            my_itoa(main->server->client_fd[index_user]->player->inventory[i]);
    cmd[10] = NULL;
    pin_command(cmd, main);
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);
}
