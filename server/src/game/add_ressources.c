/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** add_ressources
*/

#include "ftp.h"
#include "server.h"

int *get_random_pos(main_t *main, int *pos)
{
    pos[0] = rand() % (main->args->width);
    pos[1] = rand() % (main->args->height);
    return (pos);
}

static void add_ressource_to_tile(main_t *main, int ressource)
{
    int *pos = malloc(sizeof(int) * 2);
    pos = get_random_pos(main, pos);
    main->map->tiles[pos[0]][pos[1]]->inventory[ressource] += 1;
    free(pos);
}

void add_ressources(main_t *main)
{
    float density[] = {0.5, 0.3, 0.15, 0.1, 0.1, 0.08, 0.05};
    int ressource;

    for (int i = 0; i < 7; ++i) {
        ressource = main->args->width * main->args->height * density[i];
        for (; 0 < ressource; --ressource) {
            add_ressource_to_tile(main, i);
        }
    }
}

void add_ressources_if_its_time(main_t *main)
{
    int act_time = time(NULL);
    float div = main->args->freq / 100;

    if ((act_time - main->time) / div >= 20 / div) {
        for (int i = 0; i < 7; ++i) {
            for (; 0 < main->map->deleted_element[i];
                --main->map->deleted_element[i]) {
                printf("add %i to map\n", i);
                add_ressource_to_tile(main, i);
            }
        }
    }
}
