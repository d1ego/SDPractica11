#include <iostream>
#include <cstring>
#include "Solicitud.h"

using namespace std;
Solicitud::Solicitud()
{
  socketlocal = new SocketDatagrama(0);
  //PaqueteDatagrama
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments)
{//Usuario cliente (puerto variable)

  cout << "doOperation"<<endl;
	struct mensaje msg;
	msg.messageType = 0;
	msg.requestId = 0;
	msg.operationId=operationId;
	memcpy(msg.arguments,arguments,sizeof(arguments));
	PaqueteDatagrama p = PaqueteDatagrama((char*)&msg,sizeof(msg),IP,puerto);
  cout << "Datos enviados"<<endl;
  cout << "IP: "<<p.obtieneDireccion()<<endl;
  cout << "Puerto: "<<p.obtienePuerto()<<endl;
	socketlocal->envia(p);
	PaqueteDatagrama pRes = PaqueteDatagrama(4000);
  struct mensaje* msgR=(struct mensaje*)pRes.obtieneDatos();
  //struct mensaje msgR;
  //memcpy(msgR.arguments,pRes.obtieneDatos(),sizeof(4000));


  int recibido = socketlocal->recibe(pRes);
  cout << "Datos recibidos"<<endl;
  cout << "IP: "<<pRes.obtieneDireccion()<<endl;
  cout << "Puerto: "<<pRes.obtienePuerto()<<endl;
	return (char *)msgR->arguments;
}
