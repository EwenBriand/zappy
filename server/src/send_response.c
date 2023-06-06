/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** send_response.c
*/

#include "ftp.h"

void call_ai_command(char **tab, main_t *main)
{
    for (int i = 0; call_server_form_ia[i].command; i++) {
        if (strcmp(tab[0], call_server_form_ia[i].command) == 0
            && check_food(main, foodCost[i].cost, tab[0])) {
            call_server_form_ia[i].func(tab, main);
            return;
        }
    }
}

int check_if_gui_setup(main_t *main, int i, char *str)
{
    if (strlen(str) == 0)
        return 0;
    if (strcmp(str, GUI) == 0 || strcmp(str, GUI_FORMAT) == 0
    || strcmp(str, GUI_FORMAT2) == 0 || strcmp(str, GUI_FORMAT3) == 0) {
        printf("GUI connected and setup!\n");
        main->server->gui_fd = main->server->client_fd[i]->fd;
        msz_command(NULL, main);
        return 1;
    }
    return 0;
}

void check_coord_player(main_t *main)
{
    int movement[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
    int orientation = CURR_CLI->player->orientation;
    int height = main->args->height;
    int width = main->args->width;

    CURR_CLI->player->coord.y = (CURR_CLI->player->coord.y + movement[orientation][0] + height) % height;
    CURR_CLI->player->coord.x = (CURR_CLI->player->coord.x + movement[orientation][1] + width) % width;
}