/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** pnw_command.c
*/

#include "ftp.h"
#include "server.h"

// pnw #n X Y O L N\n

void pnw_command(char **args, main_t *main)
{
    char *cmd;
    char *freq;
    int team = get_team_by_name(main, args[4]);
    printf("PNW\n");

    if (team == -1 || main->teams_list[team] == NULL
        || main->teams_list[team]->current_player
            >= main->teams_list[team]->max_player)
        return send_response_to_ia("ko\n", main);
    CURR_CLI->player = init_player_char(args);
    CURR_CLI->team_name = strdup(args[4]);
    CURR_CLI->teams = &main->teams_list[team];
    asprintf(&freq, "%d\n", main->args->freq);
    send_response_to_ia(freq, main);
    main->teams_list[team]->current_player++;

    asprintf(&cmd, "pnw %d %d %d %d %d %s\n", CURR_CLI->player->id,
        CURR_CLI->player->coord.x, CURR_CLI->player->coord.y,
        CURR_CLI->player->orientation, CURR_CLI->player->level,
        CURR_CLI->team_name);
    send_to_gui(cmd, main->server);
}
