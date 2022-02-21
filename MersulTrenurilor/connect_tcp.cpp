#include "connect_tcp.h"

connect_tcp::connect_tcp()
{

}

void connect_tcp::connect_to_server()
{

        int sd;
        struct sockaddr_in server;	// structura folosita pentru conectare
        int port = atoi ("2024");

        if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
        {
          perror ("Eroare la socket().\n");
          //return errno;
        }

        server.sin_family = AF_INET;

        server.sin_addr.s_addr = inet_addr("127.0.0.1");

        server.sin_port = htons (port);

        if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
        {
          perror ("[client]Eroare la connect().\n");
          //return errno;
        }

        if (write (sd, msg, 1000) <= 0)
        {
          perror ("[client]Eroare la write() spre server.\n");
          //return errno;
        }

        bzero (msg, 1000);
        if (read (sd, msg, 1000) < 0)
        {
          perror ("[client]Eroare la read() de la server.\n");
          //return errno;
        }

        strcpy(response, msg);

        close (sd);

}
