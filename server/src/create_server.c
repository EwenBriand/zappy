/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** create_server.c
*/

#include "server.h"

bool is_digit(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9') {
            printf("Error: %s is not a digit\n", str);
            return false;
        }
    return true;
}

void display_args(args_t *args)
{
    printf("port: %d\n", args->port);
    printf("width: %d\n", args->width);
    printf("height: %d\n", args->height);

    for (int i = 0; args->name[i]; i++)
        printf("name[%d]: %s\n", i, args->name[i]);

    printf("nb_client_max: %d\n", args->nb_client_max);
    printf("freq: %d\n", args->freq);
}

char **get_names(char **av)
{
    char **names = malloc(sizeof(char *) * 7);
    int i = 0;
    for (i = 0; av[i]; i++) {
        if (av[i][0] == '-' && av[i][1] >= 'a' && av[i][1] <= 'z')
            break;
        names[i] = strdup(av[i]);
    }
    names[i] = NULL;
    return names;
}

args_t *get_data_from_args(int ac, char **av)
{
    args_t *args = malloc(sizeof(args_t));

    for (int i = 0; i < ac; i++) {
        if (check_arg("-p"))
            args->port = atoi(av[i + 1]);
        if (check_arg("-x"))
            args->width = atoi(av[i + 1]);
        if (check_arg("-y"))
            args->height = atoi(av[i + 1]);
        if (strcmp(av[i], "-n") == 0)
            args->name = get_names(av + i + 1);
        if (check_arg("-c"))
            args->nb_client_max = atoi(av[i + 1]);
        if (check_arg("-f"))
            args->freq = atoi(av[i + 1]);
    }
    printf("args->freq: %d\n", args->freq);
    return args;
}

void destroy_args(args_t *args)
{
    for (int i = 0; args->name[i]; i++)
        free(args->name[i]);
    free(args->name);
    free(args);
}
