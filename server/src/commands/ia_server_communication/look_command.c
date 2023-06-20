/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** look_command.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"
#include "struct.h"
#include "ai_command.h"

void get_player_on_tile(main_t *main, int x, int y, char *cmd)
{
    char *tmp;
    for (int i = 0; i < main->server->nbr_client_connected; i++) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL
            && main->server->client_fd[i]->player->coord->x == x
            && main->server->client_fd[i]->player->coord->y == y) {
            tmp = my_strdup(cmd);
            sprintf(cmd, "%s player", tmp);
            free(tmp);
        }
    }
}

void get_objects_on_tile(main_t *main, int x, int y, char *cmd)
{
    char *tmp;
    if (x < 0 || x >= main->map->width || y < 0 || y >= main->map->height)
        return;

    for (int i = 0; i < 7; i++)
        if (main->map->tiles[y][x]->inventory[i] > 0) {
            tmp = my_strdup(cmd);
            sprintf(cmd, "%s %s", tmp, get_object_name(i));
            free(tmp);
        }
}

static void one_tile(main_t *main, int *coord, char *cmd, int *pos)
{
    int orientation = CURR_CLI->player->orientation;
    char *tmp;
    int nx = coord[0] + (DX * pos[0]) + (DY * pos[1]);
    int ny = coord[1] + (DY * pos[0]) + (DX * pos[1]);
    get_player_on_tile(main, nx, ny, cmd);
    get_objects_on_tile(main, nx, ny, cmd);
    tmp = my_strdup(cmd);
    sprintf(cmd, "%s,", tmp);
    free(tmp);
}

void look_command(char **args, main_t *main)
{
    char *cmd = malloc(sizeof(char) * 1000);
    cmd[0] = '\0';
    char *tmp;
    int level = CURR_CLI->player->level;
    int x = CURR_CLI->player->coord->x;
    int y = CURR_CLI->player->coord->y;

    for (int i = 0; i < level; i++)
        for (int j = 0; j < (i + 3); j++)
            one_tile(main, (int[]){x, y}, cmd, (int[]){i, j});

    tmp = my_strdup(cmd);
    sprintf(cmd, "[%s]\n", tmp);
    free(tmp);
    send_to_ia(cmd, main);
    free(cmd);
}
