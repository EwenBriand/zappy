/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** look_command.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "ai_command.h"

char *get_player_on_tile(main_t *main, int x, int y)
{
    char *cmd = NULL;
    for (int i = 0; i < main->server->nbr_client_connected; i++) {
        if (main->server->client_fd[i]->player->coord.x == x &&
            main->server->client_fd[i]->player->coord.y == y) {
            asprintf(&cmd, "player");
        }
    }
    if (cmd == NULL)
        asprintf(&cmd, "");
    return (cmd);
}

static get_object_name(int i)
{
    switch (i) {
        case 0:
            return ("food");
        case 1:
            return ("linemate");
        case 2:
            return ("deraumere");
        case 3:
            return ("sibur");
        case 4:
            return ("mendiane");
        case 5:
            return ("phiras");
        case 6:
            return ("thystame");
    }
}

void get_objects_on_tile(main_t *main, int x, int y, char **cmd)
{
    for (int i = 0; i < 7; i++) {
        if (main->map->tiles[y][x].inventory[i] > 0) {
            for (int j = 0; j < main->map->tiles[y][x].inventory[i]; j++) {
                asprintf(cmd, "%s %s", *cmd, get_object_name(i));
            }
        }
    }
}

void look_command(char **args, main_t *main)
{
    char *cmd = "[";
    printf("LOOK\n");
    int orientation = CURR_CLI->player->orientation;
    int level = CURR_CLI->player->level;
    if (orientation == NORTH) {
        for (int i = 0; i < level; i++) {
            for (int j = 0; j < (i + 2) + 1; j++) {
                printf("j: {%d}\n", j);
                asprintf(&cmd, "%s%s", cmd, get_player_on_tile(main,
                    CURR_CLI->player->coord.x - i,
                    CURR_CLI->player->coord.y - j));
                get_objects_on_tile(main, CURR_CLI->player->coord.x - i,
                    CURR_CLI->player->coord.y - j, &cmd);
                asprintf(&cmd, "%s,", cmd);
            }
        }
    }
    asprintf(&cmd, "%s]", cmd);
    send_to_ia(cmd, main);
    free(cmd);
}
