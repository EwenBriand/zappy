/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** server
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EE9C98FD_0B95_4DFE_96CC_10295A834A7F
    #define EE9C98FD_0B95_4DFE_96CC_10295A834A7F

    #pragma once

    #define arr_append_n_bytes(arr, bytes, n, size) \
        do {                                        \
            arr = realloc(arr, size + n + 1);       \
            memcpy(arr + size, bytes, n);           \
            size += n;                              \
            arr[size] = '\0';                       \
        } while (0)

void help();
bool create_server(char **av);
char *circular_read(int tcp_socket);

typedef struct args_s {
    int port;
    int width;
    int height;
    char **name;
    int clientsNb;
    int freq;
} args_t;

#endif /* EE9C98FD_0B95_4DFE_96CC_10295A834A7F */
