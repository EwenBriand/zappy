/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** ai_utils.c
*/

#include "ai_command.h"

void client_killer(main_t *main)
{
    send_response_to_ia(MSG_551, main);
    close(CURR_CLI->fd);
    FD_CLR(CURR_CLI->fd, main->server->readfds);
    destroy_client(CURR_CLI);
    CURR_CLI = NULL;
}

bool check_food(main_t *main, int cost, char *cmd)
{
    if (strcmp(cmd, "pnw") == 0)
        return true;
    printf("cost: %d\n", cost);
    if (CURR_CLI->player->inventory[Q0] < cost) {
        printf("NOT ENOUGH FOOD\n");
        client_killer(main);
        return false;
    }
    CURR_CLI->player->inventory[Q0] -= cost;
    return true;
}

