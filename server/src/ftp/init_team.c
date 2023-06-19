/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** init_team.c
*/

#include "ftp.h"
#include "server.h"
#include "init_dest.h"

static void init_one_team(main_t *main, int j)
{
    main->teams_list[j] = malloc(sizeof(team_t));
    main->teams_list[j]->name = strdup(main->args->name[j]);
    main->teams_list[j]->max_player = main->args->nb_client_max;
    main->teams_list[j]->current_player = 0;
    main->teams_list[j]->win = false;
    main->teams_list[j]->eggs = malloc(sizeof(egg_t *) * 100);

    // comment CA
    // for (int i = 0; i < main->args->nb_client_max; ++i) {
    //     main->teams_list[j]->eggs[pos++] = init_egg(main, j);
    // }

    for (int pos = 0; pos < 100; ++pos)
        main->teams_list[j]->eggs[pos] = NULL;
    printf("main->teams_list[j]->name : %s\n", main->teams_list[j]->name);
}

void init_teams(main_t *main)
{
    int i = 0;
    for (; main->args->name[i] != NULL; i++) {}
    main->teams_list = malloc(sizeof(team_t *) * (i + 1));
    for (int j = 0; j < i; j++) {
        init_one_team(main, j);
    }
    main->teams_list[i] = NULL;
}

int get_team_by_name(main_t *main, char *team_name)
{
    int i = 0;
    for (; main->teams_list[i] != NULL; i++) {
        if (strcmp(main->teams_list[i]->name, team_name) == 0) {
            printf("team found\n");
            return i;
        }
    }
    return -1;
}

void destroy_teams(team_t *teams)
{
    free(teams->name);
    for (int i = 0; i < 100; ++i)
        if (teams->eggs[i] != NULL)
            destroy_egg(teams->eggs[i]);
    free(teams->eggs);
    free(teams);
}
