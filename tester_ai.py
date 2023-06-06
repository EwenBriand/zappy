import telnetlib
import time
import asyncio
import threading

# Telnet connection settings
HOST = "127.0.0.1"
PORT = "8080"
TIMEOUT = 5

# Commands to send
commands = [
    "msz 8 8\r\n",
    "bct 1 1\r\n",
    "mct\r\n",
    "tna\r\n",
    # Add more commands here
]
# create a thread that connect a new player
async def connectNewPlayer():
    # tn.write(b"connect_nbr\r\n")
    # time.sleep(1)  # Wait for the command to execute
    # response = tn.read_very_eager().decode("utf-8")
    # print(f"Response for '{command}':\n{response}")
    time.sleep(1) # Wait for the command to execute
    res = tn.read_very_eager().decode("utf-8")
    print(res)
    tn.write(b"team1\r\n")
    time.sleep(1)  # Wait for the command to execute
    res = tn.read_very_eager().decode("utf-8")
    print(res)

def connectGui():
    tn.write(b"helloGui\r\n")
    for command in commands:
        tn.write(command.encode("utf-8") + b"\n")
        time.sleep(1)  # Wait for the command to execute
        response = tn.read_very_eager().decode("utf-8")
        print(f"Response for '{command}':\n{response}")
        time.sleep(1)  # Wait for the command to execute


tn = telnetlib.Telnet(HOST, PORT, TIMEOUT)

th2 = threading.Thread(target=connectNewPlayer)
th1 = threading.Thread(target=connectGui)

th1.start()
th2.start()
th1.join()
th2.join()

tn.close()


