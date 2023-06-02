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
    printf("PNW\n");

    egg_t *egg = pop_egg(main->eggs);
    if (egg == NULL)
        return send_response_to_ia("KO no eggs available", main);
    CURR_CLI->player = init_player(egg);
    char *freq;
    asprintf(&freq, "%d", main->args->freq);
    send_response_to_ia(freq, main);

    asprintf(&cmd, "pnw_%d_%d_%d_%d_%d_%s\n", CURR_CLI->player->id,
        CURR_CLI->player->coord.x, CURR_CLI->player->coord.y,
        CURR_CLI->player->orientation, CURR_CLI->player->level,
        CURR_CLI->player->team);
    printf("cmd : %s\n", cmd);
    send_to_gui(cmd, main->server);
}
