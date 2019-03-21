# TCP Client - Server using boost::asio

This is a simple project to demonstrate the asynchronous communication between a client and a server using boost::asio library. Once the connection between the client and server is established, message can be sent and received.

## Prerequisites

This project was tested on,
* OS: Linux (Ubuntu 16.04 LTS)
* Compiler: g++ (version 7)
* CMake: Minimum version 3 (**required**)

## Compiling

Assuming one has checked out the repository,

Run the following command

```
./compile
```

The binaries will generated inside the *build/* directory.

## Program Execution

Once the project has been successully compiled, open a terminal and  run the following commands,

```
cd build
```

Start the server first

```
sudo ./server <port>
```

Now start the client in another terminal

```
sudo ./client <host> <port>
```
* host - localhost (127.0.0.1)

* port - same port id as the one entered for server.


Type a message in the client console (as seen below) to get back a response from the server.
```
Enter message:
```
Once should be able to see messages on the client and server console.

## Libraries used

* [Boost(asio)](https://www.boost.org/) - C++ libraries


## Owner
* Abhimanyu Selvan (bigillu)
