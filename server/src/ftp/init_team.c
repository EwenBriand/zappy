/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** init_team.c
*/

#include "ftp.h"
#include "server.h"

void init_teams(main_t *main)
{
    int i = 0;
    for (; main->args->name[i] != NULL; i++) {}
    main->teams_list = malloc(sizeof(team_t *) * (i + 1));
    for (int j = 0; j < i; j++) {
        main->teams_list[j] = malloc(sizeof(team_t));
        main->teams_list[j]->name = strdup(main->args->name[j]);
        main->teams_list[j]->max_player = main->args->nb_client_max;
        main->teams_list[j]->current_player = 0;
        printf("main->teams_list[j]->name : %s\n", main->teams_list[j]->name);
    }
    main->teams_list[i] = NULL;
}

int get_team_by_name(main_t *main, char *team_name)
{
    // loop inside the teams_list if the team exist return a reference to it
    // else create it
    int i = 0;
    for (; main->teams_list[i] != NULL; i++) {
        if (strcmp(main->teams_list[i]->name, team_name) == 0)
            return i;
    }
    return -1;
}
