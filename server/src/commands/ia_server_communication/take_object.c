/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** take_object.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"
#include "server.h"

void take_object(char **args, main_t *main)
{
    for (int i = 0; i < 7; i++) {
        if (main->map->tiles[CURR_CLI->player->coord.y]
            [CURR_CLI->player->coord.x]->inventory[i] > 0) {
            main->map->tiles[CURR_CLI->player->coord.y]
            [CURR_CLI->player->coord.x]->inventory[i]--;
            CURR_CLI->player->inventory[i]++;
        }
    }
    send_ok(main);
}

void set(char **args, main_t *main)
{
    for (int i = 0; i < 7; i++) {
        if (CURR_CLI->player->inventory[i] > 0) {
            main->map->tiles[CURR_CLI->player->coord.y]
            [CURR_CLI->player->coord.x]->inventory[i]++;
            CURR_CLI->player->inventory[i]--;
        }
    }
    send_ok(main);
}

void take(char **args, main_t *main)
{
    if (strcmp(args[0], "food") == 0)
        take_object(args, main);
    else
        set(args, main);
}

void connect_nbr_command(char **args, main_t *main)
{

}
