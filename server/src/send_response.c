/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** send_response.c
*/

#include "ftp.h"

static int case_of_gui(main_t *main, char **tab)
{
    printf("welcome protocole\n");
    if ((strcmp(tab[0], GUI) == 0 || strcmp(tab[0], GUI_FORMAT) == 0
            || strcmp(tab[0], GUI_FORMAT2) == 0
            || strcmp(tab[0], GUI_FORMAT3) == 0)
        && main->server->gui_fd == -1) {
        printf("GRAPHIC CONNECTED\n");
        main->server->gui_fd = CURR_CLI->fd;
        CURR_CLI->player = NULL;
        return -1;
    }
    int team_id = get_team_by_name(main, tab[0]);
    if (team_id == -1) {
        dprintf(CURR_CLI->fd, "ko team does not exist\n");
        return -1;
    } else if (main->server->gui_fd == -1) {
        dprintf(CURR_CLI->fd, "gui not connected\n");
        return -1;
    }
    return team_id;
}

void welcome_protocole(main_t *main, char **tab)
{
    int team_id = case_of_gui(main, tab);
    if (team_id == -1)
        return;
    CURR_CLI->team_name = my_strdup(tab[0]);
    printf("buf = %s\n", tab[0]);
    dprintf(CURR_CLI->fd, "%i\n", main->server->current_client_index);
    usleep(1000);
    dprintf(CURR_CLI->fd, "%d %d\n", main->map->width, main->map->height);

    for (int i = 0; i < 100; i++)
        if (main->teams_list[team_id]->eggs[i] != NULL) {
            printf("ebo %d %d\n", team_id, i);
            ebo_command((char *[]){my_itoa(team_id), my_itoa(i)}, main);
            CURR_CLI->is_welcome_protocole_done = true;
            return;
        }
    pnw_command(tab, main);
    if (CURR_CLI->player == NULL)
        return;
    CURR_CLI->is_welcome_protocole_done = true;
}

void call_ai_command(char **tab, main_t *main)
{
    for (int i = 0; tab[i]; i++)
        printf("tab[%d] = %s\n", i, tab[i]);

    if (CURR_CLI->fd == main->server->gui_fd) {
        main->server->current_client_index++;
    }

    for (int i = 0; call_server_form_ia[i].command; i++) {
        if (strcmp(tab[0], call_server_form_ia[i].command) == 0
            && check_food(main, foodCost[i].cost, tab[0])) {
            printf("call_server_form_ia[i].func(tab, main): %s \n", tab[0]);
            call_server_form_ia[i].func(tab, main);

            return;
        }
    }
    printf("send_ko(main);\n");
    if (CURR_CLI != NULL) {
        send_ko(main);
    }
}
