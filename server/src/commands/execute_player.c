/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** exec_player
*/

#include "ftp.h"
#include "incantation.h"
#include "server.h"
#include "struct.h"
#include "ai_command.h"

static void exec_current_command(main_t *main, int i)
{
    int act_time = time(NULL);

    if (main->server->client_fd[i]->player->locked)
        return;
    if (main->server->client_fd[i]->player->status_cmd == 0)
        return case_0(main, i);
    if (main->server->client_fd[i]->player->status_cmd == 1)
        return case_1(main, i, act_time);
    if (main->server->client_fd[i]->player->status_cmd == 2)
        return case_2(main, i);
}

void exec_player_command(main_t *main)
{
    for (int i = 0; i < MAX_CLI - 1; i++) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL) {
            main->server->current_client_index = i;
            exec_current_command(main, i);
        }
    }
}
