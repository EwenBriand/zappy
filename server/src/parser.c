/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** parser.c
*/

#include "server.h"

char **get_args_from_command(char *str)
{
    char *buf = "_\n\r\0";
    char *token = strtok(str, buf);
    char *args[100];
    int i = 0;
    for (; token != NULL; i++) {
        args[i] = token;
        token = strtok(NULL, buf);
    }
    args[i] = NULL;
    for (int i = 0; args[i]; i++)
        printf("args: [%s]\n", args[i]);
    return args;
}
