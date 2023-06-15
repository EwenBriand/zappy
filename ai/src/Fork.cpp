/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Fork
*/

#include "Ai.hpp"

void AI::ForkPlayerEgg()
{
    NumberOfTeamUnusedSlots();
    std::cout << "Connect_nbr FromServer: " << messageFromServer << std::endl;
    if (messageFromServer == "0\n")
        return;
    ForkPlayer();
    std::cout << "Fork FromServer: " << messageFromServer << std::endl;
    if (messageFromServer == "ok\n") {
        pid_t pid = fork();
        if (pid == 0) {
            AI newAI(this->hostname, this->port, this->teamName);
            newAI.Loop();
        } else if (pid < 0) {
            std::cerr << "Erreur lors du fork" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}
