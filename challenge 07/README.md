# Modbus simulator

Building a modbus simulator using pymodbus and changing the register values using MITM attack.

## How it works?
- open a terminal and run the server.py script. This will start a server on localhost port 5020
![starting](https://github.com/navneethtj/bi0sHardware/assets/143018158/2110327e-d1a7-4f2a-8403-2056e0da93b8)

- now open a seperate terminal and run the script original_cleint .py, this is initialize the client and send the vales [10,20,30,40,50]. Then the client will wait for 10 seconds using time.sleep(), and then reads back the values which were previously written.

- now open a new terminal and run the script mitm_client .py, this will intercept and modify the original values. each and every registers will be incremented by 1.

- after 10 seconds, when the client reads back the value from server, it will read [11,21,31,41,51] instread of [10,20,30,40,50]. Thus MITM_client was succesfully able to modify the original values.
![running](https://github.com/navneethtj/bi0sHardware/assets/143018158/fb34eff2-7645-4ff2-8547-ad2ed8f67d52)

- note that all these are connected to the same network (127.0.0.1)
