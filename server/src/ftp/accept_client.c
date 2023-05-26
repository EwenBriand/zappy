/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** accept_client
*/

#include "ftp.h"

static void update_list(server_t *server, int client)
{
    printf("Connection accepted\n");
    dprintf(client, "%s", NSG_220);
    for (int i = 0; i < 100; i++)
        if (server->client_fd[i] == NULL) {
            server->client_fd[i] = client_init(client);
            FD_SET(server->client_fd[i]->fd, server->readfds);
            break;
        }
}

int accept_client(server_t *server)
{
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int client = 0;

    if (FD_ISSET(server->fd, server->copy)) {
        client = accept(
            server->fd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client < 0) {
            printf("Error on accept");
            return 84;
        } else
            update_list(server, client);
    }
    return 0;
}
