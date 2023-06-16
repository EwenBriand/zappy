/*
/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** forward.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"

void check_coord_player(main_t *main)
{
    int movement[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int orientation = CURR_CLI->player->orientation;
    int height = main->args->height;
    int width = main->args->width;
    CURR_CLI->player->coord->y =
        (CURR_CLI->player->coord->y + movement[orientation][0] + height)
        % height;
    CURR_CLI->player->coord->x =
        (CURR_CLI->player->coord->x + movement[orientation][1] + width) % width;

    printf("x: %d\n", CURR_CLI->player->coord->x);
    printf("y: %d\n", CURR_CLI->player->coord->y);
}

void forward_command(char **args, main_t *main)
{
    printf("FORWARD\n");
    check_coord_player(main);
    char *cmd;
    asprintf(&cmd, "ppo %d %d %d %d\n", CURR_CLI->player->id,
        CURR_CLI->player->coord->x, CURR_CLI->player->coord->y,
        CURR_CLI->player->orientation);
    printf("cmd PPO: %s\n", cmd);
    send_to_gui(cmd, main->server);
    send_ok(main);
}
