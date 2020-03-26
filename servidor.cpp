#include <iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include <stdlib.h>
#include "Respuesta.h"
#include "mensaje.h"

using namespace std;

int main() {
    Respuesta resp = Respuesta(6666);
    cout<< "Esperando Respuesta:"<<endl;
    while(1){
      int numeros[2];
        struct mensaje* msg=resp.getRequest();
        memcpy(&numeros,&msg->arguments, sizeof(msg->arguments));
        cout<<msg->arguments<<endl;
        int numRespuesta = numeros[0]+numeros[1];
        resp.sendReply((char*)&numRespuesta);
    }
}
