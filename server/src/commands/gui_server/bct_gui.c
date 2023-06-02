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
    cmd[2 + 1] = my_itoa(server->map->tiles[x][y].inventory[0]);
    cmd[3 + 1] = my_itoa(server->map->tiles[x][y].inventory[1]);
    cmd[4 + 1] = my_itoa(server->map->tiles[x][y].inventory[2]);
    cmd[5 + 1] = my_itoa(server->map->tiles[x][y].inventory[3]);
    cmd[6 + 1] = my_itoa(server->map->tiles[x][y].inventory[4]);
    cmd[7 + 1] = my_itoa(server->map->tiles[x][y].inventory[5]);
    cmd[8 + 1] = my_itoa(server->map->tiles[x][y].inventory[6]);
    cmd[9 + 1] = NULL;
    bct_command(cmd, server);
    free(cmd);
}
