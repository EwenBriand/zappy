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
    if (main->server->client_fd[i]->player->orientation == 0)
        main->server->client_fd[i]->player->coord->y--;
    else if (main->server->client_fd[i]->player->orientation == 1)
        main->server->client_fd[i]->player->coord->x++;
    else if (main->server->client_fd[i]->player->orientation == 2)
        main->server->client_fd[i]->player->coord->y++;
    else if (main->server->client_fd[i]->player->orientation == 3)
        main->server->client_fd[i]->player->coord->x--;
}

// make me a function kill_eggs, he destroy all the eggs on the tile of
// ejection

void kill_eggs(main_t *main, int pos)
{
    for (int i = 0; main->teams_list[i]; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (main->teams_list[i]->eggs[j] != NULL
                && main->teams_list[i]->eggs[j]->coord->x
                    == main->server->client_fd[pos]->player->coord->x
                && main->teams_list[i]->eggs[j]->coord->y
                    == main->server->client_fd[pos]->player->coord->y) {
                printf("egg killed %i\n", main->teams_list[i]->eggs[j]->id);
                edi_command(
                    (char *[]){my_itoa(main->teams_list[i]->eggs[j]->id)},
                    main);
                main->teams_list[i]->max_player--;
                destroy_egg(main->teams_list[i]->eggs[j]);
                main->teams_list[i]->eggs[j] = NULL;
            }
        }
    }
}

void eject(char **args, main_t *main)
{
    char *cmd;
    int ejected = 0;
    for (int i = 0; i < main->server->nbr_client_connected; i++) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL
            && main->server->client_fd[i]->player->coord->x
                == CURR_CLI->player->coord->x
            && main->server->client_fd[i]->player->coord->y
                == CURR_CLI->player->coord->y
            && main->server->client_fd[i]->fd != CURR_CLI->fd) {
            asprintf(&cmd, "pex %d\n", main->server->client_fd[i]->player->id);
            send_to_gui(cmd, main->server);
            move_player_from_tile(main, i);
            dprintf(main->server->client_fd[i]->fd, "eject: %d\n",
                CURR_CLI->player->orientation);
            ejected++;
            kill_eggs(main, i);
        }
    }
    if (ejected == 0)
        send_ko(main);
    else
        send_ok(main);
}
