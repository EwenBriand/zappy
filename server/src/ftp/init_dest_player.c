/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** init_dest_player
*/

#include <stdlib.h>
#include <time.h>
#include "ftp.h"
#include "server.h"

static int id_act = 0;

egg_t *init_egg(main_t *main, int i)
{
    static int id = 0;
    egg_t *new = malloc(sizeof(egg_t));

    if (new == NULL)
        return (NULL);

    srand(time(NULL) + i);
    new->coord.x = rand() % main->args->width;
    new->coord.y = rand() % main->args->height;
    new->team = strdup(main->args->name[i]);
    new->orientation = rand() % 4; // TODO rand
    new->id = id++;
    // jsp si on fait comme ca car ca laisse la possibiliter a un joueur de se
    // connecter sans passer par l'oeuf ce qui fait qu'on a le nb de joueur au
    // max et un oeuf en plus
    // on peut peut etre ne pas add mtn et add a la connection du nouveau
    // joueur dans l'oeuf
    main->teams_list[i]->max_player++;

    printf("Egg created at %d %d with %d oritentation from %s team\n",
        new->coord.x, new->coord.y, new->orientation, new->team);

    return (new);
}

void destroy_egg(egg_t *egg)
{
    free(egg->team);
    free(egg);
}

player_t *init_player(egg_t *egg)
{
    player_t *new = malloc(sizeof(player_t));

    if (new == NULL)
        return (NULL);
    new->id = id_act++;
    new->coord.x = egg->coord.x;
    new->coord.y = egg->coord.y;
    new->orientation = egg->orientation;
    // new->team = egg->team;

    new->inventory[Q0] = 1260;
    for (int i = 1; i < 7; ++i)
        new->inventory[i] = 0;
    new->level = 1;
    new->cmd_buf = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 11; ++i)
        new->cmd_buf[i] = NULL;

    return (new);
}

player_t *init_player_char(char **args)
{
    player_t *new = malloc(sizeof(player_t));

    if (new == NULL)
        return (NULL);
    new->id = id_act++;
    new->coord.x = atoi(args[1]);
    new->coord.y = atoi(args[2]);
    new->orientation = atoi(args[3]);

    new->inventory[Q0] = 1260;
    for (int i = 1; i < 7; ++i)
        new->inventory[i] = 0;
    new->level = 1;
    new->cmd_buf = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 11; ++i)
        new->cmd_buf[i] = NULL;

    printf("Player %d created at %d %d with %d oritentation at level %d\n",
        new->id, new->coord.x, new->coord.y, new->orientation, new->level);

    return (new);
}

void destroy_player(player_t *player)
{
    for (int i = 0; i < 11; ++i)
        if (player->cmd_buf[i] != NULL)
            free(player->cmd_buf[i]);
    free(player);
}
