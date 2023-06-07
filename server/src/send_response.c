/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** send_response.c
*/

#include "ftp.h"

void call_ai_command(char **tab, main_t *main)
{
    for (int i = 0; tab[i]; i++)
        printf("tab[%d] = %s\n", i, tab[i]);

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
//     // if (strcmp(str, GUI) == 0 || strcmp(str, GUI_FORMAT) == 0
//     //     || strcmp(str, GUI_FORMAT2) == 0 || strcmp(str, GUI_FORMAT3) == 0) {
//         printf("GUI connected and setup!\n");

//         // printf("gui fd = %d\n", main->server->gui_fd);
//     //     return 1;
//     // }
//     // return 0;
// }

