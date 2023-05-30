/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_
    #include <string>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <iostream>
    #include <cerrno>

class Client {
    public:
        Client(const std::string &hostname, int port);
        bool connectToServer();
        std::string receiveData();
        void sendData(const std::string &message);
    private:
        std::string hostname;
        int port;
        int socketFD;
};

#endif /* !CLIENT_HPP_ */
