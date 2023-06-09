/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** btc_command.c
*/

#include <stdio.h>
#include "ftp.h"
#include "server.h"

void bct_command(char **args, main_t *main)
{
    char *buffer = NULL;
    int buff_size = 0;

    for (int i = 0; args[i]; ++i) {
        arr_append_n_bytes(buffer, args[i], strlen(args[i]), buff_size);
        if (args[i + 1])
            arr_append_n_bytes(buffer, " ", 1, buff_size);
    }

    if (buffer == NULL)
        asprintf(&buffer, "bct 1 2 3 4 5 6 7 8 9\n");
    printf("sendin to gui: %s\n", buffer);
    send_to_gui(buffer, main->server);
}
