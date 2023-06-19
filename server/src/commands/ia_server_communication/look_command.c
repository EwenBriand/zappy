/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** look_command.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "ai_command.h"

// char *get_player_on_tile(main_t *main, int x, int y)
void get_player_on_tile(main_t *main, int x, int y, char **cmd)
{
    // char *cmd = NULL;
    for (int i = 0; i < main->server->nbr_client_connected; i++) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL
            && main->server->client_fd[i]->player->coord->x == x
            && main->server->client_fd[i]->player->coord->y == y) {
            asprintf(cmd, "%splayer", *cmd);
        }
    }
    // if (cmd == NULL)
    //     return "";
    // return (cmd);
}

void get_objects_on_tile(main_t *main, int x, int y, char **cmd)
{
    if (x < 0 || x >= main->map->width || y < 0 || y >= main->map->height)
        return;

    for (int i = 0; i < 7; i++) {
        if (main->map->tiles[y][x]->inventory[i] > 0) {
            for (int j = 0; j < main->map->tiles[y][x]->inventory[i]; j++) {
                asprintf(cmd, "%s %s", *cmd, get_object_name(i));
                break;
            }
        }
    }
}

void look_command(char **args, main_t *main)
{
    char *cmd = NULL;
    int orientation = CURR_CLI->player->orientation;
    int level = CURR_CLI->player->level;
    int x = CURR_CLI->player->coord->x;
    int y = CURR_CLI->player->coord->y;
    for (int i = 0; i < level; i++) {
        for (int j = 0; j < (i + 3); j++) {
            int nx = x + (DX * i) + (DY * j);
            int ny = y + (DY * i) + (DX * j);
            get_player_on_tile(main, nx, ny, &cmd);
            get_objects_on_tile(main, nx, ny, &cmd);
        }
    }
    asprintf(&cmd, "[%s]", cmd);
    send_to_ia(cmd, main);
    free(cmd);
}
