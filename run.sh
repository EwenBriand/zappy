# ipconfig getifaddr en0
cd ./server && make && mv zappy_server ../ && cd ../
cd ./ai && make && mv zappy_ai ../ && cd ../
./zappy_server -p 8080 -x 12 -y 12 -n team1 team2 team3 team4 -c 5 -f 100