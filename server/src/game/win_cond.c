/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** ftp
*/

#include "ftp.h"
#include "struct.h"

void win_cond(main_t *main)
{
    for (int i = 0; main->teams_list[i]; ++i)
        if (main->teams_list[i]->current_player >= 6)
            main->teams_list[i]->win = 0;

    for (int i = 0; i < main->server->nbr_client_connected; ++i) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL
            && main->server->client_fd[i]->player->level == 8)
            ++main->teams_list[main->server->client_fd[i]->teams]->win;
    }

    for (int i = 0; main->teams_list[i]; ++i)
        if (main->teams_list[i]->max_player >= 6
            && main->teams_list[i]->win >= 6) {
            main->this_is_the_end = true;
            seg_command((char *[]){main->teams_list[i]->name}, main);
        }
}
