/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** main.c
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ftp.h"
#include "global.h"
#include "server.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
static void ctrl_c(int sig_no)
{
    HANDLER = ERROR_VALUE;
}

int main(int argc, char **argv)
{
    if (argc < 7)
        return help();

    main_t *main = init_main(argc, argv);
    signal(SIGINT, ctrl_c);
    init_teams(main);
    if (main->server->fd == -1) {
        destroy_main(main);
        return ERROR_VALUE;
    }
    loop_server(main);
    printf("i'm out\n");

    destroy_main(main);

    return (0);
}