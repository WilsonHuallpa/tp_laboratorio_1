#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "vuelos.h"
#include "contoller.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayVuelos){

    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha [35];
    char destino [35];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    char buffer[7][35];
    int ret_value = 0;
    eVuelo* auxVuelo;

    if(pFile != NULL && pArrayVuelos != NULL && ll_clear(pArrayVuelos) == 0 ){
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                    buffer[0],buffer[1],buffer[2],buffer[3],
                                    buffer[4],buffer[5],buffer[6],buffer[7]);
        while(!feof(pFile)){
            if(feof(pFile)){
                break;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                    buffer[0],buffer[1],buffer[2],buffer[3],
                                    buffer[4],buffer[5],buffer[6],buffer[7]);

            idVuelo = atoi(buffer[0]);
            idAvion = atoi(buffer[1]);
            idPiloto = atoi(buffer[2]);
            strcpy(fecha,buffer[3]);
            strcpy(destino,buffer[4]);
            cantPasajeros = atoi(buffer[5]);
            horaDespegue = atoi(buffer[6]);
            horaLlegada = atoi(buffer[7]);

            auxVuelo = vuelo_newParametros(&idVuelo,&idAvion,&idPiloto,fecha,destino,
                                           &cantPasajeros,&horaDespegue,&horaLlegada);

            if(auxVuelo != NULL && ll_add(pArrayVuelos,(eVuelo*)auxVuelo) == 0){
                ret_value++;
            }

        }

    }
    return ret_value;
}
