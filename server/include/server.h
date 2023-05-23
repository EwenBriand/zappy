/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** my.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void help();
bool create_server(char **av);

typedef struct args_s {
    int port;
    int width;
    int height;
    char **name;
    int clientsNb;
    int freq;
} args_t;

typedef struct server_s {
} server_t;
