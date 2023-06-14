/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** init_dest_main
*/

#include "ftp.h"
#include "server.h"

static tile_t *new_tile(int x, int y)
{
    tile_t *new = malloc(sizeof(tile_t));

    new->coord.x = x;
    new->coord.y = y;

    for (int i = 0; i < 7; i++)
        new->inventory[i] = 0;

    return (new);
}

static map_t *init_map(args_t *args)
{
    map_t *new = malloc(sizeof(map_t));

    if (new == NULL)
        return (NULL);
    new->width = args->width;
    new->height = args->height;
    new->tiles = malloc(sizeof(tile_t **) * args->height);
    if (new->tiles == NULL)
        return (NULL);
    for (int i = 0; i < args->height; i++) {
        new->tiles[i] = malloc(sizeof(tile_t *) * args->width);
        if (new->tiles[i] == NULL)
            return (NULL);
        for (int j = 0; j < args->width; j++)
            new->tiles[i][j] = new_tile(i, j);
    }
    for (int i = 0; i < 7; i++)
        new->deleted_element[i] = 0;

    return (new);
}

static void destroy_map(map_t *map)
{
    for (int i = 0; i < map->height; i++)
        free(map->tiles[i]);
    free(map->tiles);
    free(map);
}

main_t *init_main(int argc, char **argv)
{
    main_t *main = malloc(sizeof(main_t));
    int pos = 0;

    main->args = get_data_from_args(argc, argv);
    main->server = init_server(main->args);
    main->map = init_map(main->args);
    main->time = time(NULL);
    main->this_is_the_end = false;

    add_ressources(main);
    return (main);
}

void destroy_main(main_t *main)
{
    printf("destroy main\n");
    if (main->teams_list == NULL) {
        for (int i = 0; main->teams_list[i] != NULL; ++i)
            destroy_teams(main->teams_list[i]);
        free(main->teams_list);
    }
    close(main->server->fd);
    destroy_server(main->server);
    destroy_args(main->args);
    destroy_map(main->map);

    free(main);
}
