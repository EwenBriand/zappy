/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** incantation
*/

#pragma once

#include "struct.h"

void lock_all(main_t *main);
void clear_all(main_t *main);
void unlock_all(main_t *main);
void level_up_all(main_t *main);
void delete_ressources(main_t *main, int x, int y);
bool check_tile(main_t *main, int x, int y);
int get_all_lvl(main_t *main, int lvl);
