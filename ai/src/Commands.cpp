/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Commands
*/

#include "Ai.hpp"

void AI::Forward()
{
    std::cout << "Forward" << std::endl;
    client.sendData("Forward\n");
    messageFromServer = client.receiveData();
}

void AI::TurnRight()
{
    std::cout << "Right" << std::endl;
    client.sendData("Right\n");
    messageFromServer = client.receiveData();
}

void AI::TurnLeft()
{
    std::cout << "Left" << std::endl;
    client.sendData("Left\n");
    messageFromServer = client.receiveData();
}

void AI::LookAround()
{
    std::cout << "Look" << std::endl;
    client.sendData("Look\n");
    messageFromServer = client.receiveData();
}

void AI::Inventory()
{
    std::cout << "Inventory" << std::endl;
    client.sendData("Inventory\n");
    messageFromServer = client.receiveData();

}

void AI::BroadcastText(std::string message)
{
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
    std::cout << "Fork" << std::endl;
    client.sendData("Fork\n");
    messageFromServer = client.receiveData();
}

void AI::EjectPlayer()
{
    std::cout << "Eject" << std::endl;
    client.sendData("Eject\n");
    messageFromServer = client.receiveData();
}

void AI::DeathOfPlayer()
{
}

void AI::TakeObject()
{
    std::cout << "Take" << std::endl;
    client.sendData("Take\n");
    messageFromServer = client.receiveData();
}

void AI::SetObjectDown(int object, int quantity)
{
    std::cout << "Set: " + std::to_string(object) + " "
        + std::to_string(quantity) + "\n" << std::endl;
    client.sendData("Set " + std::to_string(object) + " "
        + std::to_string(quantity) + "\n");
    messageFromServer = client.receiveData();
}

void AI::StartIncantation()
{
    std::cout << "Incantation" << std::endl;
    client.sendData("Incantation\n");
    messageFromServer = client.receiveData();
}

