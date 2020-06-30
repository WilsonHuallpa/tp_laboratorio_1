
#ifndef _PILOTO
#define _PILOTO


typedef struct {

    int idPiloto;
    char nombrep[51];

}ePiloto;


ePiloto* piloto_new(void);
ePiloto* piloto_newParametros(int* p_idPiloto, char* p_Nombre);

void piloto_delete(ePiloto* unPiloto);

int piloto_setIdPiloto(ePiloto* unPiloto, int p_idPiloto);
int piloto_getIdP(ePiloto* unPiloto ,int* p_idPiloto);

int piloto_setNombre(ePiloto* unPiloto, char* p_Nombre);
int piloto_getNombre(ePiloto* unPiloto, char* p_Nombre);

void piloto_imprimirPilotos(LinkedList* listaPiloto);

int filtrarPilotoPorNombre(void* element , char* cadena );








#endif // _PILOTO



