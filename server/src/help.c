/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** help.c
*/

#include "server.h"

int help()
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 "
           "... -c clientsNb -f freq\n");
    printf("\tport\tis the port number\n");
    printf("\twidth\tis the width of the world\n");
    printf("\theight\tis the height of the world\n");
    printf("\tnameX\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf(
        "\tfreq\tis the reciprocal of time unit for execution of actions\n");

    return 84;
}

int list_len(char **list)
{
    int i = 0;
    for (; list[i]; i++)
        ;
    return i;
}
