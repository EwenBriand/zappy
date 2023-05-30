/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** btc_command.c
*/

#include <stdio.h>
#include "ftp.h"
#include "server.h"

void bct_command(char **args, main_t *server)
{
    char *buffer = NULL;
    int buff_size = 0;

    for (int i = 0; args[i]; ++i)
        arr_append_n_bytes(buffer, args[i], strlen(args[i]), buff_size);

    if (buffer == NULL)
        asprintf(&buffer, "bct_1_2_3_4_5_6_7_8_9\n");
    printf("sendin to gui: %s\n", buffer);
    send_to_gui(buffer, server->server);
}
