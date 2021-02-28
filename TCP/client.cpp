#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        cerr << "Missing hostname and port number\n";
        exit(0);
    }
    char *serverName = argv[1];
    int port = atoi(argv[2]);
    char message[1500];

    struct hostent *host = gethostbyname(serverName);
    sockaddr_in clientSocket;
    clientSocket.sin_family = AF_INET;
    clientSocket.sin_port = htons(port);
    clientSocket.sin_addr = **(struct in_addr **)host->h_addr_list;

    int clientSocketID = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocketID < 0)
    {
        cout << "Failed socket()\n";
        exit(0);
    }

    int status = connect(clientSocketID, (struct sockaddr *)&clientSocket, sizeof(clientSocket));

    if (status < 0)
    {
        cout << "Failed connect()\n";
        exit(0);
    }

    cout << "Connection Successful\n";

    while (true)
    {
        string data;
        cout << "Client: ";
        //cin>>data;
        getline(cin, data);

        strcpy(message, data.c_str());

        send(clientSocketID, (char *)&message, sizeof(message), 0);
        
        if (data=="exit")
        {
            cout<<"Session exited Successfuly!"<<"\n";
            break;
        }

        cout << "Server: ";

        recv(clientSocketID, (char *)&message, sizeof(message), 0);

        if (!strcmp(message, "exit"))
        {
            cout<<"Session exited Successfuly!"<<"\n";
            break;
        }
        cout<<message<<"\n";
    }

    close(clientSocketID);

    return 0;
}