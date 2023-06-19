/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** player.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"
#include "init_dest.h"

void connect_nbr(char **args, main_t *main)
{
    char *cmd = NULL;
    send_to_ia(cmd, main);
}

void move_player_from_tile(main_t *main, int i)
{
    switch (main->server->client_fd[i]->player->orientation) {
        case 0: main->server->client_fd[i]->player->coord->y--; break;
        case 1: main->server->client_fd[i]->player->coord->x++; break;
        case 2: main->server->client_fd[i]->player->coord->y++; break;
        case 3: main->server->client_fd[i]->player->coord->x--; break;
        default: break;
    }
}

static void kill_eggs_cond(main_t *main, int i, int j, int pos)
{
    if (main->teams_list[i]->eggs[j] != NULL
        && main->teams_list[i]->eggs[j]->coord->x
            == main->server->client_fd[pos]->player->coord->x
        && main->teams_list[i]->eggs[j]->coord->y
            == main->server->client_fd[pos]->player->coord->y) {
        printf("egg killed %i\n", main->teams_list[i]->eggs[j]->id);
        edi_command(
            (char *[]){my_itoa(main->teams_list[i]->eggs[j]->id)}, main);
        main->teams_list[i]->max_player--;
        destroy_egg(main->teams_list[i]->eggs[j]);
        main->teams_list[i]->eggs[j] = NULL;
    }
}

void kill_eggs(main_t *main, int pos)
{
    for (int i = 0; main->teams_list[i]; ++i)
        for (int j = 0; j < 100; ++j)
            kill_eggs_cond(main, i, j, pos);
}

static bool res_cond(main_t *main, int i)
{
    if (main->server->client_fd[i] != NULL
        && main->server->client_fd[i]->player != NULL
        && main->server->client_fd[i]->player->coord->x
            == CURR_CLI->player->coord->x
        && main->server->client_fd[i]->player->coord->y
            == CURR_CLI->player->coord->y
        && main->server->client_fd[i]->fd != CURR_CLI->fd)
        return true;
    return false;
}

void eject(char **args, main_t *main)
{
    char *cmd;
    int ejected = 0;
    for (int i = 0; i < main->server->nbr_client_connected; i++) {
        if (res_cond(main, i)) {
            asprintf(&cmd, "pex %d\n", main->server->client_fd[i]->player->id);
            send_to_gui(cmd, main->server);
            move_player_from_tile(main, i);
            dprintf(main->server->client_fd[i]->fd, "eject: %d\n",
                CURR_CLI->player->orientation);
            ejected++;
            kill_eggs(main, i);
            free(cmd);
        }
    }
    if (ejected == 0)
        send_ko(main);
    else
        send_ok(main);
}
