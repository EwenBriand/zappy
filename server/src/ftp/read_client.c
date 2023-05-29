/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** read_client
*/

#include "ftp.h"
#include "server.h"

// static int get_command_line(char *command)
// {
//     char *tmp = malloc(sizeof(char) * (strlen(command) + 1));
//     char *cmd[] = {"USER", "PASS", "CWD", "CDUP", "DELE", "PWD", "PASV",
//         "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"};
//     int res = 0;

//     for (size_t i = 0; i < strlen(command); i++)
//         if (command[i] == ' ' || command[i] == '\r' || command[i] == '\n') {
//             tmp[i] = '\0';
//             break;
//         } else
//             tmp[i] = command[i];

//     for (; res < 13; ++res)
//         if (strcmp(tmp, cmd[res]) == 0)
//             break;
//     if (strlen(command) == 0)
//         res = 14;
//     free(tmp);
//     return res;
// }

// a update pour intégrer le circular buffer
static void read_client2(server_t *server, int i)
{
    char *buf = circular_read(server->client_fd[i]->fd);
    int val = strlen(buf);

    if (val <= 0 || strcmp(buf, "QUIT") == 0 || strcmp(buf, "QUIT\r\n") == 0) {
        printf("LAST Client said: %s\n", buf);
        dprintf(server->client_fd[i]->fd, "%s", MSG_221);
        close(server->client_fd[i]->fd);
        FD_CLR(server->client_fd[i]->fd, server->readfds);
        destroy_client(server->client_fd[i]);
        server->client_fd[i] = NULL;
    } else {
        printf("Client said: %s\n", buf);
        // make_command(server, buf, i);
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
