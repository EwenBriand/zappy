/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** take_object.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "server.h"
#include "ai_command.h"

void take_object(char **args, main_t *main)
{
    for (int i = 0; i < 7; i++) {
        if (main->map
                ->tiles[CURR_CLI->player->coord.y][CURR_CLI->player->coord.x]
                ->inventory[i]
            > 0) {
            main->map
                ->tiles[CURR_CLI->player->coord.y][CURR_CLI->player->coord.x]
                ->inventory[i]--;
            CURR_CLI->player->inventory[i]++;
            main->map->deleted_element[i]++;
            pgt_command(
                (char *[]){my_itoa(CURR_CLI->player->id), my_itoa(i)}, main);
        }
    }
    send_ok(main);
}

void set_command(char **args, main_t *main)
{
    int quantity = atoi(args[2]);
    for (int i = 0; i < quantity; i++)
        pdr_command((char *[]){my_itoa(CURR_CLI->player->id), args[1]}, main);

    send_ok(main);
}

void take(char **args, main_t *main)
{
    if (strcmp(args[0], "food") == 0)
        take_object(args, main);
}

void connect_nbr_command(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "%d\n",
        main->args->nb_client_max - main->server->nbr_client_connected + 1);
    send_to_ia(cmd, main);
}
