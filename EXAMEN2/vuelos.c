#include <stdlib.h>
#include <stdio.h>
#include "vuelos.h"
#include <string.h>

eVuelo* vuelo_new(void) {
    return (eVuelo*) malloc(sizeof(eVuelo));
}

eVuelo* vuelo_newParametros(int* p_idVuelo, int* p_idAvion ,int* p_idPiloto, char* p_fecha,
                             char* p_Destino, int* p_cantpsj,int* p_horaDpg, int* p_horaLlegd) {

  eVuelo* auxVuelo = vuelo_new();

  if (auxVuelo != NULL && (
        vuelo_setIdVuelo(auxVuelo, *p_idVuelo) == 1 &&
        vuelo_setIdAvion(auxVuelo, *p_idAvion) == 1 &&
        vuelo_setIdPiloto(auxVuelo, *p_idPiloto) == 1 &&
        vuelo_setFecha(auxVuelo, p_fecha) == 1 &&
        vuelo_setDestino(auxVuelo, p_Destino) == 1 &&
        vuelo_setCantpsj(auxVuelo, *p_cantpsj) == 1 &&
        vuelo_setHoradespegue(auxVuelo, *p_horaDpg) == 1 &&
        vuelo_setHorallegada(auxVuelo, *p_horaLlegd) == 1)) {
  } else {

    auxVuelo = NULL;
  }
  return auxVuelo;
}


int vuelo_setIdVuelo(eVuelo* unVuelo ,int p_idVuelo) {
  int returnValue = 0;
  if (unVuelo != NULL) {
    unVuelo ->idVuelo = p_idVuelo;
    returnValue = 1;
  }
 return returnValue;
}
int vuelo_getIdVuelo(eVuelo* unVuelo ,int* p_idVuelo) {
    int returnValue = 0;
    if (unVuelo != NULL) {
        *p_idVuelo = unVuelo ->idVuelo;
        returnValue = 1;
    }
    return returnValue;
}

int vuelo_setIdAvion(eVuelo* unVuelo ,int p_idAvion) {
  int returnValue = 0;
  if (unVuelo != NULL) {
    unVuelo ->idAvion = p_idAvion;
    returnValue = 1;
  }
 return returnValue;
}
int vuelo_getIdAvion(eVuelo* unVuelo ,int* p_idAvion) {
    int returnValue = 0;
    if (unVuelo != NULL) {
        *p_idAvion = unVuelo ->idAvion;
        returnValue = 1;
    }
    return returnValue;
}

int vuelo_setIdPiloto(eVuelo* unVuelo ,int p_idPiloto) {
  int returnValue = 0;
  if (unVuelo != NULL) {
    unVuelo ->idPiloto = p_idPiloto;
    returnValue = 1;
  }
 return returnValue;
}
int vuelo_getIdPiloto(eVuelo* unVuelo ,int* p_idPiloto) {
    int returnValue = 0;
    if (unVuelo != NULL) {
        *p_idPiloto = unVuelo ->idPiloto;
         returnValue = 1;
    }
    return returnValue;
}

int vuelo_setFecha(eVuelo* unVuelo, char* p_fecha) {

    int returnValue = 0;
    if(unVuelo != NULL && unVuelo->fecha !=NULL && p_fecha != NULL) {
        strcpy(unVuelo->fecha, p_fecha);
        returnValue = 1;
    }
    return returnValue;
}
int vuelo_getFecha(eVuelo* unVuelo,char* p_fecha) {
  int returnValue = 0;
  if (unVuelo != NULL && unVuelo->fecha != NULL) {
    strcpy(p_fecha, unVuelo->fecha);
    returnValue = 1;
  }
  return returnValue;
}

int vuelo_setDestino(eVuelo* unVuelo, char* p_Destino) {

    int returnValue = 0;

    if(unVuelo != NULL && unVuelo->destino != NULL && p_Destino != NULL) {
        strcpy(unVuelo->destino, p_Destino);
        returnValue = 1;
    }
    return returnValue;
}
int vuelo_getDestino(eVuelo* unVuelo, char* p_Destino) {
  int returnValue = 0;
  if (unVuelo != NULL && unVuelo->destino != NULL) {
    strcpy(p_Destino, unVuelo->destino);
    returnValue = 1;
  }
  return returnValue;
}

int vuelo_setCantpsj(eVuelo* unVuelo, int p_cantpsj) {
    int returnValue = 0;
    if(unVuelo != NULL && p_cantpsj >= 0 && p_cantpsj <= 1000 ) {
        unVuelo->cantPasajeros = p_cantpsj;
        returnValue = 1;
    }
    return returnValue;
}
int vuelo_getCantpsj(eVuelo* unVuelo, int* p_cantpsj) {
  int returnValue = 0 ;

  if (unVuelo != NULL) {
    *p_cantpsj = unVuelo->cantPasajeros;
    returnValue = 1;
  }
return returnValue;
}

int vuelo_setHoradespegue(eVuelo* unVuelo,int p_horaDpg) {

  int returnValue = 0;

  if (unVuelo != NULL && p_horaDpg > 0 && p_horaDpg < 100 ) {
    unVuelo->horaDespegue = p_horaDpg;
    returnValue = 1;
  }
  return returnValue;

}
int vuelo_getHoradespegue(eVuelo* unVuelo,int* p_horaDpg) {
    int returnValue = 0;

    if(unVuelo != NULL){
        *p_horaDpg = unVuelo->horaDespegue;
        returnValue = 1;
    }
    return returnValue;
}

int vuelo_setHorallegada(eVuelo* unVuelo, int p_horaLlegd) {
    int returnValue = 0;

    if(unVuelo != NULL && p_horaLlegd >=0 && p_horaLlegd <= 100) {
        unVuelo->horaLlegada = p_horaLlegd;
        returnValue = 1;
    }
    return returnValue;
}
int vuelo_getHorallegada(eVuelo* unVuelo, int* p_horaLlegd) {
    int retrunValue = 0;

    if(unVuelo != NULL){
        *p_horaLlegd = unVuelo->horaLlegada;
        retrunValue = 1;
    }
    return retrunValue;
}

int contarpasajeros(void* element){
    int cantidad = 0;
    eVuelo* unVuelos;
    if(element != NULL){
        unVuelos = (eVuelo*)element;
        if(vuelo_getCantpsj(unVuelos,&cantidad) != 1){
          cantidad = 0;
        }
    }
 return cantidad;
}
int contarpasajerosIrlanda(void* element){

    int cantidad = 0;
    eVuelo* unVuelos;
    if(element != NULL ) {
        unVuelos = (eVuelo*)element;
        if(strcasecmp(unVuelos->destino,"Irlanda") == 0) {
            if(vuelo_getCantpsj(unVuelos,&cantidad) != 1){
              cantidad = 0;
            }
       }
    }
 return cantidad;
}
int filtrarVueloCorto(void* element) {

    int ret_value = 0;
    int i;
    int j;
    int x;
    eVuelo* unVuelo;
    if (element != NULL) {
        unVuelo =(eVuelo*)element;
        if(vuelo_getHoradespegue(unVuelo,&i) == 1 &&
           vuelo_getHorallegada(unVuelo,&j) == 1) {
                x = j - i;
                if (x < 3) {
                    ret_value = 1;
                }
        }
    }
    return ret_value;
}
int filtrarVueloPortugal(void* element){

    int ret_value = 0;
    eVuelo* unVuelo;
    if(element != NULL){
        unVuelo = (eVuelo*)element;
        if(strcmp(unVuelo->destino,"Portugal") == 0){
            ret_value = 1;
        }
    }
   return ret_value;
}
int filtrarVuelomenosAlex(void* element){

    int ret_value = 0;

    eVuelo* unVuelo;
    if(element != NULL ){
        unVuelo = (eVuelo*)element;
        if(unVuelo->idPiloto != 1 ){
            ret_value = 1;
        }
    }
   return ret_value;
}

void vuelo_delete(eVuelo* unVuelo){

  if(unVuelo != NULL){
    free(unVuelo);
  }
}
int vuelo_CompareByIdVuelo(void* e1, void* e2) {

    int ret_value;

    eVuelo* vuelo1 = (eVuelo*)e1;
    eVuelo* vuelo2 = (eVuelo*)e2;

    if(vuelo1 != NULL && vuelo2 != NULL) {
        if(vuelo1->idVuelo > vuelo2->idVuelo) {
            ret_value = 1;
        }else if(vuelo1->idVuelo < vuelo2->idVuelo) {
                ret_value = -1;
            }else {
                ret_value = 0;
            }
    }
    return ret_value;
}
int vuelo_CompareByIdAvion(void* e1, void* e2) {
    int ret_value;
    eVuelo* vuelo1 = (eVuelo*)e1;
    eVuelo* vuelo2 = (eVuelo*)e2;

    if(vuelo1 != NULL && vuelo2 != NULL) {
        if(vuelo1->idAvion > vuelo2->idAvion) {
            ret_value = 1;
        }else {
            if(vuelo1->idAvion < vuelo2->idAvion) {
                ret_value = -1;
            }else {
                ret_value = 0;
            }
        }
    }
    return ret_value;
}
int vuelo_CompareByIdPiloto(void* e1, void* e2) {
    int ret_value;
    eVuelo* vuelo1 = (eVuelo*)e1;
    eVuelo* vuelo2 = (eVuelo*)e2;

    if (vuelo1 != NULL && vuelo2 != NULL) {
        if(vuelo1->idPiloto > vuelo2->idPiloto) {
            ret_value = 1;
        }else {
            if(vuelo1->idPiloto < vuelo2->idPiloto) {
                ret_value = -1;
            }else {
                ret_value = 0;
            }
        }
    }
    return ret_value;
}

int vuelo_CompareByfecha(void* e1, void* e2){
    int ret_value;

    eVuelo* vuelo1;
    eVuelo* vuelo2;
    if(e1 != NULL && e2 != NULL){
        vuelo1 = (eVuelo*)e1;
        vuelo2 = (eVuelo*)e2;

       ret_value = strcmp(vuelo1->fecha,vuelo2->fecha);
    }
    return ret_value;
}
int vuelo_CompareByDestino(void* e1, void* e2){
    int ret_value;

    eVuelo* vuelo1;
    eVuelo* vuelo2;
    if(e1!= NULL && e2 != NULL) {
        vuelo1 = (eVuelo*)e1;
        vuelo2 = (eVuelo*)e2;
        ret_value = strcmp(vuelo1->destino,vuelo2->destino);
    }
    return ret_value;
}

int vuelo_ComparCantPsj(void* e1, void* e2) {

    int ret_value;

    eVuelo* vuelo1;
    eVuelo* vuelo2;

    if(e1 != NULL && e2 != NULL) {
        vuelo1 = (eVuelo*)e1;
        vuelo2 = (eVuelo*)e2;
        if(vuelo1->cantPasajeros > vuelo2->cantPasajeros) {
            ret_value = 1;
        }else if(vuelo1->cantPasajeros < vuelo2->cantPasajeros) {
                ret_value = -1;
            }else {
                ret_value = 0;
            }
    }
    return ret_value;
}
int vuelo_ComparHdespegue(void* e1, void* e2) {

    int ret_value;

    eVuelo* vuelo1;
    eVuelo* vuelo2;

    if(e1 != NULL && e2 != NULL) {
        vuelo1 = (eVuelo*)e1;
        vuelo2 = (eVuelo*)e2;
        if(vuelo1->horaDespegue > vuelo2->horaDespegue) {
            ret_value = 1;
        }else if(vuelo1->horaDespegue < vuelo2->horaDespegue) {
                ret_value = -1;
            }else {
                ret_value = 0;
            }
    }
    return ret_value;
}
int vuelo_ComparHllegada(void* e1, void* e2) {

    int ret_value;

    eVuelo* vuelo1;
    eVuelo* vuelo2;

    if(e1 != NULL && e2 != NULL) {
        vuelo1 = (eVuelo*)e1;
        vuelo2 = (eVuelo*)e2;
        if(vuelo1->horaLlegada > vuelo2->horaLlegada) {
            ret_value = 1;
        }else if(vuelo1->horaLlegada < vuelo2->horaLlegada) {
                ret_value = -1;
            }else {
                ret_value = 0;
            }
    }
    return ret_value;
}

