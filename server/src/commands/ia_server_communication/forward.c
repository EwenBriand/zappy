/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** forward.c
*/

#include "ai_command.h"

void forward_command(char **args, server_t *server)
{
    printf("FORWARD\n");
    if (server->client_fd == -1)
        return;

    if (CURR_CLI->player->orientation == NORTH)
        CURR_CLI->player->coord.y -= 1;
    if (CURR_CLI->player->orientation == SOUTH)
        CURR_CLI->player->coord.y += 1;
    if (CURR_CLI->player->orientation == EAST)
        CURR_CLI->player->coord.x += 1;
    if (CURR_CLI->player->orientation == WEST)
        CURR_CLI->player->coord.x -= 1;

    send(CURR_CLI->fd, "ok", 2, 0);
    char *cmd;
    // asprintf(&cmd, "ppo_%d_%d_%d_%d\n", CURR_CLI->player->id,
    //     CURR_CLI->player->coord.x, CURR_CLI->player->coord.y,
    //     CURR_CLI->player->orientation);
    pnw_command(args, server);
    sleep(2);
    asprintf(&cmd, "ppo_%d_%d_%d_%c\n", 0, 0, 0, 'E');
    send_to_gui(cmd, server);
}
