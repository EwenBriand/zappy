/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** parser.c
*/

#include "server.h"

char **get_args_from_command(char *str)
{
    char *buf = " \r\n\0";
    char *token = strtok(str, buf);
    char **args = malloc(sizeof(char *) * 100);
    int i = 0;

    for (; token != NULL; i++) {
        args[i] = token;
        token = strtok(NULL, buf);
    }
    args[i] = NULL;
    if (args[1] != NULL && args[1][0] == '#')
        args[1] = &args[1][1];

    return args;
}
