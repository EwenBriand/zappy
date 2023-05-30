/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** forward.c
*/

#include "ai_command.h"

void forward_command(char **args, main_t *main)
{
    printf("FORWARD\n");
    // printf
    // main->server->current_client_index
    printf("client_index :%d\n", main->server->current_client_index);
    printf("pointer :%p\n", CURR_CLI->player);
    if (CURR_CLI->player->orientation == NORTH)
        CURR_CLI->player->coord.y -= 1;
    if (CURR_CLI->player->orientation == SOUTH)
        CURR_CLI->player->coord.y += 1;
    if (CURR_CLI->player->orientation == EAST)
        CURR_CLI->player->coord.x += 1;
    if (CURR_CLI->player->orientation == WEST)
        CURR_CLI->player->coord.x -= 1;

    // printf("x: %d\n", CURR_CLI->player->coord.x);

    send_ok(main);
    char *cmd;
    // pnw_command(args, main);
    sleep(1);
    asprintf(&cmd, "ppo_%d_%d_%d_%c\n", CURR_CLI->player->id,
        CURR_CLI->player->coord.x, CURR_CLI->player->coord.y,
        CURR_CLI->player->orientation);

    // asprintf(&cmd, "ppo_%d_%d_%d_%c\n", 0, 0, 0, 'E');
    send_to_gui(cmd, main->server);
}
