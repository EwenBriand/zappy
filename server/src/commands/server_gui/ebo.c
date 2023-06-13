/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** ebo
*/

#include <stdio.h>
#include <stdlib.h>
#include "ftp.h"
#include "server.h"

void ebo_command(char **args, main_t *main)
{
    // 0 : id team_id
    // 1 : id_egg
    char *cmd = NULL;

    int team = atoi(args[0]);
    if (team == -1 || main->teams_list[team] == NULL ||
        main->teams_list[team]->current_player
        >= main->teams_list[team]->max_player)
        return send_response_to_ia("ko\n", main);
    CURR_CLI->player = init_player(main->teams_list[team]->eggs[atoi(args[1])]);
    CURR_CLI->teams = &main->teams_list[team];
    main->teams_list[team]->current_player++;
    printf("EGG player position %d, %d\n", CURR_CLI->player->coord.x, CURR_CLI->player->coord.y);

    sprintf(cmd, "ebo %d\n", main->teams_list[team]->eggs[atoi(args[1])]->id);
    send_to_gui(cmd, main->server);
    send_ok(main);
    destroy_egg(main->teams_list[team]->eggs[atoi(args[1])]);
    main->teams_list[team]->eggs[atoi(args[1])] = NULL;
}
