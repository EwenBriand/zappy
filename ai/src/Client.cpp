/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Client
*/

#include "Client.hpp"

Client::Client(const std::string& hostname, int port)
    : hostname(hostname), port(port), socketFD(-1) {}

bool Client::connectToServer()
{
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD == -1) {
        perror("Socket creation failed");
        return false;
    }
    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname.c_str(), &(serverAddress.sin_addr)) <= 0) {
        perror("Invalid address or address not supported");
        return false;
    }
    if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Connection to the server failed");
        return false;
    }

    return true;
}

std::string Client::receiveData()
{
    char buffer[1024] = {0};
    read(socketFD, buffer, 1024);
    return std::string(buffer);
}

void Client::sendData(const std::string &message)
{
    send(socketFD, message.c_str(), message.size(), 0);
}
