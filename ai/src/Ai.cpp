/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Ai
*/

#include "Ai.hpp"

AI::AI(const std::string &hostname, int port, const std::string teamName)
    : client(hostname, port), teamName(teamName)
{
    this->hostname = hostname;
    this->port = port;
    if (!client.connectToServer()) {
        std::cerr << "Could not connect to server" << std::endl;
        return;
    }
    start = std::chrono::system_clock::now();
    WelcomeProtocol();
    std::cout << "waiting for server message..." << std::endl;
    // client.sendData("pnw 0 0 0 " + teamName + "\n");
    // messageFromServer = client.receiveData();
    freq = 100;
}

AI::~AI()
{
}

void AI::WelcomeProtocol()
{
    messageFromServer = client.receiveData(); // get Welcome message
    client.sendData(teamName + "\n");         // send team name
    clientNbrRemain = atoi(client.receiveData().c_str()); // get client number
    messageFromServer = client.receiveData();             // get map size
    x = atoi(messageFromServer.substr(0, messageFromServer.find(" ")).c_str());
    y = atoi(messageFromServer
                 .substr(messageFromServer.find(" ") + 1,
                     messageFromServer.find("\n"))
                 .c_str());
    std::cout << "END OF WELCOME" << std::endl;
}

void AI::Loop()
{
    int i = 0;
    messageFromServer = client.receiveData();
    while (alive) {
        if (Waiter()) {
            int directionToResource = FindResourceInVision();
            HandleIncomingMessages();
            UpdateInventory();
            if (directionToResource != -1) {
                TurnToDirection(directionToResource);
                Forward();
                TakeObject();
                if (messageFromServer == "ok\n")
                    UpdateInventory();
                std::cout << "level avant: " << level << std::endl;
                CheckLevelUp();
                std::cout << "level après: " << level << std::endl;
            } else {
                std::cout << "level avant: " << level << std::endl;
                // CheckLevelUp();
                std::cout << "level après: " << level << std::endl;
                Forward();
            }
            i++;
            // if (i % 150 == 0)
            //     ForkPlayerEgg();
        }
    }
}
