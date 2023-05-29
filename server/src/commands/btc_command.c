/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** btc_command.c
*/

#include "ftp.h"
#include "server.h"


void bct_command(char **args, server_t *server)
{
    char cmd[100];
    // printf("BONJOUR MONDEE!!!!!!!!!!!!!!!!!!!!!\n");
    // asprintf(cmd, "bct_%s_%s_%s_%s_%s_%s_%s_%s_%s\n",
    // args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);
    char *buffer = NULL;
    int buff_size = 0;

    // arr_append_n_bytes(bufer, cmd, strlen(cmd), 0);
    for (int i = 0; args[i]; ++i) {
        arr_append_n_bytes(buffer, args[i], strlen(args[i]), buff_size);
    }
    if (buffer == NULL)
        asprintf(&buffer, "bct_1_2_3_4_5_6_7_8_9\n");
    printf("sendin to gui: %s\n", buffer);
    send_to_gui(buffer, server);
}