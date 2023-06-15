/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** init_dest
*/

#pragma once

#include "struct.h"

server_t *init_server(args_t *args);
void destroy_server(server_t *server);

client_t *client_init(int fd);
void destroy_client(client_t *client);

main_t *init_main(int argc, char **argv);
void destroy_main(main_t *main);

player_t *init_player_char(main_t *main);
player_t *init_player(egg_t *egg);
void destroy_player(player_t *player);

egg_t *init_egg(main_t *main, int i);
void destroy_egg(egg_t *egg);

void init_teams(main_t *main);
void destroy_teams(main_t *main);

args_t *get_data_from_args(int ac, char **av);
void destroy_args(args_t *args);
