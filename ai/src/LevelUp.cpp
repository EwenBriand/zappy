/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** LevelUp
*/

#include "Ai.hpp"

void AI::CheckInventoryAndSetObjects()
{
    const std::array<std::array<int, 6>, 7> requirementLevels = {{
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {2, 0, 1, 0, 2, 0},
        {1, 1, 2, 0, 1, 0},
        {1, 2, 1, 3, 0, 0},
        {1, 2, 3, 0, 1, 0},
        {2, 2, 2, 2, 2, 1}
    }};

    bool canLevelUp = true;
    for (int i = 0; i < 6; i++) {
        if (inventory.getResource(i) < requirementLevels[level-1][i]) {
            canLevelUp = false;
            break;
        }
    }
    if (canLevelUp) {
        incantationSoon = true;
        FindResourceInVision();
        for (int i = 0; i < 6; i++) {
            int requiredResource = requirementLevels[level-1][i];
            if (requiredResource > 0) {
                if (CheckSameTileOtherAI()) {
                    SetObjectDown(i + 1, requiredResource);
                    UpdateInventory();
                }
            }
        }
    }
}

void AI::CheckLevelUp()
{
    CheckInventoryAndSetObjects();
    if (incantationSoon) {
        std::string levelUpMessage = "Ready_level_" + std::to_string(level + 1);
        BroadcastText(levelUpMessage);
        if (CheckSameTileOtherAI()) {
            StartIncantation();
        }
        if (CheckSameTileOtherAI()) {
            StartIncantation();
            if (messageFromServer != "ok\n") {
                StartIncantation();
            } else {
                level++;
                incantationSoon = false;
            }
        }
    }
}
