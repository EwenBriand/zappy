/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** tna
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void tna_gui_command(char **args, main_t *server)
{
    for (int i = 0; i < list_len(server->args->name); i++)
        tna_command((char *[]){server->args->name[i]}, server);
}
