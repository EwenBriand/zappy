/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** server
*/
#pragma once

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

#include "args.h"

#define arr_append_n_bytes(arr, bytes, n, size) \
    do {                                        \
        arr = realloc(arr, size + n + 1);       \
        memcpy(arr + size, bytes, n);           \
        size += n;                              \
        arr[size] = '\0';                       \
    } while (0)
#define check_arg(x) (strcmp(av[i], x) == 0 && is_digit(av[i + 1]))

typedef struct sockinfo_s {
    int server_sock;
    struct sockaddr_in server_addr;
    int *client_socks;
    int max_clients;
    int listen;
    int current_client_sock;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    int port;
} sockinfo_t;

int help();
bool create_server(args_t *args);
args_t *get_data_from_args(int ac, char **av);
char *circular_read(int tcp_socket);

// NINJA
