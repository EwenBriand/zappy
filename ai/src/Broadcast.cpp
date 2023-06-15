/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Broadcast
*/

#include "Ai.hpp"

void AI::HandleIncomingMessages()
{
    if (messageFromServer.substr(0, 8) == "message ") {
        size_t commaPos = messageFromServer.find(",");
        std::string directionStr = messageFromServer.substr(8, commaPos - 8);
        std::string text = messageFromServer.substr(commaPos + 1);

        int direction = std::stoi(directionStr);
        std::cout << "Server broadcast direction " << direction << ": " << text << std::endl;

        auto msg = splitString(text, ' ');
        if (msg[0] == "Ready" && msg[2] == "level") {
            int levelInMessage = std::stoi(msg[3]);
            broadcastLevel = levelInMessage;
            if (levelInMessage == level + 1 && incantationSoon) {
                TurnToDirection(direction);
                Forward();
                LookAround();
            }
        }
    }
}


