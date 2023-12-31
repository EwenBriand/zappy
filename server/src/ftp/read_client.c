/*
** EPITECH PROJECT, 2023
** FTP
** File description:
** read_client
*/

#include "ftp.h"
#include "server.h"
#include "init_dest.h"

static void add_cmd_to_player(player_t *player, char *str)
{
    int i = list_len((void **) player->cmd_buf);
    if (i >= 10)
        return;
    player->cmd_buf[i] = my_strdup(str);
}

void get_command(char *str, main_t *main, int i)
{
    if (main->server->client_fd[i]->player != NULL)
        return add_cmd_to_player(main->server->client_fd[i]->player, str);
    if (strlen(str) > 2) {
        char **tab = get_args_from_command(str);
        if (main->server->client_fd[i]->fd == main->server->gui_fd) {
            return call_gui_command(main, tab);
        }
        welcome_protocole(main, tab);
        free(tab);
    }
}

static void read_client2(main_t *main, int i)
{
    char *buf = circular_read(main->server->client_fd[i]->fd);
    int val = strlen(buf);
    main->server->current_client_index = i;

    if (val <= 0 || strcmp(buf, "QUIT") == 0 || strcmp(buf, "QUIT\r\n") == 0) {
        dprintf(main->server->client_fd[i]->fd, "%s", MSG_221);
        if (main->server->client_fd[i]->player != NULL)
            main->teams_list[main->server->client_fd[i]->teams]
                ->current_player--;
        close(main->server->client_fd[i]->fd);
        FD_CLR(main->server->client_fd[i]->fd, main->server->readfds);
        destroy_client(main->server->client_fd[i]);
        main->server->client_fd[i] = NULL;
        main->server->nbr_client_connected--;
    } else {
        get_command(buf, main, i);
    }
    free(buf);
}

void read_client(main_t *main)
{
    for (int i = 0; i < MAX_CLI - 1; i++) {
        if (main->server->client_fd[i] != NULL
            && FD_ISSET(main->server->client_fd[i]->fd, main->server->copy)) {
            read_client2(main, i);
        }
    }
}
