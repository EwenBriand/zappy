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
    main->server->teams_list = malloc(sizeof(team_t *) * (i + 1));
    printf("CREATE TEAMS LIST\n");
    for (int j = 0; j < i; j++) {
        main->server->teams_list[j] = malloc(sizeof(team_t));
        main->server->teams_list[j]->name = strdup(main->args->name[j]);
        main->server->teams_list[j]->max_player = main->args->clientsNb;
        printf("main->server->teams_list[j]->name : %s\n", main->server->teams_list[j]->name);
    }
    main->server->teams_list[i] = NULL;
}

team_t *get_team_by_name(main_t *main, char *team_name)
{
    // loop inside the teams_list if the team exist return a reference to it else create it
    int i = 0;
    for (; main->server->teams_list[i] != NULL; i++) {
        if (strcmp(main->server->teams_list[i]->name, team_name) == 0)
            return &main->server->teams_list[i];
    }
    return NULL;
}


