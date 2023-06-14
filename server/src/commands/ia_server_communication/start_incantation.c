/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** start_incantation.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"

static const int incantation[7][7] = {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 2, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
};

int get_all_lvl(main_t *main, int lvl)
{
    int nb_player_with_this_lvl = 0;
    for (int i = 0; i < main->server->nbr_client_connected; i++) {
        if (main->server->client_fd[i]->player->level == lvl)
            nb_player_with_this_lvl++;
    }
    return (nb_player_with_this_lvl);
}

bool check_tile(main_t *main, int x, int y)
{
    int lvl = CURR_CLI->player->level;
    int nb_player_with_this_lvl = get_all_lvl(main, lvl);

    for (int i = 0; i < 7; i++) {
        if (incantation[lvl - 1][i] != 0) {
            if (main->map->tiles[y][x]->inventory[i] != incantation[lvl - 1][i])
                return (false);
        }
    }
    return (true);
}

void start_incantation(char **args, main_t *main)
{
    printf("START INCANTATION\n");
    bool res = check_tile(main, CURR_CLI->player->coord.x, CURR_CLI->player->coord.y);
    if (res == false) {
        send_ko(main);
        return;
    }
    send_ok(main);
    char *cmd;
    asprintf(&cmd, "pic %d %d %d\n", CURR_CLI->player->coord.x,
        CURR_CLI->player->coord.y, CURR_CLI->player->level);
    send_to_gui(cmd, main->server);
}