/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** init_and_destroy
*/

#include "ftp.h"

static int creat_tcp(char *port)
{
    struct sockaddr_in my_addr;

    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(atoi(port));
    my_addr.sin_addr.s_addr = INADDR_ANY;

    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(tcp_socket, (struct sockaddr *) &my_addr, sizeof(my_addr)) == -1)
        return -1;
    listen(tcp_socket, 42);
    return tcp_socket;
}

server_t *init_server(char *port, char *origin)
{
    server_t *server = malloc(sizeof(server_t));
    server->origin = malloc(sizeof(char) * 1024);

    server->fd = creat_tcp(port);
    server->max = server->fd;
    server->client_fd = malloc(sizeof(client_t *) * 100);
    for (int i = 0; i < 100; i++)
        server->client_fd[i] = NULL;
    if (chdir(origin) == -1) {
        free(server->origin);
        server->origin = NULL;
    } else
        getcwd(server->origin, 1024);

    server->readfds = malloc(sizeof(fd_set));
    FD_ZERO(server->readfds);
    FD_SET(server->fd, server->readfds);
    server->copy = malloc(sizeof(fd_set));
    return server;
}

void destroy_server(server_t *server)
{
    for (int i = 0; i < 100; i++)
        if (server->client_fd[i] != NULL)
            destroy_client(server->client_fd[i]);

    free(server->client_fd);
    free(server->readfds);
    free(server->copy);
    free(server);
}

client_t *client_init(int fd)
{
    client_t *client = malloc(sizeof(client_t));

    client->fd = fd;
    client->name = NULL;
    client->pass = NULL;
    client->connected = 0;
    client->path = malloc(sizeof(char) * 1024);
    getcwd(client->path, 1024);
    client->mode = 0;
    client->data_socket = -1;
    return client;
}

void destroy_client(client_t *client)
{
    close(client->fd);
    free(client->name);
    free(client->pass);
    free(client->path);
    free(client);
}
