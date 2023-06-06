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
    #define BASESLEEP 700000000/freq; //this is 7s
    #define INCANTATIONSLEEP 30000000000/freq;
    #define FORKSLEEP 4200000000/freq;

class AI {
    enum Direction {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    class InventoryContent {
        int linemate;
        int sibur;
        int deraumere;
        int mendiane;
        int phiras;
        int thystame;
    public:
        InventoryContent() : linemate(0), sibur(0), deraumere(0), mendiane(0), phiras(0), thystame(0) {}
        void parse(std::string inventoryMessage) {
            std::string tmp;
            int i = 0;
            while (inventoryMessage[i] != '\0') {
                if (inventoryMessage[i] == ' ') {
                    if (tmp == "linemate") {
                        linemate = atoi(inventoryMessage.substr(i + 1).c_str());
                    } else if (tmp == "sibur") {
                        sibur = atoi(inventoryMessage.substr(i + 1).c_str());
                    } else if (tmp == "deraumere") {
                        deraumere = atoi(inventoryMessage.substr(i + 1).c_str());
                    } else if (tmp == "mendiane") {
                        mendiane = atoi(inventoryMessage.substr(i + 1).c_str());
                    } else if (tmp == "phiras") {
                        phiras = atoi(inventoryMessage.substr(i + 1).c_str());
                    } else if (tmp == "thystame") {
                        thystame = atoi(inventoryMessage.substr(i + 1).c_str());
                    }
                    tmp = "";
                } else
                    tmp += inventoryMessage[i];
                i++;
            }
        }
    };

    public:
        AI(const std::string &hostname, int port, const std::string teamName);
        ~AI();
        void WelcomeProtocol();
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
        bool Waiter();

    private:
        bool alive = true;
        Client client;
        std::string teamName;
        int level = 1;
        int food = 10;
        std::string messageFromServer;
        int orientation = NORTH;
        int freq;
        bool MoveX = 0;
        bool MoveY = 0;
        int clientNbrRemain;
        int x = 0;
        int y = 0;
        InventoryContent inventory;
        std::chrono::time_point<std::chrono::system_clock> start;
        std::chrono::time_point<std::chrono::system_clock> end;
        int timeToWait = 0;

        void UpdateInventory();
};

#endif /* !IA_HPP_ */