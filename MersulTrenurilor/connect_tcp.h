#ifndef CONNECT_TCP_H
#define CONNECT_TCP_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <iostream>
using namespace std;
/* codul de eroare returnat de anumite apeluri */
extern int errno;

/* portul de conectare la server*/

class connect_tcp
{
public:
    char msg[1000], response[1000];
    connect_tcp();
    void connect_to_server();
};

#endif // CONNECT_TCP_H
