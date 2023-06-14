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
        void parse(const std::string inventoryMessage);
        void assignValue(const std::string &name, int value);
        int getResource(int i);
        int getFood() { return food; }
        int getLinemate() { return linemate; }
        int getSibur() { return sibur; }
        int getDeraumere() { return deraumere; }
        int getMendiane() { return mendiane; }
        int getPhiras() { return phiras; }
        int getThystame() { return thystame; }
        void setFood(int food) { this->food = food; }
        void setLinemate(int linemate) { this->linemate = linemate; }
        void setSibur(int sibur) { this->sibur = sibur; }
        void setDeraumere(int deraumere) { this->deraumere = deraumere; }
        void setMendiane(int mendiane) { this->mendiane = mendiane; }
        void setPhiras(int phiras) { this->phiras = phiras; }
        void setThystame(int thystame) { this->thystame = thystame; }
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
        void SetObjectDown(int object, int quantity);
        void StartIncantation();
        bool Waiter();
        void AllPlayerLevel();

    private:
        bool alive = true;
        Client client;
        std::string teamName;
        std::string hostname;
        int port;
        int level = 1;
        int food = 10;
        int broadcastLevel = 0;
        bool incantationSoon = false;
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
        void CheckInventoryAndSetObjects();
        void CheckLevelUp();
        void HandleIncomingMessages();
        void ForkPlayerEgg();
        bool CheckSameTileOtherAI();
};

#endif /* !IA_HPP_ */
