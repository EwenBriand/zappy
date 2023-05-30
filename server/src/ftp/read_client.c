/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** read_client
*/

#include "ftp.h"
#include "server.h"

void get_command(char *str, server_t *server, int i)
{
    printf("Client said: [%s]\n", str);
    CHECK_IF_GUI_SETUP(server, i, str);
    char **tab = get_args_from_command(str);
    CALL_AI_COMMAND(tab, server);
}

static void read_client2(server_t *server, int i)
{
    char *buf = circular_read(server->client_fd[i]->fd);
    int val = strlen(buf);
    server->current_client_index = i; //////// TODO: check if working
    if (val <= 0 || strcmp(buf, "QUIT") == 0 || strcmp(buf, "QUIT\r\n") == 0) {
        // printf("LAST Client said: %s\n", buf);
        dprintf(server->client_fd[i]->fd, "%s", MSG_221);
        close(server->client_fd[i]->fd);
        FD_CLR(server->client_fd[i]->fd, server->readfds);
        destroy_client(server->client_fd[i]);
        server->client_fd[i] = NULL;
    } else {
        get_command(buf, server, i);
    }
}

void read_client(server_t *server)
{
    for (int i = 0; i < MAX_CLI - 1; i++) {
        if (server->client_fd[i] != NULL)
            printf("%i\n", server->client_fd[i]->fd);
        if (server->client_fd[i] != NULL
            && FD_ISSET(server->client_fd[i]->fd, server->copy)) {
            read_client2(server, i);
        }
    }
}
