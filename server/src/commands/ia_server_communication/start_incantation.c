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
        if (main->server->client_fd[i]->player != NULL &&
            main->server->client_fd[i]->player->level == lvl)
            nb_player_with_this_lvl++;
    }
    return (nb_player_with_this_lvl);
}

bool check_tile(main_t *main, int x, int y)
{
    int lvl = CURR_CLI->player->level;
    int nb_player_with_this_lvl = get_all_lvl(main, lvl);

    if (nb_player_with_this_lvl < incantation[lvl - 1][0]) {
        printf("NO PLAYER\n");
        return (false);
    }
    for (int i = 1; i < 7; i++) {
        if (incantation[lvl - 1][i] != 0) {
            if (main->map->tiles[y][x]->inventory[i] < incantation[lvl - 1][i]) {
                printf("NO RESSOURCESE %i is nessesary %i on map and %i nessesary\n", i, main->map->tiles[y][x]->inventory[i], incantation[lvl - 1][i]);
                return (false);
            }
        }
    }
    for (int i = 1; i < 7; i++)
        if (incantation[lvl - 1][i] != 0)
            main->map->tiles[y][x]->inventory[i] -= incantation[lvl - 1][i];
    return (true);
}

void start_incantation(char **args, main_t *main, bool res)
{
    printf("START INCANTATION\n");
    if (res == false) {
        printf("KO INCANTATION FAILED\n");
        send_ko(main);
        return;
    }
    printf("old level %i\n", CURR_CLI->player->level);
    CURR_CLI->player->level++;
    printf("new level %i\n", CURR_CLI->player->level);

    send_ok(main);
    char *cmd;
    asprintf(&cmd, "pic %d %d %d\n", CURR_CLI->player->coord.x,
                CURR_CLI->player->coord.y, CURR_CLI->player->level);
    send_to_gui(cmd, main->server);
    free(cmd);
}
