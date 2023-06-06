/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** gui_commands
*/

#include "ftp.h"

void call_gui_command(main_t *main, int i, char **tab)
{
    for (int i = 0; commands_gui[i].command; i++) {
        if (strcmp(tab[0], commands_gui[i].command) == 0) {
            usleep(10000);
            commands_gui[i].func(tab, main);
            return;
        }
    }
}
