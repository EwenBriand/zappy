/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** main.c
*/

#include "server.h"

int main(int ac, char **av)
{
    printf("Hello World\n");
    if (ac != 7)
        help();
    if (create_server(av))
        return 84;
    return (0);
}