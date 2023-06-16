teams=("team1" "team1" "team2" "team2" "team3" "team4" "team1" "team1" "team2" "team2" "team3" "team4" "team5" "team5" "team1" "team1" "team2" "team2" "team3" "team4" "team1" "team1" "team2" "team2" "team3" "team4" "team5" "team5")
host="127.0.0.1"
port=8080

for team in "${teams[@]}"; do
    ./zappy_ai -p "$port" -n "$team" -h "$host" &
    sleep 1
done
