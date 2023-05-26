/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** ftp
*/

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "error_code.h"

#ifndef C7BD7286_8BB1_4478_8F44_9B46CFC8ED37
    #define C7BD7286_8BB1_4478_8F44_9B46CFC8ED37

static const int ERROR_VALUE = 84;
static const int END_VALUE = 0;

typedef struct client_s {
    int fd;
    int data_socket;

    int connected;
    char *path;
    int mode;
    char *name;
    char *pass;

} client_t;

typedef struct server_s {
    int fd;
    int port;
    int max;
    char *origin;
    client_t **client_fd;
    fd_set *readfds;
    fd_set *copy;

} server_t;

server_t *init_server(char *port, char *origin);
void destroy_server(server_t *server);
int accept_client(server_t *server);
void read_client(server_t *server);
void loop_server(server_t *server);
client_t *client_init(int fd);
void destroy_client(client_t *client);

#endif /* C7BD7286_8BB1_4478_8F44_9B46CFC8ED37 */
