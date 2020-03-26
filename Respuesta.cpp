#include "Respuesta.h"
#include "mensaje.h"

PaqueteDatagrama p = PaqueteDatagrama(4000);
struct mensaje msgReturn;

Respuesta::Respuesta(int pl)
{
  socketlocal = new SocketDatagrama(pl);
}

struct mensaje* Respuesta::getRequest(void){
  int recibido = socketlocal->recibe(p);
	p.obtieneDireccion();
	p.obtienePuerto();
	p.obtieneDatos();
	//msgReturn.arguments=(struct mensaje*)&p.obtieneDatos();
	//return &msgReturn;
  return (struct mensaje*)p.obtieneDatos();
}

void Respuesta::sendReply(char *respuesta){
	struct mensaje msg;
	msg.messageType = 1;
	msg.requestId = 0;
	msg.operationId=0;
	memcpy(msg.arguments,respuesta,sizeof(respuesta));
	p.inicializaDatos((char*)&msg);
	socketlocal->envia(p);
}
