/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** inventory.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "incantation.h"
#include "ai_command.h"
#include "init_dest.h"

static void fill_string(int i, char **cmd, main_t *main)
{
    if (i == 0) {
        asprintf(cmd, "%s%s %d", *cmd, get_object_name(i),
            CURR_CLI->player->inventory[i]);
    } else {
        asprintf(cmd, "%s, %s %d", *cmd, get_object_name(i),
            CURR_CLI->player->inventory[i]);
    }
}

void inventory_command(char **args, main_t *main)
{
    printf("INVENTORY!!!!!!!!!!\n");
    char *cmd = "[";
    for (int i = 0; i <= Q6; i++) {
        fill_string(i, &cmd, main);
    }
    asprintf(&cmd, "%s]\n", cmd);
    printf("cmd : %s", cmd);
    send_to_ia(cmd, main);
    free(cmd);
}

void incantation_command(char **args, main_t *main)
{
    bool res = check_tile(
        main, CURR_CLI->player->coord->x, CURR_CLI->player->coord->y);
    start_incantation(args, main, res);
}

void fork_command(char **args, main_t *main)
{
    char *cmd;
    int team_id = get_team_by_name(main, CURR_CLI->team_name);

    asprintf(&cmd, "pfk %d\n", CURR_CLI->player->id);
    send_to_gui(cmd, main->server);
    for (int i = 0; i < 100; i++)
        if (main->teams_list[team_id]->eggs[i] == NULL) {
            main->teams_list[team_id]->eggs[i] =
                init_egg_from_cli(main, team_id);
            break;
        }
    send_ok(main);
    free(cmd);
}
