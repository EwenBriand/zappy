/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** loop.server
*/

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

void loop_server(server_t *server)
{
    int nfds = 0;

    while (HANDLER != ERROR_VALUE) {
        setup_rdfs(server);
        nfds = select(server->max + 1, server->copy, NULL, NULL, NULL);
        if (nfds < 0)
            break;

        printf("connected asked %i\n", nfds);

        if (accept_client(server) == 84)
            break;
        read_client(server);
    }
}
