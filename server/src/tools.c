/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** tools
*/

#include "tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int list_len(void **list)
{
    int i = 0;
    for (; list[i]; i++)
        ;
    return i;
}

char *pop(char **list)
{
    if (!list || !list[0])
        return NULL;
    char *popped = list[0];
    int len = list_len((void **) list);
    for (int i = 0; i < len - 1; i++)
        list[i] = list[i + 1];
    list[len - 1] = NULL;
    return popped;
}

egg_t *pop_egg(egg_t **list)
{
    if (!list || !list[0])
        return NULL;
    egg_t *popped = list[0];
    int len = list_len((void **) list);
    for (int i = 0; i < len - 1; i++)
        list[i] = list[i + 1];
    list[len - 1] = NULL;
    return popped;
}

char *my_itoa(int num)
{
    int len = snprintf(NULL, 0, "%d", num);
    char *str = malloc(len + 1);
    snprintf(str, len + 1, "%d", num);
    return str;
}

char *my_strdup(const char *s)
{
    size_t len = strlen(s) + 1;
    char *dup = malloc(len);
    if (dup)
        memcpy(dup, s, len);
    return dup;
}
