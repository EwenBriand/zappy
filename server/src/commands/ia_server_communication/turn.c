/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** turn.c
*/

#include "ai_command.h"

void turn_right(char **args, main_t *main)
{
    if (CURR_CLI->player->orientation == 3)
        CURR_CLI->player->orientation = 0;
    else
        CURR_CLI->player->orientation++;
}

void turn_left(char **args, main_t *main)
{
    if (CURR_CLI->player->orientation == 0)
        CURR_CLI->player->orientation = 3;
    else
        CURR_CLI->player->orientation--;
}