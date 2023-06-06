/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** gui_commands
*/

#include "ftp.h"

void call_gui_command(main_t *main, int i, char **tab)
{
    printf("in gui command\n");
    for (int i = 0; commands_gui[i].command; i++) {
        printf("tab[0] = %s\n", tab[0]);
        printf("commands_gui[i].command = %s\n", commands_gui[i].command);
        if (strcmp(tab[0], commands_gui[i].command) == 0) {
            commands_gui[i].func(tab, main);
            return;
        }
    }
}
