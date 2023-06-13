/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** inventory.c
*/

#pragma GCC diagnostic ignored "-Wwrite-strings"

#include "ai_command.h"

static char *fill_string(int i, char *cmd, main_t *main)
{
    printf("main->server->current_client_index : %d\n",main->server->current_client_index);
    printf("CURR_CLI->player->inventory[i] : %p\n",
        main->server->client_fd[main->server->current_client_index]->player);
    if (i == 0) {
        asprintf(&cmd, "%s%s %d", cmd, get_object_name(i),
            CURR_CLI->player->inventory[i]);
    } else {
        asprintf(&cmd, "%s, %s %d", cmd, get_object_name(i),
            CURR_CLI->player->inventory[i]);
    }
    return (cmd);
}

void inventory_command(char **args, main_t *main)
{
    char *cmd = "[";
    for (int i = 0; i <= Q6; i++) {
        cmd = fill_string(i, cmd, main);
        printf("cmd : %s\n", cmd);
    }
    asprintf(&cmd, "%s]\n", cmd);
    send_to_ia(cmd, main);
    free(cmd);
}
static void fork_pie(char **args, main_t *main)
{
    char *cmd;
    pid_t pid = fork();
    if (pid == 0) {
        sleep(300 / main->args->freq);
        asprintf(&cmd, "pie %d %d %d\n", CURR_CLI->player->coord.x,
            CURR_CLI->player->coord.y, 1);
        send_to_gui(cmd, main->server);
        free(cmd);
        exit(0);
    }
}

void incantation_command(char **args, main_t *main)
{
    start_incantation(args, main);
    fork_pie(args, main);
    send_ok(main);
}

void fork_command(char **args, main_t *main)
{
    char *cmd;

    asprintf(&cmd, "pfk %d\n", CURR_CLI->player->id);
    send_to_gui(cmd, main->server);
    send_ok(main);
}

