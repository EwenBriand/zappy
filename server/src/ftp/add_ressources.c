/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** add_ressources
*/

#include "ftp.h"
#include "server.h"

static int *get_random_pos(main_t *main, int *pos)
{
    pos[0] = rand() % main->args->width;
    pos[1] = rand() % main->args->height;
    return (pos);
}

static void add_ressourceto_tile(tile_t *tile, int ressource)
{
    tile->inventory[ressource] += 1;
}

void add_ressources(main_t *main)
{
    float density[] = {0.5, 0.3, 0.15, 0.1, 0.1, 0.08, 0.05};
    int *pos = malloc(sizeof(int) * 2);
    int ressource;

    for (int i = 0; i < 7; ++i) {
        ressource = main->args->width * main->args->height * density[i];
        for (int j = 0; j < ressource; ++j) {
            pos = get_random_pos(main, pos);
            add_ressourceto_tile(main->map->tiles[pos[0]][pos[1]], i);
        }
    }
    free(pos);
}

void add_ressources_if_its_time(main_t *main)
{
    int act_time = time(NULL);
    float div = main->args->freq / 100;
    // printf("hello\n");

    if ((act_time - main->time) / div >= 20 / div) {
        printf("add ressources\n");
        add_ressources(main);
        main->time = act_time;
    }
}
