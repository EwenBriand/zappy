/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** incant_tool
*/

#include "ftp.h"
#include "struct.h"

void lock_all(main_t *main)
{
    int nb_player = get_all_lvl(main, CURR_CLI->player->level);
    CURR_CLI->player->id_player_inc = malloc(sizeof(int) * (nb_player + 1));
    int pos = 0;

    printf("nb_player = %d\n", nb_player);

    for (int i = 0;
         i < main->server->nbr_client_connected && nb_player - 1 > pos; i++) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL
            && main->server->client_fd[i]->player->level
                == CURR_CLI->player->level
            && main->server->client_fd[i]->player->coord.x
                == CURR_CLI->player->coord.x
            && main->server->client_fd[i]->player->coord.y
                == CURR_CLI->player->coord.y
            && main->server->client_fd[i]->fd != CURR_CLI->fd) {
            printf("nb_player = %d\n", pos + 1);
            CURR_CLI->player->id_player_inc[pos++] = i;
            main->server->client_fd[i]->player->locked = true;
            dprintf(main->server->gui_fd, "pic %d %d %d %d\n",
                main->server->client_fd[i]->player->coord.x,
                main->server->client_fd[i]->player->coord.y,
                main->server->client_fd[i]->player->level,
                main->server->client_fd[i]->player->id);
        }
    }
    CURR_CLI->player->id_player_inc[pos] = -1;
}

void unlock_all(main_t *main)
{
    if (CURR_CLI->player->id_player_inc == NULL)
        return;
    for (int pos = 0; CURR_CLI->player->id_player_inc[pos] != -1; pos++) {
        main->server->client_fd[CURR_CLI->player->id_player_inc[pos]]
            ->player->locked = false;
    }
}

void level_up_all(main_t *main)
{
    for (int pos = 0; CURR_CLI->player->id_player_inc[pos] != -1; pos++) {
        ++main->server->client_fd[CURR_CLI->player->id_player_inc[pos]]
              ->player->level;
    }
    CURR_CLI->player->level++;
}

void clear_all(main_t *main)
{
    free(CURR_CLI->player->id_player_inc);
    CURR_CLI->player->id_player_inc = NULL;
}
