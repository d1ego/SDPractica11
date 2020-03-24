#ifndef SOCKETDATAGRAMA_H
#define SOCKETDATAGRAMA_H

#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
class SocketDatagrama
{
public:
  SocketDatagrama(int);
  ~SocketDatagrama();
//Recibe un paquete tipo datagrama proveniente de este socket
  int recibe(PaqueteDatagrama & p);
//Envía un paquete tipo datagrama desde este socket
  int envia(PaqueteDatagrama & p);
private:
  struct sockaddr_in direccionLocal;
  struct sockaddr_in direccionForanea;
  int s; //ID socket
};

#endif
