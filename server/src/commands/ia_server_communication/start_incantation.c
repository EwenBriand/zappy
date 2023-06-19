/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** start_incantation.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "incantation.h"
#include "ai_command.h"

static const int incantation[7][7] = {{1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0}, {2, 2, 0, 1, 0, 2, 0}, {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0}, {6, 1, 2, 2, 0, 1, 0}, {6, 2, 2, 2, 2, 2, 1}};

int get_all_lvl(main_t *main, int lvl)
{
    int nb_player_with_lvl = 1;
    for (int i = 0; i < main->server->nbr_client_connected
         && nb_player_with_lvl < incantation[lvl - 1][0];
         i++) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL
            && main->server->client_fd[i]->player->level == lvl
            && main->server->client_fd[i]->player->coord->x
                == CURR_CLI->player->coord->x
            && main->server->client_fd[i]->player->coord->y
                == CURR_CLI->player->coord->y
            && main->server->client_fd[i]->player->id != CURR_CLI->player->id)
            nb_player_with_lvl++;
    }
    return (nb_player_with_lvl);
}

static bool maybe(main_t *main, int *coord, int i, int lvl)
{
    if (incantation[lvl - 1][i] != 0) {
        if (main->map->tiles[coord[1]][coord[0]]->inventory[i]
            < incantation[lvl - 1][i]) {
            printf(
                "NO RESSOURCESE %i is nessesary %i on map and %i nessesary\n",
                i, main->map->tiles[coord[1]][coord[0]]->inventory[i],
                incantation[lvl - 1][i]);
            return (false);
        }
    }
    return (true);
}

bool check_tile(main_t *main, int x, int y)
{
    printf("act level %i\n\n", CURR_CLI->player->level);
    int lvl = CURR_CLI->player->level;
    int nb_player_with_this_lvl = get_all_lvl(main, lvl);

    printf("in check : nb_player_with_lvl = %d incantation[lvl - 1][0] = %d\n",
        nb_player_with_this_lvl, incantation[lvl - 1][0]);
    if (nb_player_with_this_lvl != incantation[lvl - 1][0]) {
        printf("NO PLAYER\n");
        return (false);
    }
    for (int i = 1; i < 7; i++)
        if (!maybe(main, (int[]){x, y}, i, lvl))
            return (false);
    return (true);
}

void delete_ressources(main_t *main, int x, int y)
{
    int lvl = CURR_CLI->player->level;

    for (int i = 1; i < 7; i++)
        if (incantation[lvl - 1][i] != 0)
            main->map->tiles[y][x]->inventory[i] -= incantation[lvl - 1][i];
}

void start_incantation(char **args, main_t *main, bool res)
{
    printf("START INCANTATION\n");
    if (res == false) {
        printf("KO INCANTATION FAILED\n");
        free(CURR_CLI->player->act_cmd);
        CURR_CLI->player->act_cmd = strdup("Incant2");
        send_ko(main);
        return;
    }
    lock_all(main);

    char cmd[1000];
    sprintf(cmd, "pic %d %d %d %d", CURR_CLI->player->coord->x,
        CURR_CLI->player->coord->y, CURR_CLI->player->level,
        CURR_CLI->player->id);
    for (int i = 0; CURR_CLI->player->id_player_inc[i] != -1; i++)
        sprintf(cmd, "%s %d", cmd,
            main->server->client_fd[CURR_CLI->player->id_player_inc[i]]
                ->player->id);
    send_to_gui(cmd, main->server);
}
