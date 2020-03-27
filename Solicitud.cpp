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
  int enviado, recibido;
  cout << "doOperation"<<endl;
  cout << arguments[0]<<endl;

	struct mensaje msg;
	msg.messageType = 0;
	msg.requestId = 0;
	msg.operationId=operationId;
  //strcpy(msg.arguments,arguments);
  memcpy(msg.arguments,arguments,sizeof(struct mensaje*));
	PaqueteDatagrama p = PaqueteDatagrama((char*)&msg,TAM_MAX_DATA,IP,puerto);
  cout << "Datos enviados"<<endl;
  cout << "IP: "<<p.obtieneDireccion()<<endl;
  cout << "Puerto: "<<p.obtienePuerto()<<endl;
	enviado=socketlocal->envia(p);
  if (enviado == -1) {
      perror("Fallo al enviar");
    }
	PaqueteDatagrama pRes = PaqueteDatagrama(4000);
  //struct mensaje msgR;
  //memcpy(msgR.arguments,pRes.obtieneDatos(),sizeof(4000));
  recibido = socketlocal->recibe(pRes);

  if (recibido == -1) {
      perror("Fallo al recibir");
    }

  cout << "Datos recibidos"<<endl;
  cout << "IP: "<<pRes.obtieneDireccion()<<endl;
  cout << "Puerto: "<<pRes.obtienePuerto()<<endl;

struct mensaje* msgR=(struct mensaje*)pRes.obtieneDatos();

	//return pRes.obtieneDatos();
  return (char *)msgR->arguments;
}
