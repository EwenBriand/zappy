/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Ai
*/

#include "Ai.hpp"

AI::AI(const std::string &hostname, int port, const std::string teamName) :
client(hostname, port), teamName(teamName)
{
    if (!client.connectToServer()) {
        std::cerr << "Could not connect to server" << std::endl;
        return;
    }
    start = std::chrono::system_clock::now();
    WelcomeProtocol();
    std::cout << "waiting for server message..." << std::endl;
    client.sendData("pnw_0_0_0_1_1_" + teamName + "\n");
    messageFromServer = client.receiveData();
    freq = atoi(messageFromServer.c_str());
}

AI::~AI()
{
}

void AI::Loop()
{
    int i = 0;
    while (alive) {
        if (Waiter()) {

        i++;
        printf("Loop %d\n", i);
        // Forward();
        LookAround();
        // Inventory();
        // printf("Inventory sent\n");

        messageFromServer = client.receiveData();
        std::cout << "Message from server: " << messageFromServer << std::endl;
        // if (messageFromServer.find("dead") != std::string::npos) {
        //     alive = false;
        //     break;
        // }
        }
    }
}

void AI::WelcomeProtocol()
{
    messageFromServer = client.receiveData(); // get Welcome message
    client.sendData(teamName + "\n"); //send team name
    messageFromServer = client.receiveData(); // get team name
    clientNbrRemain = atoi(messageFromServer.c_str()); // get client number
    messageFromServer = client.receiveData(); // get map size
    x = atoi(messageFromServer.substr(0, messageFromServer.find(" ")).c_str());
    y = atoi(messageFromServer.substr(messageFromServer.find(" ") + 1, messageFromServer.find("\n")).c_str());
}

void AI::UpdateInventory()
{
    client.sendData("Inventory\n");
    std::string inventoryMessage = client.receiveData();
}

bool AI::Waiter()
{
    auto currentTime = std::chrono::system_clock::now();
    auto elapsed_seconds = currentTime - start;
    if (elapsed_seconds.count() >= timeToWait) {
        start = std::chrono::system_clock::now();
        return true;
    }
    return false;
}

void AI::Forward()
{
    timeToWait = BASESLEEP;
    std::cout << "Forward?" << std::endl;
    client.sendData("Forward\n");
}

void AI::TurnRight()
{
    timeToWait = BASESLEEP;
    client.sendData("Right\n");
}

void AI::TurnLeft()
{
    timeToWait = BASESLEEP;
    client.sendData("Left\n");
}

void AI::LookAround()
{
    timeToWait = BASESLEEP;
    client.sendData("Look\n");
}

void AI::Inventory()
{
    timeToWait = BASESLEEP;
    client.sendData("Inventory\n");
}

void AI::BroadcastText(std::string message)
{
    timeToWait = BASESLEEP;
    client.sendData("Broadcast " + message + "\n");
}

void AI::NumberOfTeamUnusedSlots()
{
    client.sendData("Connect_nbr\n");
}

void AI::ForkPlayer()
{
    timeToWait = FORKSLEEP
    client.sendData("Fork\n");
}

void AI::EjectPlayer()
{
    timeToWait = BASESLEEP;
    client.sendData("Eject\n");
}

void AI::DeathOfPlater()
{

}

void AI::TakeObject()
{
    timeToWait = BASESLEEP;
    client.sendData("Take Object\n");
}

void AI::SetObjectDown()
{
    timeToWait = BASESLEEP;
    client.sendData("Set Object Down\n");
}

void AI::StartIncantation()
{
    timeToWait = INCANTATIONSLEEP
    client.sendData("Incantation\n");
}