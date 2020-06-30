
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include "pilotos.h"
#include <string.h>

ePiloto* piloto_new(void) {
    return (ePiloto*) malloc(sizeof(ePiloto));
}

ePiloto* piloto_newParametros(int* p_idPiloto, char* p_Nombre) {

  ePiloto* auxPiloto = piloto_new();

  if (auxPiloto != NULL &&
      piloto_setIdPiloto(auxPiloto,*p_idPiloto) &&
      piloto_setNombre(auxPiloto,p_Nombre)) {
  } else {

     piloto_delete(auxPiloto);
     auxPiloto = NULL;

  }
  return auxPiloto;
}



int piloto_setIdPiloto(ePiloto* unPiloto, int p_idPiloto) {

  int ret_Value = 0;

  if (unPiloto != NULL) {
    unPiloto->idPiloto = p_idPiloto;
    ret_Value = 1;
  }

 return ret_Value;
}

int piloto_getIdP(ePiloto* unPiloto ,int* p_idPiloto) {
    int ret_value = 0;

    if (unPiloto != NULL) {
        *p_idPiloto = unPiloto->idPiloto;
        ret_value = 1;
    }

    return ret_value;
}

int piloto_setNombre(ePiloto* unPiloto, char* p_Nombre) {

    int ret_value = 0;

    if(unPiloto != NULL && unPiloto->nombrep != NULL && p_Nombre != NULL) {
        strcpy(unPiloto->nombrep, p_Nombre);
        ret_value = 1;
    }
    return ret_value;
}

int piloto_getNombre(ePiloto* unPiloto, char* p_Nombre) {
  int ret_value = 0;

  if (unPiloto != NULL && unPiloto->nombrep != NULL) {
    strcpy(p_Nombre, unPiloto->nombrep);
    ret_value = 1;
  }
  return ret_value;
}

void piloto_delete(ePiloto* unPiloto){

      if(unPiloto != NULL){
            free(unPiloto);
      }
}

void piloto_imprimirPilotos(LinkedList* listaPiloto) {

    int i;
    int tamPiloto;
    int idPlt;
    char nombrePlt[50];
    ePiloto* elemento;
    if (listaPiloto != NULL) {
        tamPiloto = ll_len(listaPiloto);
        printf(" +===================================================================================+\n");
        printf(" |                                PILOTO DISPONIBLE                                  |\n");
        printf(" +===================================================================================+\n");
        for(i=0 ; i<tamPiloto; i++) {
            elemento =(ePiloto*) ll_get(listaPiloto,i);
            if(elemento != NULL && piloto_getIdP(elemento,&idPlt) && piloto_getNombre(elemento,nombrePlt)){
                printf(" | %12d                       |%25s                     |\n",idPlt,nombrePlt);
                printf(" +-----------------------------------------------------------------------------------+\n");

            }
        }
    }
}


int filtrarPilotoPorNombre(void* element , char* cadena ){

    int ret_value = 1;
    ePiloto* unPiloto;
    if(element != NULL){
        unPiloto = (ePiloto*)element;
        if(strcmp(unPiloto->nombrep,cadena) == 0){
            ret_value = 0;
        }
    }
   return ret_value;
}
