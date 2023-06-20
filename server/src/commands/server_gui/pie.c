/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** pie
*/

#include "asprintf.h"
#include "ftp.h"
#include "server.h"

void pie_command(char **args, main_t *server)
{
    char *cmd = NULL;
    printf("args[2] : %s\n", args[2]);
    asprintf(&cmd, "pie %s %s %s\n", args[0], args[1], args[2]);
    printf("--------------pie : %s -----------------------\n", cmd);
    send_to_gui(cmd, server->server);
    free(cmd);
    free(args[0]);
    free(args[1]);
    free(args[2]);
}
