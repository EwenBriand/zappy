/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** bct
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

static void free_gui(char **args, char **cmd)
{
    for (int i = 0; cmd[i]; i++)
        free(cmd[i]);
    free(cmd);

    if (strcmp(args[0], "bct") == 0)
        return;
    free(args[1]);
    free(args[2]);
}

void bct_gui_command(char **args, main_t *server)
{
    int x = atoi(args[1]);
    int y = atoi(args[2]);
    char **cmd = malloc(sizeof(char *) * 11);
    cmd[0] = my_strdup("bct");
    cmd[1] = my_strdup(args[1]);
    cmd[2] = my_strdup(args[2]);
    int j = 3;
    for (int i = 0; i < 7; i++)
        if (server->map->tiles[y][x]->inventory[i] < 0)
            cmd[j++] = my_itoa(0);
        else
            cmd[j++] = my_itoa(server->map->tiles[y][x]->inventory[i]);
    cmd[j] = NULL;

    bct_command(cmd, server);
    free_gui(args, cmd);
}
