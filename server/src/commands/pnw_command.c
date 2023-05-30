/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** pnw_command.c
*/

#include "ftp.h"
#include "server.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
void pnw_command(char **args, main_t *server)
{
    send_to_gui("pnw aaaaa\n", server->server);
}
