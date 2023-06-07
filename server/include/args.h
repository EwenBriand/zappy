/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** args.h
*/

#pragma once

typedef struct args_s {
    int port;
    int width;
    int height;
    char **name;
    int nb_client_max;
    int freq;
} args_t;
