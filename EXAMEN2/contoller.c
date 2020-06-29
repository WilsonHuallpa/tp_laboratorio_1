#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "contoller.h"
#include "parser.h"
#include "pilotos.h"
#include "vuelos.h"

int controller_loadFromText(char* path , LinkedList* pArrayvuelos){
     int ret_value = 0;
     FILE* fileText;
     if(pArrayvuelos != NULL){
        fileText =  fopen(path, "r");
        if(fileText != NULL){
            ret_value = parser_EmployeeFromText(fileText,pArrayvuelos);
        }
        fclose(fileText);
    }
    return ret_value;
}

void harcodearPiloto(LinkedList* listaPiloto){

    int idPiloto[5] ={1,2,3,4,5};
    char nombrepiloto[5][51] = {{"Alex Lifeson"},{"Richard Bach"},
                                {"John Kerry"},{"Erwin Rommel"},{"Stephen Coonts"}};
    ePiloto* unPiloto;

    int i;
    if(listaPiloto != NULL){
        for(i=0 ; i< 5 ; i++){
            unPiloto = (ePiloto*) malloc(sizeof(ePiloto));
            if(unPiloto != NULL){
                unPiloto->idPiloto = idPiloto[i];
                strcpy(unPiloto->nombrep, nombrepiloto[i]);
                if (ll_add(listaPiloto, (ePiloto*)unPiloto) != 0) {
                 printf("\n Error en el harcodeo. ");
                }
            }
        }
    }
}

int controller_imprimirVuelos(LinkedList* listavuelos, LinkedList* listaPiloto){

    int ret_value = -1;
    char nombre[50];
    int i;
    int tamPiloto;
    ePiloto* elemento;
    eVuelo* elemento2;

    if(listavuelos != NULL && listaPiloto != NULL){
        tamPiloto = ll_len(listaPiloto);
        printf(" +===================================================================================+\n");
        printf(" |                                PILOTO DISPONIBLE                                  |\n");
        printf(" +===================================================================================+\n");
        for(i=0 ; i<tamPiloto; i++) {
            elemento =(ePiloto*) ll_get(listaPiloto,i);
            printf(" | %12d                       |%25s                     |\n",elemento->idPiloto,elemento->nombrep);
            printf(" +-----------------------------------------------------------------------------------+\n");

        }
       printf("\n\nIngrese nombre del piloto: ");
       fflush(stdin);
       gets(nombre);
       for(i=0 ; i< tamPiloto ; i++){
            elemento = (ePiloto*) ll_get(listaPiloto,i);
            if( stricmp(elemento->nombrep,nombre) == 0 ) {
                printf("+====================================================================================+\n");
                printf("|                                VUELOS DEL PILOTO                                   |\n");
                printf("+====================================================================================+\n");
                for(int j=0 ; j < ll_len(listavuelos) ; j++ ) {
                    elemento2 =(eVuelo*) ll_get(listavuelos,j);
                    if ( elemento->idPiloto == elemento2->idPiloto) {
                        printf("|%20s%20s%20s%8d%8d%8d|\n",elemento->nombrep,elemento2->fecha,elemento2->destino,
                                                                                elemento2->cantPasajeros,elemento2->horaDespegue,
                                                                                elemento2->horaLlegada);
                        printf("+------------------------------------------------------------------------------------+\n");
                        ret_value = 1;

                    }
                }
                system("pause");
                break;
            }
       }
    }
    return ret_value;
}

int controller_saveAsText(char* path, LinkedList* pArrayvuelos) {

      FILE* file = NULL;
      int ret_Value = 0;
      int i;
      eVuelo* auxVuelo;
      LinkedList* filtro;

      if (pArrayvuelos != NULL && ll_len(pArrayvuelos) > 0) {

        filtro = ll_filter(pArrayvuelos,filtrarVueloCorto); //filtroo los vuelos cortos.
        file = fopen(path, "w");

        if(filtro != NULL && file != NULL){

            fprintf(file,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
            for(i=0; i < ll_len(filtro) ; i++){

                auxVuelo = (eVuelo*)ll_get(filtro,i);

                if(auxVuelo != NULL ){

                    fprintf(file,"%d,%d,%d,%s,%s,%d,%d,%d\n",auxVuelo->idVuelo,auxVuelo->idAvion,
                                                             auxVuelo->idPiloto,auxVuelo->fecha,
                                                             auxVuelo->destino,auxVuelo->cantPasajeros,
                                                             auxVuelo->horaDespegue,auxVuelo->horaLlegada);
                    ret_Value = 1;
                }
            }
        }
        fclose(file);
    }
    return ret_Value;
}




LinkedList* controller_listaVuelosPortugal(LinkedList* pArrayvuelos ){


    LinkedList* auxListaV = NULL;

    if (pArrayvuelos != NULL) {

        auxListaV = ll_filter(pArrayvuelos,filtrarVueloPortugal);
    }

    return auxListaV;
}

int inprimirVuelos(LinkedList* listVuelo){

    int i;

    int ret_value = 0;
    eVuelo* unVuelo;
    if(listVuelo != NULL){
        printf("+===================================================================================+\n");
        printf("| ID-VUELO | ID-AVION | ID-PILOTO |    FECHA    |    DESTINO    | C_PSJ | H_D | H_L | \n");
        printf("+===================================================================================+\n");
        for(i = 0 ; i<ll_len(listVuelo); i++){
            unVuelo = ll_get(listVuelo,i);
            if (unVuelo != NULL) {
                printf("|%7d%9d%11d%18s%14s%10d%7d%6d |\n",unVuelo->idVuelo,unVuelo->idAvion,unVuelo->idPiloto,
                                         unVuelo->fecha,unVuelo->destino,unVuelo->cantPasajeros,
                                         unVuelo->horaDespegue,unVuelo->horaLlegada);
                printf("+-----------------------------------------------------------------------------------+\n");
                ret_value = 1;
            }
        }
    }
    return ret_value;
}



LinkedList* controller_listaVuelosmenosAlex(LinkedList* pArrayvuelos ){


    LinkedList* auxListaV = NULL;

    if (pArrayvuelos != NULL) {

        auxListaV = ll_filter(pArrayvuelos,filtrarVuelomenosAlex );
    }

    return auxListaV;
}













/*int controller_cantidadPasajeros(LinkedList* listaVuelos) {

    int totalpasajeros = 0;
    int i;
    eVuelo* unvuelo;
    if (listaVuelos != NULL) {
        for (i=0 ; i<ll_len(listaVuelos) ; i++ ) {
           unvuelo = (eVuelo*)ll_get(listaVuelos,i);
           if(unvuelo != NULL) {
            totalpasajeros = totalpasajeros + unvuelo->cantPasajeros;
           }
        }
    }
 return totalpasajeros;
}*/

/*int controller_cantidadirlanda(LinkedList* listaVuelos) {

  int totalpasajeros = 0;
    int i;
    eVuelo* unvuelo;
    if (listaVuelos != NULL) {
        for (i=0 ; i<ll_len(listaVuelos) ; i++ ) {
           unvuelo = (eVuelo*)ll_get(listaVuelos,i);
           if(unvuelo != NULL && (strcmp(unvuelo->destino,"Irlanda") == 0)) {
            totalpasajeros = totalpasajeros + unvuelo->cantPasajeros;
           }
        }
    }
 return totalpasajeros;

}*/
//pendiente



