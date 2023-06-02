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
    std::cout << "Message from server: " << messageFromServer << std::endl;
    freq = atoi(messageFromServer.c_str());
}

AI::~AI()
{
}

void AI::UpdateInventory() {
    client.sendData("Inventory\n");
    usleep(500000);
    std::string inventoryMessage = client.receiveData();
    usleep(500000);
    inventory.parse(inventoryMessage);
}

void AI::TurnToDirection(int desiredDirection)
{
    while (orientation != desiredDirection) {
        if ((orientation + 1) % 4 == desiredDirection) {
            TurnRight();
            orientation = (orientation + 1) % 4;
        } else {
            TurnLeft();
            orientation = (orientation - 1 + 4) % 4;
        }
    }
}

std::vector<std::string> AI::splitString(const std::string &str, char delim)
{
    std::vector<std::string> elems;
    std::string elem;
    std::istringstream elemStream(str);
    while (std::getline(elemStream, elem, delim))
        elems.push_back(elem);
    return elems;
}

int AI::FindFoodInVision()
{
    LookAround();
    usleep(500000);
    messageFromServer = client.receiveData();
    usleep(500000);
    std::vector<std::string> vision = splitString(messageFromServer, ',');

    for (int i = 0; i < vision.size(); i++) {
        std::vector<std::string> tileContents = splitString(vision[i], ' ');
        for (const std::string &object : tileContents) {
            if (object == "food")
                return i;
        }
    }
    return -1;
}

void AI::Loop()
{
    while (alive) {
        int directionToFood = FindFoodInVision();
        if (directionToFood != -1) {
            TurnToDirection(directionToFood);
            Forward();
        } else
            Forward();
        usleep(500000);
    }
}

void AI::Forward()
{
    BASESLEEP
    std::string cmb;
    cmb = "Forward\n";
    client.sendData(cmb);
}

void AI::TurnRight()
{
    BASESLEEP
    std::string cmb;
    cmb = "Right\n";
    client.sendData(cmb);
}

void AI::TurnLeft()
{
    BASESLEEP
    std::string cmb;
    cmb = "Left\n";
    client.sendData(cmb);
}

void AI::LookAround()
{
    BASESLEEP
    std::string cmb;
    cmb = "Look\n";
    client.sendData(cmb);
}

void AI::BroadcastText(std::string message)
{

}

void AI::NumberOfTeamUnusedSlots()
{

}

void AI::ForkPlayer()
{

}

void AI::EjectPlayer()
{

}

void AI::DeathOfPlayer()
{

}

void AI::TakeObject()
{

}

void AI::SetObjectDown()
{

}

void AI::StartIncantation()
{

}