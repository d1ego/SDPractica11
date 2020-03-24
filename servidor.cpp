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
    Respuesta resp = Respuesta(0);
    cout<< "Esperando Respuesta:"<<endl;
    while(1){
        struct mensaje msg=*resp.getRequest();
        cout<<msg.arguments<<endl;
        char numRespuesta = msg.arguments[0] + msg.arguments[1];
        resp.sendReply((char*)&numRespuesta);
    }
}
