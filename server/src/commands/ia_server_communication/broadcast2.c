/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** broadcast2
*/

#include "asprintf.h"
#include "ai_command.h"

#include <math.h>

static float get_distance_btw_two_tiles(int x1, int y1, int x2, int y2)
{
    int x_vector = x2 - x1;
    int y_vector = y2 - y1;
    return sqrt(pow(x_vector, 2) + pow(y_vector, 2));
}

static float get_tile2(main_t *main, int tile_x, int tile_y, float buf)
{
    if (tile_x < 0) {
        tile_x = main->map->width - 1;
    } else if (tile_x >= main->map->width) {
        tile_x = 0;
    }
    if (tile_y < 0) {
        tile_y = main->map->height - 1;
    } else if (tile_y >= main->map->height) {
        tile_y = 0;
    }
    return buf;
}

static int check_tile_x_and_tile_y(main_t *main, int tile_x, int tile_y)
{
    if ((tile_x == -1 && tile_y == -1)
        || (tile_x == main->map->width && tile_y == main->map->height)
        || (tile_x == main->map->width && tile_y == -1)
        || (tile_x == -1 && tile_y == main->map->height)) {
        return 1;
    }
    return 0;
}

void broadcast_sec(main_t *main, int *int_val, int *tile_n_x, int *tile_n_y)
{
    static float buf = 100000;
    int tile_x = int_val[0] + (int_val[4] % 3) - 1;
    int tile_y = int_val[1] + (int_val[4] / 3) - 1;
    if (check_tile_x_and_tile_y(main, tile_x, tile_y))
        return;
    buf = get_tile2(main, tile_x, tile_y, buf);
    float dis =
        get_distance_btw_two_tiles(tile_x, tile_y, int_val[2], int_val[3]);
    buf = (dis < buf) ? dis : buf;
    if (dis == buf) {
        *tile_n_x = tile_x;
        *tile_n_y = tile_y;
    }
}
