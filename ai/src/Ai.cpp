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
    int i = 0;
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

void AI::DeathOfPlayer()
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