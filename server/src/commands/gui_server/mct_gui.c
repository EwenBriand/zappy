/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** mct
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"
#include "gui_command.h"

void mct_gui_command(char **args, main_t *server)
{
    for (int y = 0; y < server->map->height; y++)
        for (int x = 0; x < server->map->width; x++) {
            bct_gui_command(
                (char *[]){"nothing", my_itoa(y), my_itoa(x)}, server);
        }
    printf("mct END \n");
}
