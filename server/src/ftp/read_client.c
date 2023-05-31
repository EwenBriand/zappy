/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** read_client
*/

#include "ftp.h"
#include "server.h"

void get_command(char *str, main_t *main, int i)
{
    printf("Client said: [%s]\n", str);
    CHECK_IF_GUI_SETUP(main, i, str);
    char **tab = get_args_from_command(str);
    CALL_AI_COMMAND(tab, main);
}

static void read_client2(main_t *main, int i)
{
    char *buf = circular_read(main->server->client_fd[i]->fd);
    int val = strlen(buf);
    main->server->current_client_index = i;
    if (val <= 0 || strcmp(buf, "QUIT") == 0 || strcmp(buf, "QUIT\r\n") == 0) {
        // printf("LAST Client said: %s\n", buf);
        dprintf(main->server->client_fd[i]->fd, "%s", MSG_221);
        close(main->server->client_fd[i]->fd);
        FD_CLR(main->server->client_fd[i]->fd, main->server->readfds);
        destroy_client(main->server->client_fd[i]);
        main->server->client_fd[i] = NULL;
    } else {
        get_command(buf, main, i);
    }
}

void read_client(main_t *main)
{
    for (int i = 0; i < MAX_CLI - 1; i++) {
        if (main->server->client_fd[i] != NULL)
            printf("%i\n", main->server->client_fd[i]->fd);
        if (main->server->client_fd[i] != NULL
            && FD_ISSET(main->server->client_fd[i]->fd, main->server->copy)) {
            read_client2(main, i);
        }
    }
}
