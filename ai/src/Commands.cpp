/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Commands
*/

#include "Ai.hpp"

void AI::Forward()
{
    timeToWait = BASESLEEP;
    std::cout << "Forward" << std::endl;
    client.sendData("Forward\n");
    messageFromServer = client.receiveData();
}

void AI::TurnRight()
{
    timeToWait = BASESLEEP;
    std::cout << "Right" << std::endl;
    client.sendData("Right\n");
    messageFromServer = client.receiveData();
}

void AI::TurnLeft()
{
    timeToWait = BASESLEEP;
    std::cout << "Left" << std::endl;
    client.sendData("Left\n");
    messageFromServer = client.receiveData();
}

void AI::LookAround()
{
    timeToWait = BASESLEEP;
    std::cout << "Look" << std::endl;
    client.sendData("Look\n");
    messageFromServer = client.receiveData();
}

void AI::Inventory()
{
    timeToWait = BASESLEEP;
    std::cout << "Inventory" << std::endl;
    client.sendData("Inventory\n");
    messageFromServer = client.receiveData();

}

void AI::BroadcastText(std::string message)
{
    timeToWait = BASESLEEP;
    std::cout << "Broadcast" << std::endl;
    client.sendData("Broadcast " + message + "\n");
    messageFromServer = client.receiveData();
}

void AI::NumberOfTeamUnusedSlots()
{
    std::cout << "Connect_nbr" << std::endl;
    client.sendData("Connect_nbr\n");
    messageFromServer = client.receiveData();
}

void AI::ForkPlayer()
{
    timeToWait = FORKSLEEP;
    std::cout << "Fork" << std::endl;
    client.sendData("Fork\n");
    messageFromServer = client.receiveData();
}

void AI::EjectPlayer()
{
    timeToWait = BASESLEEP;
    std::cout << "Eject" << std::endl;
    client.sendData("Eject\n");
    messageFromServer = client.receiveData();
}

void AI::DeathOfPlayer()
{
}

void AI::TakeObject()
{
    timeToWait = BASESLEEP;
    std::cout << "Take" << std::endl;
    client.sendData("Take\n");
    messageFromServer = client.receiveData();
}

void AI::SetObjectDown(int object, int quantity)
{
    timeToWait = BASESLEEP;
    std::cout << "Set" + std::to_string(object) + " "
        + std::to_string(quantity) + "\n" << std::endl;
    client.sendData("Set" + std::to_string(object) + " "
        + std::to_string(quantity) + "\n");
    messageFromServer = client.receiveData();
}

void AI::StartIncantation()
{
    timeToWait = INCANTATIONSLEEP;
    std::cout << "Incantation" << std::endl;
    client.sendData("Incantation\n");
    messageFromServer = client.receiveData();
}

