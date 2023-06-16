import telnetlib
import time
import asyncio
import threading
import random
# Telnet connection settings
HOST = "127.0.0.1"
PORT = "8080"
TIMEOUT = 5
tn = telnetlib.Telnet(HOST, PORT, TIMEOUT)

def send(str):
    str = str + "\n"
    tn.write(str.encode("utf-8"))

def recieve():
    res = tn.read_very_eager().decode("utf-8")
    print(res)


def welcome():
    recieve() #welcome msg
    send("team" + str(random.randint(1, 4))) #team name
    time.sleep(1) # Wait for the command to execute
    recieve() #cli nbr
    recieve() #map

def getLine():
    cmd = input("Enter command: ")
    # check is still connected
    send(cmd)
    recieve()

welcome()

while True:
    getLine()

