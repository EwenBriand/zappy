/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** loop.server
*/

#include <signal.h>
#include "ftp.h"
#include "global.h"

void setup_rdfs(server_t *server)
{
    FD_ZERO(server->readfds);
    FD_SET(server->fd, server->readfds);
    for (int i = 0; i < MAX_CLI; i++) {
        if (server->client_fd[i] != NULL && server->client_fd[i]->fd > 0)
            FD_SET(server->client_fd[i]->fd, server->readfds);
        if (server->client_fd[i] != NULL
            && server->client_fd[i]->fd > server->max)
            server->max = server->client_fd[i]->fd;
    }
    *server->copy = *server->readfds;
}

void loop_server(main_t *main)
{
    int nfds = 0;

    while (HANDLER != ERROR_VALUE) {
        setup_rdfs(main->server);
        nfds = select(
            main->server->max + 1, main->server->copy, NULL, NULL, NULL);
        if (nfds < 0)
            break;

        if (accept_client(main) == 84)
            break;
        read_client(main);
        if (!main->this_is_the_end) {
            exec_player_command(main);
            add_ressources_if_its_time(main);
            win_cond(main);
        } else
            printf("This is the END\nHOLD your breath and count to ten\n");
    }
}
