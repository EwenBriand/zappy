/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** BaseLogic
*/

#include "Ai.hpp"

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

std::string AI::PrioritizeResources()
{
    const std::array<std::array<int, 6>, 7> requirementLevels = {
        {{1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0}, {2, 0, 1, 0, 2, 0},
            {1, 1, 2, 0, 1, 0}, {1, 2, 1, 3, 0, 0}, {1, 2, 3, 0, 1, 0},
            {2, 2, 2, 2, 2, 1}}};
    const std::array<std::string, 6> resourceNames = {
        "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"};

    if (inventory.getFood() <= 4)
        return "food";

    for (size_t i = 0; i < resourceNames.size(); ++i) {
        if (requirementLevels[level - 1][i] > 0) {
            if (resourceNames[i] == "linemate"
                && inventory.getLinemate() < requirementLevels[level - 1][i])
                return "linemate";
            else if (resourceNames[i] == "deraumere"
                && inventory.getDeraumere() < requirementLevels[level - 1][i])
                return "deraumere";
            else if (resourceNames[i] == "sibur"
                && inventory.getSibur() < requirementLevels[level - 1][i])
                return "sibur";
            else if (resourceNames[i] == "mendiane"
                && inventory.getMendiane() < requirementLevels[level - 1][i])
                return "mendiane";
            else if (resourceNames[i] == "phiras"
                && inventory.getPhiras() < requirementLevels[level - 1][i])
                return "phiras";
            else if (resourceNames[i] == "thystame"
                && inventory.getThystame() < requirementLevels[level - 1][i])
                return "thystame";
        }
    }
    return "food";
}

int AI::FindResourceInVision()
{
    LookAround();
    if (messageFromServer == "ok\n")
        LookAround();
    std::cout << "Look FromServer: " << messageFromServer << std::endl;
    std::vector<std::string> vision = splitString(messageFromServer, ',');
    std::string priorityResource = PrioritizeResources();

    std::cout << "priorityResource: " << priorityResource << std::endl;

    for (int i = 0; i < vision.size(); i++) {
        if (!vision[i].empty() && vision[i][0] == ' ')
            vision[i].erase(0, 1);

        std::vector<std::string> tileContents = splitString(vision[i], ' ');
        for (const std::string &object : tileContents) {
            // if (i == 0 && incantationSoon && object == "player" && std::count(tileContents.begin(), tileContents.end(), "player") > 1) {
            //     // EjectPlayer();
            //     return -1;
            // }
            if (object == priorityResource)
                return i;
            if (object == "player" && std::count(tileContents.begin(), tileContents.end(), "player") > 1 && incantationSoon && level > 1 && priorityResource != "food" && broadcastActive)
                return i;
        }
    }
    return -1;
}
bool AI::CheckSameTileOtherAI()
{
    static const std::array<int, 7> requiredPlayersPerLevel = {1, 2, 2, 4, 4, 6, 6};
    LookAround();
    std::cout << "Look FromServer: " << messageFromServer << std::endl;
    std::vector<std::string> vision = splitString(messageFromServer, ',');
    std::vector<std::string> tileContents = splitString(vision[0], ' ');
    int playerCount = std::count(tileContents.begin(), tileContents.end(), "player");

    if (playerCount >= requiredPlayersPerLevel[this->level - 1]) {
        return true;
    }
    return false;
}
