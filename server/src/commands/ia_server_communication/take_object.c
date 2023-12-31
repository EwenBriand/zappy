/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** take_object.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "asprintf.h"
#include "server.h"
#include "ai_command.h"

void take_object(char **args, main_t *main)
{
    for (int i = 0; i < 7; i++) {
        if (main->map
                ->tiles[CURR_CLI->player->coord->y][CURR_CLI->player->coord->x]
                ->inventory[i]
            > 0) {
            main->map
                ->tiles[CURR_CLI->player->coord->y][CURR_CLI->player->coord->x]
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
    if (CURR_CLI->player->inventory[atoi(args[1])] < quantity)
        return (send_ko(main));
    for (int i = 0; i < quantity; i++) {
        CURR_CLI->player->inventory[atoi(args[1])]--;
        main->map
            ->tiles[CURR_CLI->player->coord->y][CURR_CLI->player->coord->x]
            ->inventory[atoi(args[1])]++;
        pdr_command((char *[]){my_itoa(CURR_CLI->player->id), args[1]}, main);
    }
    printf("set command\n : %d\n", CURR_CLI->player->inventory[atoi(args[1])]);
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
    int team_id = get_team_by_name(main, CURR_CLI->team_name);
    asprintf(&cmd, "%d\n",
        main->teams_list[team_id]->max_player
            - main->teams_list[team_id]->current_player);
    send_to_ia(cmd, main);
    free(cmd);
}
