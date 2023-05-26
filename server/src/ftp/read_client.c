/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** read_client
*/

#include "ftp.h"

static int get_command_line(char *command)
{
    char *tmp = malloc(sizeof(char) * (strlen(command) + 1));
    char *cmd[] = {"USER", "PASS", "CWD", "CDUP", "DELE", "PWD", "PASV",
        "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"};
    int res = 0;

    for (size_t i = 0; i < strlen(command); i++)
        if (command[i] == ' ' || command[i] == '\r' || command[i] == '\n') {
            tmp[i] = '\0';
            break;
        } else
            tmp[i] = command[i];

    for (; res < 13; ++res)
        if (strcmp(tmp, cmd[res]) == 0)
            break;
    if (strlen(command) == 0)
        res = 14;
    free(tmp);
    return res;
}

static void make_command(server_t *server, char *buf, int i)
{
    int command = get_command_line(buf);

    switch (command) {
        case 0: user(server, i); break;
        case 1: pass(server, buf, i); break;
        case 2: cwd(server, buf, i); break;
        case 3: cdup(server, i); break;
        case 4: dele(server, buf, i); break;
        case 5: pwd(server, i); break;
        case 6: pasv(server, i); break;
        case 7: port(server, buf, i); break;
        case 8: help(server, i); break;
        case 9: noop(server, i); break;
        case 10: retr(server, buf, i); break;
        case 12: list(server, buf, i); break;
        case 14: dprintf(server->client_fd[i]->fd, "%s", NSG_550); break;
        default: dprintf(server->client_fd[i]->fd, "%s", NSG_500); break;
    }
}

static void read_client2(server_t *server, int i)
{
    char buf[1024];
    int val = 0;

    printf("client start\n");
    val = read(server->client_fd[i]->fd, buf, 1024);
    buf[val] = '\0';
    if (val <= 0 || strcmp(buf, "QUIT") == 0 || strcmp(buf, "QUIT\r\n") == 0) {
        printf("LAST Client said: %s\n", buf);
        dprintf(server->client_fd[i]->fd, "%s", NSG_221);
        close(server->client_fd[i]->fd);
        FD_CLR(server->client_fd[i]->fd, server->readfds);
        destroy_client(server->client_fd[i]);
        server->client_fd[i] = NULL;
    } else {
        printf("Client said: %s\n", buf);
        make_command(server, buf, i);
    }
}

void read_client(server_t *server)
{
    for (int i = 0; i < 100 - 1; i++) {
        if (server->client_fd[i] != NULL)
            printf("%i\n", server->client_fd[i]->fd);
        if (server->client_fd[i] != NULL
            && FD_ISSET(server->client_fd[i]->fd, server->copy)) {
            read_client2(server, i);
        }
    }
}
