Create two programs Client and Server. Server creates a message queue and waits for connections from various clients. A client opens the message queue and sends a text message: "Connect" to the server and waits for response from Server. 
The primary server on receipt of the "Connect" message from a client creates a new secondary server process. This new process would handle all further communication from this client.

The primary server sends a type of message (a unique number) to the client to be used for further communication and goes on to wait for new client connections.

Now onwards, the client in all communication with the secondary server has to use this message type, though the message queue being used for communication is the same.

Client would request for the contents of a file by providing the path of the file to the server and the secondary server would open and read the desired file and send the contents of the file to the client over the message queue. 
There is no limit to the file size and the client may request for the contents of multiple files one after another. 
The client, when done, will send a "terminate" message to the server and the secondary server should exit on receipt of this message.

The client should ask the user how many and which files it wants to get from the server.

