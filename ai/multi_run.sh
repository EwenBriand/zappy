#!/bin/bash

# Command to be executed
command_to_run="./zappy_ai -p 8080 -n team1 -h 127.0.0.1"

# Number of times to run the command
num_times=5

# Loop to run the command multiple times
for ((i=1; i<=$num_times; i++))
do
    echo "Running command $i"
    sleep 1
    ($command_to_run) &
done

# Wait for all background processes to complete
wait

echo "All commands completed"
