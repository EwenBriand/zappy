/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** ebo
*/

#define __STDC_WANT_LIB_EXT2__ 1
#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"
#include "init_dest.h"

// 0 : id team_id
// 1 : id_egg

void ebo_command(char **args, main_t *main)
{
    char *cmd = NULL;
    printf("EBO\n");
    int team = atoi(args[0]);
    if (team == -1 || main->teams_list[team] == NULL
        || main->teams_list[team]->current_player
            >= main->teams_list[team]->max_player)
        return send_response_to_ia("ko\n", main);
    asprintf(
        &cmd, "ebo %d\n", main->teams_list[team]->eggs[atoi(args[1])]->id);
    send_to_gui(cmd, main->server);

    CURR_CLI->player =
        init_player(main->teams_list[team]->eggs[atoi(args[1])], main);
    CURR_CLI->teams = team;
    CURR_CLI->team_name = strdup(main->teams_list[team]->name);
    main->teams_list[team]->current_player++;
    printf("EGG player position %d, %d\n", CURR_CLI->player->coord->x,
        CURR_CLI->player->coord->y);

    send_ok(main);
    destroy_egg(main->teams_list[team]->eggs[atoi(args[1])]);
    main->teams_list[team]->eggs[atoi(args[1])] = NULL;
}
