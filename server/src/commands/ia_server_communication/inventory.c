/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** inventory.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "asprintf.h"
#include "incantation.h"
#include "ai_command.h"
#include "init_dest.h"

static void fill_string(int i, char *cmd, main_t *main)
{
    char *tmp;
    if (i == 0) {
        tmp = my_strdup(cmd);
        sprintf(cmd, "%s%s %d", tmp, get_object_name(i),
            CURR_CLI->player->inventory[i]);
        free(tmp);
    } else {
        tmp = my_strdup(cmd);
        sprintf(cmd, "%s, %s %d", tmp, get_object_name(i),
            CURR_CLI->player->inventory[i]);
        free(tmp);
    }
}

void inventory_command(char **args, main_t *main)
{
    printf("INVENTORY!!!!!!!!!!\n");
    char *cmd = malloc(sizeof(char) * 1000);
    cmd[0] = '\0';
    char *tmp;
    for (int i = 0; i <= Q6; i++)
        fill_string(i, cmd, main);

    tmp = my_strdup(cmd);
    sprintf(cmd, "[%s]\n", tmp);
    printf("cmd : %s", cmd);
    send_to_ia(cmd, main);
    free(tmp);
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
