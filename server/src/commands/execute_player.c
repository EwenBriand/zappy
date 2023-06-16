/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** execute_player
*/

#include "ftp.h"
#include "incantation.h"
#include "server.h"
#include "struct.h"
#include "ai_command.h"


int get_command_time(char *name)
{
    printf("name: %s\n", name);
    for (int i = 0; foodCost[i].command; ++i) {
        printf("command: %s\n", foodCost[i].command);
        if (strcmp(name, foodCost[i].command) == 0)
            return foodCost[i].cost;
    }
    return 0;
}

static void case_0(main_t *main, int i)
{
    if (list_len((void **) main->server->client_fd[i]->player->cmd_buf) == 0)
        return;
    main->server->client_fd[i]->player->status_cmd = 1;
    main->server->client_fd[i]->player->act_cmd =
        pop(main->server->client_fd[i]->player->cmd_buf);
    if (strlen(main->server->client_fd[i]->player->act_cmd) > 2) {
        char **tab =
            get_args_from_command(main->server->client_fd[i]->player->act_cmd);
        call_ai_command(tab, main);
        if (main->server->client_fd[i] != NULL) {
            main->server->client_fd[i]->player->time = time(NULL);
            main->server->client_fd[i]->player->command_time =
                get_command_time(tab[0]);
            printf("command %s take time: %d\n", tab[0],
                main->server->client_fd[i]->player->command_time);
            printf("case 0, act_cmd: %s\n",
                main->server->client_fd[i]->player->act_cmd);
        }
    }
}

static void case_1(main_t *main, int i, int act_time)
{
    if ((act_time - main->server->client_fd[i]->player->time)
        >= main->server->client_fd[i]->player->command_time
            * ((float) main->args->freq / 100))
        main->server->client_fd[i]->player->status_cmd = 2;
}

static void case_2(main_t *main, int i)
{
    printf("case 2\n");
    if (strcmp(main->server->client_fd[i]->player->act_cmd, "Incantation")
        == 0) {
        main->server->client_fd[i]->player->status_cmd = 0;
        bool res = check_tile(
            main, CURR_CLI->player->coord->x, CURR_CLI->player->coord->y);
        if (res) {
            dprintf(main->server->client_fd[i]->fd, "ok\n");
            unlock_all(main);
            delete_ressources(
                main, CURR_CLI->player->coord->x, CURR_CLI->player->coord->y);
            level_up_all(main);
            clear_all(main);
        } else {
            dprintf(main->server->client_fd[i]->fd, "ko\n");
            unlock_all(main);
            clear_all(main);
        }
        dprintf(main->server->gui_fd, "pie %d %d %d\n",
            CURR_CLI->player->coord->x, CURR_CLI->player->coord->y, res);
    } else {
        main->server->client_fd[i]->player->status_cmd = 0;
    }
}

void execute_current_command(main_t *main, int i)
{
    int act_time = time(NULL);

    if (main->server->client_fd[i]->player->locked)
        return;
    if (main->server->client_fd[i]->player->status_cmd == 0) {
        case_0(main, i);
    } else if (main->server->client_fd[i]->player->status_cmd == 1)
        case_1(main, i, act_time);
    else if (main->server->client_fd[i]->player->status_cmd == 2)
        case_2(main, i);

    // lock if incantation
    // if ((act_time - main->server->client_fd[i]->player->time)
    //     >= main->server->client_fd[i]->player->command_time
    //         * ((float) main->args->freq / 100)) {
    //     if (list_len(main->server->client_fd[i]->player->cmd_buf) == 0)
    //         return;
    //     if (strlen(main->server->client_fd[i]->player->cmd_buf[0]) > 2)
    //     {
    //         char **tab = get_args_from_command(
    //             pop(main->server->client_fd[i]->player->cmd_buf));
    //         call_ai_command(tab, main);
    //         if (main->server->client_fd[i] != NULL) {
    //             main->server->client_fd[i]->player->time = time(NULL);
    //             main->server->client_fd[i]->player->command_time =
    //                 get_command_time(tab[0]);
    //             printf("command %s take time: %d\n", tab[0],
    //                 main->server->client_fd[i]->player->command_time);
    //         }
    //     }
    // }
}

void execute_player_command(main_t *main)
{
    for (int i = 0; i < MAX_CLI - 1; i++) {
        if (main->server->client_fd[i] != NULL
            && main->server->client_fd[i]->player != NULL) {
            main->server->current_client_index = i;
            execute_current_command(main, i);
        }
    }
}
