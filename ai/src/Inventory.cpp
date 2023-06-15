/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Inventory
*/

#include "Ai.hpp"

void AI::UpdateInventory()
{
    Inventory();
    std::string inventoryMessage = client.receiveData();
    inventory.parse(inventoryMessage);
    std::cout << "food: " << inventory.getFood() << std::endl;
    std::cout << "linemate: " << inventory.getLinemate() << std::endl;
    std::cout << "sibur: " << inventory.getSibur() << std::endl;
    std::cout << "deraumere: " << inventory.getDeraumere() << std::endl;
    std::cout << "mendiane: " << inventory.getMendiane() << std::endl;
    std::cout << "phiras: " << inventory.getPhiras() << std::endl;
    std::cout << "thystame: " << inventory.getThystame() << std::endl;
}

void AI::InventoryContent::parse(std::string inventoryMessage)
{
    if(inventoryMessage.size() < 2) return;
    std::cout << "inventoryMessage from server : " << inventoryMessage << std::endl;
    inventoryMessage = inventoryMessage.substr(1, inventoryMessage.size() - 2);
    std::string delimiter = ", ";
    size_t pos = 0;
    std::string item;

    while ((pos = inventoryMessage.find(delimiter)) != std::string::npos) {
        item = inventoryMessage.substr(0, pos);
        inventoryMessage.erase(0, pos + delimiter.length());

        std::string name;
        int value;
        std::stringstream ss(item);
        ss >> name >> value;

        assignValue(name, value);
    }
    std::string name;
    int value;
    std::stringstream ss(inventoryMessage);
    ss >> name >> value;

    assignValue(name, value);
}

void AI::InventoryContent::assignValue(const std::string &name, int value)
{
    if (name == "food") {
        setFood(value);
    } else if (name == "linemate") {
        setLinemate(value);
    } else if (name == "sibur") {
        setSibur(value);
    } else if (name == "deraumere") {
        setDeraumere(value);
    } else if (name == "mendiane") {
        setMendiane(value);
    } else if (name == "phiras") {
        setPhiras(value);
    } else if (name == "thystame") {
        setThystame(value);
    }
}

int AI::InventoryContent::getResource(int i)
{
    if (i == 0)
        return getLinemate();
    else if (i == 1)
        return getDeraumere();
    else if (i == 2)
        return getSibur();
    else if (i == 3)
        return getMendiane();
    else if (i == 4)
        return getPhiras();
    else if (i == 5)
        return getThystame();
    return 0;
}
