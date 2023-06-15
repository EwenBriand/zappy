/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Utils
*/

#include "Ai.hpp"

std::vector<std::string> AI::splitString(const std::string &str, char delim)
{
    std::vector<std::string> elems;
    std::string elem;
    std::istringstream elemStream(str);
    while (std::getline(elemStream, elem, delim))
        elems.push_back(elem);
    return elems;
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
