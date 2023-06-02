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
    std::cout << "waiting for server message..." << std::endl;
    client.sendData("pnw_0_0_0_1_1_" + teamName + "\n");
    sleep(1);
    messageFromServer = client.receiveData();
    //TODO : remove frequency logique and put a 10 buffer inside the server.
    std::cout << "Message from server start: " << messageFromServer << std::endl;
    freq = atoi(messageFromServer.c_str());
}

AI::~AI()
{
}

void AI::Loop()
{
    while (alive) {
        printf("Loop\n");
        // Forward();
        Inventory();
        printf("Inventory sent\n");
        messageFromServer = client.receiveData();
        std::cout << "Message from server: " << messageFromServer << std::endl;
    }
}

void AI::Forward()
{
    BASESLEEP
    client.sendData("Forward\n");
}

void AI::TurnRight()
{
    BASESLEEP
    client.sendData("Right\n");
}

void AI::TurnLeft()
{
    BASESLEEP
    client.sendData("Left\n");
}

void AI::LookAround()
{
    BASESLEEP
    client.sendData("Look\n");
}

void AI::Inventory()
{
    BASESLEEP
    client.sendData("Inventory\n");
}

void AI::BroadcastText(std::string message)
{
    BASESLEEP
    client.sendData("Broadcast " + message + "\n");
}

void AI::NumberOfTeamUnusedSlots()
{
    client.sendData("Connect_nbr\n");
}

void AI::ForkPlayer()
{
    FORKSLEEP
    client.sendData("Fork\n");
}

void AI::EjectPlayer()
{
    BASESLEEP
    client.sendData("Eject\n");
}

void AI::DeathOfPlater()
{

}

void AI::TakeObject()
{
    BASESLEEP
    client.sendData("Take Object\n");
}

void AI::SetObjectDown()
{
    BASESLEEP
    client.sendData("Set Object Down\n");
}

void AI::StartIncantation()
{
    INCANTATIONSLEEP
    client.sendData("Incantation\n");
}