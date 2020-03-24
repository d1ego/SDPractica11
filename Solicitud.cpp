#include "Solicitud.h"

Solicitud::Solicitud()
{
  socketlocal = new SocketDatagrama(0);
}

char * Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments)
{

}
