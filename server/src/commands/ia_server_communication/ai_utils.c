/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** ai_utils.c
*/

#include "ai_command.h"

void client_killer(main_t *main)
{
    send_response_to_ia(MSG_551, main);
    pdi_command((char *[]){my_itoa(CURR_CLI->player->id), NULL}, main);
    close(CURR_CLI->fd);
    FD_CLR(CURR_CLI->fd, main->server->readfds);
    destroy_client(CURR_CLI);
    CURR_CLI = NULL;
    main->server->nbr_client_connected--;
}

static void eat_x_food(player_t *player, int food)
{
    if (player->living_time > food)
        player->living_time -= food;
    else {
        while (player->living_time < food && player->inventory[Q0] > 0) {
            player->inventory[Q0] -= 1;
            player->living_time += 126;
        }
        player->living_time -= food;
        printf("EAT FOOD %i left %i in the stomach\n", player->inventory[Q0],
            player->living_time);
    }
}

static bool have_enough_food(player_t *player, int cost)
{
    if (player->inventory[Q0] * 126 + player->living_time <= cost)
        return false;
    return true;
}

bool check_food(main_t *main, int cost, char *cmd)
{
    if (strcmp(cmd, "pnw") == 0)
        return true;
    if (CURR_CLI->fd == main->server->gui_fd)
        return true;
    if (have_enough_food(CURR_CLI->player, cost * 10) == false) {
        printf("NOT ENOUGH FOOD\n");
        client_killer(main);
        return false;
    }
    eat_x_food(CURR_CLI->player, cost * 10);
    return true;
}

char *get_object_name(int i)
{
    switch (i) {
        case 0: return ("food");
        case 1: return ("linemate");
        case 2: return ("deraumere");
        case 3: return ("sibur");
        case 4: return ("mendiane");
        case 5: return ("phiras");
        case 6: return ("thystame");
        default: return ("");
    }
}
