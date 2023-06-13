/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** parser.c
*/

#include "server.h"

char **get_args_from_command(char *str)
{
    // printf("str: %s\n", str);
    char *buf = " \r\n\0";
    char *token = strtok(str, buf);
    char **args = malloc(sizeof(char *) * 100);
    int i = 0;

    for (; token != NULL; i++) {
        args[i] = token;
        token = strtok(NULL, buf);
    }
    args[i] = NULL;
    return args;
}
