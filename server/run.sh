# ipconfig getifaddr en0
# clear ; make && ./zappy_server -p 8080 -x 10 -y 10 -n team1 team2 team3 team4 team5 -c 10 -f 800
clear ; make re && valgrind ./zappy_server -p 8080 -x 10 -y 10 -n team1 team2 team3 team4 -c 10 -f 100
