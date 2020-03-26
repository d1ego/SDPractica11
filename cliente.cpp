#include <iostream>
#include<string.h>
#include "Solicitud.h"

using namespace std;

int main(int argc, char* argv[]) {
	char num[2];
	int numRespuesta;
    num[0] = 5;
    num[1] = 5; /*rellena el mensaje */
	Solicitud solicitud;
	memcpy(&numRespuesta,solicitud.doOperation(argv[1],6666,1,(char*)&num),4);


	//solicitud.prueba(10);
	//memcpy(&numRespuesta,solicitud.doOperation(argv[1],6666,1,(char*)&num),10);
	//cout<<numRespuesta<<endl;
	printf("Resultado:%d\n", numRespuesta);
	return 0;
}
