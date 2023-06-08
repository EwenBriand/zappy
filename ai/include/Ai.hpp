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
    #include <cstring>
    #include <vector>
    #include <sstream>
    #include <cstdlib>
    #include <ctime>
    #include <chrono>
    #include <thread>
    #include <algorithm>
    #include <random>
    #include <map>
    #include <fstream>
    #include <cmath>
    #include <iomanip>
    #include <csignal>
    #include <array>
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
        int food;
        int linemate;
        int sibur;
        int deraumere;
        int mendiane;
        int phiras;
        int thystame;
    public:
        InventoryContent() : food(10), linemate(0), sibur(0), deraumere(0), mendiane(0), phiras(0), thystame(0) {}
        void parse(std::string inventoryMessage, const std::function<std::vector<std::string>(const std::string &, char)> &splitString) {
            std::vector<std::string> items = splitString(inventoryMessage, ',');
            for (const auto &item : items) {
                std::string name = splitString(item, ' ')[0];
                int value = std::stoi(splitString(item, ' ')[1]);
                if (name == "food") food = value;
                else if (name == "linemate") linemate = value;
                else if (name == "sibur") sibur = value;
                else if (name == "deraumere") deraumere = value;
                else if (name == "mendiane") mendiane = value;
                else if (name == "phiras") phiras = value;
                else if (name == "thystame") thystame = value;
            }
        }
        int getFood() { return food; }
        int getLinemate() { return linemate; }
        int getSibur() { return sibur; }
        int getDeraumere() { return deraumere; }
        int getMendiane() { return mendiane; }
        int getPhiras() { return phiras; }
        int getThystame() { return thystame; }
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
        void DeathOfPlayer();
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
        void TurnToDirection(int desiredDirection);
        std::vector<std::string> splitString(const std::string &str, char delimiter);
        std::string PrioritizeResources();
        int FindResourceInVision();
        // void CheckLevelUp();
};

#endif /* !IA_HPP_ */
