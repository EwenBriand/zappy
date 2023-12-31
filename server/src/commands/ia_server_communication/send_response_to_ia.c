/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** send_response_to_ia.c
*/

#include "ai_command.h"

void send_ok(main_t *main)
{
    printf("sending ok\n");

    if (CURR_CLI->fd == -1)
        return;
    send(CURR_CLI->fd, "ok\n", 3, 0);
}

void send_ko(main_t *main)
{
    send(CURR_CLI->fd, "ko\n", 3, 0);
}

void send_response_to_ia(char *response, main_t *main)
{
    send(CURR_CLI->fd, response, strlen(response), 0);
}
