#include <iostream>
#include<cstring>
#include "Respuesta.h"

using namespace std;

int main() {
    Respuesta resp = Respuesta(7200);

    while(1){
      cout<< "Esperando Respuesta:"<<endl;
      int numeros[2];
      struct mensaje* msg=resp.getRequest();
        //strcpy(&numeros,&msg->arguments);
        memcpy(&numeros,&msg->arguments, sizeof(struct mensaje*));
        cout<<"Datos recibidos:"<< numeros[0] << ","<<numeros[1]<<endl;
        int numRespuesta = numeros[0]+numeros[1];

        resp.sendReply((char*)&numRespuesta);
    }
}
