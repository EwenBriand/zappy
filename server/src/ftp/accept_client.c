/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** accept_client
*/

#include "ftp.h"

static void manage_team(main_t *main, int i)
{

}

static void accept_new_user_protocole(main_t *main, int i)
{
    char *msg = "WELCOME\n";
    char *buf = malloc(sizeof(char) * 8);
    dprintf(main->server->client_fd[i]->fd, "%s", msg);
    int len = read(main->server->client_fd[i]->fd, buf, 8);
    if (check_if_gui_setup(main, i, buf))
        return;
    if (len) {
        main->server->client_fd[i]->team_name = strdup(buf);
        manage_team(main, i);
    }
    dprintf(main->server->client_fd[i]->fd, "%i\n", i + 1);
    usleep(1000);
    dprintf(main->server->client_fd[i]->fd, "%d %d\n", main->map->width,
        main->map->height);
}

static void update_list(main_t *main, int client)
{
    for (int i = 0; i < 100; i++)
        if (main->server->client_fd[i] == NULL) {
            main->server->client_fd[i] = client_init(client);
            FD_SET(main->server->client_fd[i]->fd, main->server->readfds);
            accept_new_user_protocole(main, i);
            break;
        }
}

int accept_client(main_t *main)
{
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client = 0;

    if (FD_ISSET(main->server->fd, main->server->copy)) {
        main->server->nbr_client_connected++;
        client = accept(
            main->server->fd, (struct sockaddr *) &client_addr, &client_addr_len);
        printf("New client connected\n");
        if (client < 0) {
            printf("Error on accept");
            return 84;
        } else
            update_list(main, client);
    }
    return 0;
}
