#include "Respuesta.h"

PaqueteDatagrama p = PaqueteDatagrama(4000);

Respuesta::Respuesta(int pl)
{
  socketlocal = new SocketDatagrama(pl);
}

struct mensaje* Respuesta::getRequest(void){
}

void Respuesta::sendReply(char *respuesta)
{

}
