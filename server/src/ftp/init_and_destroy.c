/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** init_and_destroy
*/

#include "ftp.h"
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
static int creat_tcp(int port)
{
    struct sockaddr_in my_addr;

    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (setsockopt(
            tcp_socket, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int))
        < 0)
        return -1;
    if (bind(tcp_socket, (struct sockaddr *) &my_addr, sizeof(my_addr)) == -1)
        return -1;
    listen(tcp_socket, 42);
    // int flags = fcntl(tcp_socket, F_GETFL, 0);
    // fcntl(tcp_socket, F_SETFL, flags | O_NONBLOCK);
    return tcp_socket;
}

server_t *init_server(args_t *args)
{
    server_t *server = malloc(sizeof(server_t));

    server->fd = creat_tcp(args->port);
    server->max = server->fd;
    server->client_fd = malloc(sizeof(client_t *) * MAX_CLI);
    for (int i = 0; i < MAX_CLI; i++)
        server->client_fd[i] = NULL;

    server->readfds = malloc(sizeof(fd_set));
    FD_ZERO(server->readfds);
    FD_SET(server->fd, server->readfds);
    server->copy = malloc(sizeof(fd_set));
    server->gui_fd = -1;
    return server;
}

void destroy_server(server_t *server)
{
    for (int i = 0; i < MAX_CLI; i++)
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
    client->connected = 0;
    client->data_socket = -1;
    client->player = NULL;
    return client;
}

void destroy_client(client_t *client)
{
    close(client->fd);
    free(client->name);
    free(client);
}
