/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** circular_buf
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

char *circular_read(int tcp_socket)
{
    char buf[1024];
    char *buffer = NULL;
    int n = 0;
    int buff_size = 0;

    n = read(tcp_socket, &buf, 1023);
    arr_append_n_bytes(buffer, buf, n, buff_size);
    while (n == 1023) {
        n = read(tcp_socket, &buf, 1023);
        if (n < 0)
            break;
        arr_append_n_bytes(buffer, buf, n, buff_size);
    }
    return buffer;
}
