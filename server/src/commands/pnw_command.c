/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** pnw_command.c
*/


#include "ftp.h"
#include "server.h"

void pnw_command(char **args, server_t *server)
{
    send_to_gui("pnw aaaaa\n", server);
}