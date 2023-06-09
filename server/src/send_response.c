/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** send_response.c
*/

#include "ftp.h"

void welcome_protocole(main_t *main, char **tab)
{
    if (strcmp(tab[0], GUI) == 0 || strcmp(tab[0], GUI_FORMAT) == 0
        || strcmp(tab[0], GUI_FORMAT2) == 0 || strcmp(tab[0], GUI_FORMAT3) == 0) {
        printf("GRAPHIC CONNECTED\n");
        main->server->gui_fd = CURR_CLI->fd;
        return;
    }
    CURR_CLI->team_name = strdup(tab[0]);

    printf("buf = %s\n", tab[0]);
    dprintf(CURR_CLI->fd, "%i\n", main->server->current_client_index);
    usleep(1000);
    dprintf(CURR_CLI->fd, "%d %d\n", main->map->width,
        main->map->height);
    // pnw_command((*char[]) {CURR_CLI->team_name}, main);
    pnw_command(tab, main);
    printf("CURR_CLI->team_name = %s\n", CURR_CLI->team_name);
    if (CURR_CLI->player == NULL){
        printf("CURR_CLI->player == NULL\n");
        return;
    }
}

void call_ai_command(char **tab, main_t *main)
{
    for (int i = 0; tab[i]; i++)
        printf("tab[%d] = %s\n", i, tab[i]);

    // if (CURR_CLI->is_welcome_protocole_done == false) {
    //     printf("welcome protocole\n");
    //     welcome_protocole(main, tab);
    //     CURR_CLI->is_welcome_protocole_done = true;
    //     send_ok(main);
    //     return;
    // }

    for (int i = 0; call_server_form_ia[i].command; i++) {
        if (strcmp(tab[0], call_server_form_ia[i].command) == 0
            && check_food(main, foodCost[i].cost, tab[0])) {
            printf("call_server_form_ia[i].func(tab, main): %s \n", tab[0]);
            call_server_form_ia[i].func(tab, main);
            return;
        }
    }
    printf("send_ko(main);\n");
    send_ko(main);
}

// irnt check_if_gui_setup(char **args, main_t *main)
// {
//     // if (strlen(str) == 0)
//     //     return 0;
// if (strcmp(str, GUI) == 0 || strcmp(str, GUI_FORMAT) == 0
//     || strcmp(str, GUI_FORMAT2) == 0 || strcmp(str, GUI_FORMAT3) == 0) {
//         printf("GUI connected and setup!\n");

//         // printf("gui fd = %d\n", main->server->gui_fd);
//     //     return 1;
//     // }
//     // return 0;
// }
