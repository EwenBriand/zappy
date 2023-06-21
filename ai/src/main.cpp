/*
** EPITECH PROJECT, 2023
** B-YEP-400-BAR-4-1-zappy-clement.toni
** File description:
** main
*/

#include "Client.hpp"
#include "Ai.hpp"

int main(int argc, char **argv)
{
    if (argc != 7) {
        std::cerr << "Usage: ./zappy_ai -p port -n name -h machine" << std::endl;
        return 1;
    }
    std::string hostname;
    std::string teamName;
    int port;
    int opt;

    while ((opt = getopt(argc, argv, "p:n:h:")) != -1) {
        switch (opt) {
            case 'p':
                port = std::stoi(optarg);
                break;
            case 'n':
                teamName = std::string(optarg);
                break;
            case 'h':
                hostname = std::string(optarg);
                break;
            default:
                std::cerr << "Usage: ./zappy_ai -p port -n name -h machine" << std::endl;
                return 1;
        }
    }
    try {
        AI ai(hostname, port, teamName);
        ai.Loop();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
