# Client - Server Chat-bot

Simple server client chat bot written in C++ adapted from workshop by ACM IIT Roorkee Student Chapter.

## What does it do?
It creates a connection to the server and can send and recieve text messages. 

## Built With:
* C++ 
* Socket Programming

## Usage:
1. Clone the repo.
2. Use either the TCP or UDP choose relevant directory.
3. Open terminal and compile the files server.cpp and client.cpp
```
g++ server.cpp -o server
g++ client.cpp -o client
```
4. Start the server on a specified port.
```
./server PORT
```
5. In another terminal window connect the client to server.
```
./client localhost PORT
```
##### Sidenote:
NOTE: If you compile it on a windows machine, it might throw an error:
```
server.cpp:2:10: fatal error: sys/socket.h: No such file or directory
    2 | #include <sys/socket.h>
      |          ^~~~~~~~~~~~~~
compilation terminated.
```
This happens as: 
```
<sys/socket.h> is for UNIX/Linux.

For windows, you use <Winsock2.h>. You'll also need to link against Ws2_32.lib and call WSAStartup to use WinSock.
```

## Acknowledgments:
* ACM IIT Roorkee Student Chapter
* https://stackoverflow.com/questions/22432910/makefile-error-sys-socket-h-no-such-file-or-directory-under-windows
* https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/
* https://www.geeksforgeeks.org/udp-server-client-implementation-c/
