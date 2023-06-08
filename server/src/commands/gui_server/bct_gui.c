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

void bct_gui_command(char **args, main_t *server)
{
    int x = atoi(args[1]);
    int y = atoi(args[2]);
    char **cmd = malloc(sizeof(char *) * 11);
    cmd[0] = "bct";
    cmd[0 + 1] = args[1];
    cmd[1 + 1] = args[2];
    for (int i = 0; i < 7; i++)
        cmd[3 + i] = my_itoa(server->map->tiles[x][y]->inventory[i]);
    cmd[10] = NULL;
    bct_command(cmd, server);
    free(cmd);
}
