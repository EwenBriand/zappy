/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** ia
*/

#ifndef IA_HPP_
    #define IA_HPP_
    #include <string>
    #include <iostream>
    #include <unistd.h>
    #include <getopt.h>
    #include <cerrno>
    #include "Client.hpp"
    #define BASESLEEP usleep(700000/freq);
    #define INCANTATIONSLEEP usleep(3000000/freq);
    #define FORKSLEEP usleep(42000000/freq);

class AI {
    enum Direction {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    public:
        AI(const std::string &hostname, int port, const std::string teamName);
        ~AI();
        void Loop();
        void Forward();
        void TurnRight();
        void TurnLeft();
        void LookAround();
        void Inventory();
        void BroadcastText(std::string message);
        void NumberOfTeamUnusedSlots();
        void ForkPlayer();
        void EjectPlayer();
        void DeathOfPlater();
        void TakeObject();
        void SetObjectDown();
        void StartIncantation();

    private:
        // inventory
        bool alive = true;
        Client client;
        std::string teamName;

        int level = 1;
        int food = 10;
        std::string messageFromServer;
        std::string inventory;
        int orientation = NORTH;
        int freq;
        bool MoveX = 0;
        bool MoveY = 0;
};

#endif /* !IA_HPP_ */
