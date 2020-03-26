#include <iostream>
#include<cstring>
#include "Solicitud.h"

using namespace std;

int main(int argc, char* argv[]) {
	int num[2];
	int numRespuesta;
    num[0] = 5;
    num[1] = 5; /*rellena el mensaje */
	Solicitud solicitud;
	cout<<"Numero enviados: "<< num[0]<<","<<num[1]<<endl;
	memcpy(&numRespuesta,solicitud.doOperation(argv[1],7200,1,(char*)&num),4);

	//solicitud.prueba(10);
	//memcpy(&numRespuesta,solicitud.doOperation(argv[1],6666,1,(char*)&num),10);
	//cout<<numRespuesta<<endl;
	printf("Resultado:%d\n", numRespuesta);
	return 0;
}
