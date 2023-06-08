/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** execute_player
*/

#include "ftp.h"
#include "server.h"
#include "struct.h"
#include "ai_command.h"

void execute_current_command(main_t *main, int i)
{

    // setup food et time gestion
    if (list_len(main->server->client_fd[i]->player->cmd_buf) == 0)
        return;
    if (strlen(main->server->client_fd[i]->player->cmd_buf[0]) > 2) {
        char **tab = get_args_from_command(
            pop(main->server->client_fd[i]->player->cmd_buf));
        call_ai_command(tab, main);
    }
}

void execute_player_command(main_t *main)
{
    for (int i = 0; i < MAX_CLI - 1; i++) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL) {
            execute_current_command(main, i);
        }
    }
}
