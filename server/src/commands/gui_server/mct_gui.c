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
    for (int i = 0; i < server->map->height; i++)
        for (int j = 0; j < server->map->width; j++) {
            bct_gui_command((char *[]){my_itoa(i), my_itoa(j)}, server);
        }
    printf("mct END \n");
}
