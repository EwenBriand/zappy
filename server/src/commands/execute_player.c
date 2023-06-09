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

int get_command_time(char *name)
{
    printf("name: %s\n", name);
    for (int i = 0; foodCost[i].command; ++i) {
        printf("command: %s\n", foodCost[i].command);
        if (strcmp(name, foodCost[i].command) == 0)
            return foodCost[i].cost;
    }
    return 0;
}

void execute_current_command(main_t *main, int i)
{
    int act_time = time(NULL);
    float div = main->args->freq / 100;

    if ((act_time - main->server->client_fd[i]->player->time) / div
        >= main->server->client_fd[i]->player->command_time / div) {
        if (list_len(main->server->client_fd[i]->player->cmd_buf) == 0)
            return;
        if (strlen(main->server->client_fd[i]->player->cmd_buf[0]) > 2) {
            char **tab = get_args_from_command(
                pop(main->server->client_fd[i]->player->cmd_buf));
            call_ai_command(tab, main);
            main->server->client_fd[i]->player->time = time(NULL);
            main->server->client_fd[i]->player->command_time =
                get_command_time(tab[0]);
            printf("command %s take time: %d\n", tab[0],
                main->server->client_fd[i]->player->command_time);
        }
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
