#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "contoller.h"
#include "parser.h"
#include "pilotos.h"
#include "vuelos.h"

int controller_huallpa_loadFromText(char* path , LinkedList* pArrayvuelos){
     int ret_value = 0;

     FILE* fileText;

     if (pArrayvuelos != NULL) {

        fileText =  fopen(path, "r");
        if(fileText != NULL){
            ret_value = parser_EmployeeFromText(fileText,pArrayvuelos);
        }
        fclose(fileText);
    }
    return ret_value;
}


int controller_huallpa_loadpiloto(char* path , LinkedList* listaPiloto){
     int ret_value = 0;

     FILE* fileTex;

     if (listaPiloto != NULL) {

        fileTex =  fopen(path, "r");
        if(fileTex != NULL){
            ret_value = parser_piloto(fileTex,listaPiloto);
        }
        fclose(fileTex);
    }
    return ret_value;
}

int controller_huallpa_harcodearPiloto(LinkedList* listaPiloto){

    int ret_value = 0;
    int i;
    ePiloto* unPiloto;

    if(listaPiloto != NULL){
//crear un lista dinamica

        int idPiloto[5] = {1,2,3,4,5};
        char nombrepiloto[5][51] = {{"Alex Lifeson"},{"Richard Bach"},
                                    {"John Kerry"},{"Erwin Rommel"},
                                    {"Stephen Coonts"}};

        for(i=0 ; i< 5 ; i++) {
            unPiloto = piloto_newParametros(&idPiloto[i],nombrepiloto[i]);
            if(unPiloto != NULL){
                if (ll_add(listaPiloto, (ePiloto*)unPiloto) != 0) {
                    printf("\n Error en el harcodeo. ");
                    ret_value = 1;
                }
            }
        }
    }
    return ret_value;
}

int controller_huallpa_imprimirVuelos(LinkedList* listavuelos, LinkedList* listaPiloto){

    int ret_value = -1;
    char nombre[50];
    char fecha[50];
    char destino[50];
    int cantPsj;
    int h_Dsp;
    int h_Lle;
    int i;
    ePiloto* elemento;
    eVuelo* elemento2;

    if(listavuelos != NULL && listaPiloto != NULL){
        system("cls");
        piloto_imprimirPilotos(listaPiloto);
        printf("\n\nIngrese nombre del piloto: ");
        fflush(stdin);
        gets(nombre);

        for(i=0 ; i< ll_len(listaPiloto) ; i++){
            elemento = (ePiloto*) ll_get(listaPiloto,i);
            if( stricmp(elemento->nombrep,nombre) == 0 ) {
//poner destalles.
                printf("+====================================================================================+\n");
                printf("|                                VUELOS DEL PILOTO                                   |\n");
                printf("+====================================================================================+\n");

                for(int j=0 ; j < ll_len(listavuelos) ; j++ ) {
                    elemento2 =(eVuelo*) ll_get(listavuelos,j);

                    if ( elemento->idPiloto == elemento2->idPiloto && piloto_getNombre(elemento,nombre) &&
                        vuelo_getFecha(elemento2,fecha) && vuelo_getDestino(elemento2,destino) &&
                        vuelo_getCantpsj(elemento2,&cantPsj) && vuelo_getHoradespegue(elemento2,&h_Dsp)&&
                        vuelo_getHorallegada(elemento2,&h_Lle)){

                        printf("|%20s%20s%20s%8d%8d%8d|\n",nombre,fecha,destino,cantPsj,h_Dsp,h_Lle);
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

int controller_huallpa_saveAsText(char* path, LinkedList* pArrayvuelos) {

      FILE* file = NULL;
      int ret_Value = 0;
      int i;
      int idvuelo,idvion,idpiloto,cant_Psj,h_Dsp,h_lle;
      char destino[50];
      char fecha[50];
      eVuelo* auxVuelo;
      LinkedList* filtro;

      if (pArrayvuelos != NULL && ll_len(pArrayvuelos) > 0) {

        filtro = ll_filter(pArrayvuelos,filtrarVueloCorto); //filtroo los vuelos cortos.
        file = fopen(path, "w");

        if(filtro != NULL && file != NULL){
            fprintf(file,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n");
            for(i=0; i < ll_len(filtro) ; i++){
                auxVuelo = (eVuelo*)ll_get(filtro,i);

                if(auxVuelo != NULL && vuelo_getIdVuelo(auxVuelo,&idvuelo) && vuelo_getIdAvion(auxVuelo,&idvion) &&
                                       vuelo_getIdPiloto(auxVuelo,&idpiloto) && vuelo_getFecha(auxVuelo,fecha) &&
                                       vuelo_getDestino(auxVuelo,destino)&& vuelo_getCantpsj(auxVuelo,&cant_Psj) &&
                                       vuelo_getHoradespegue(auxVuelo,&h_Dsp) && vuelo_getHorallegada(auxVuelo,&h_lle)){

                    fprintf(file,"%d,%d,%d,%s,%s,%d,%d,%d\n",idvuelo,idvion,idpiloto,fecha,destino,cant_Psj,h_Dsp,h_lle);
                    ret_Value = 1;
                }
            }
        }
        fclose(file);
    }
    return ret_Value;
}

LinkedList* controller_huallpa_listaVuelosPortugal(LinkedList* pArrayvuelos ){


    LinkedList* auxListaV = NULL;

    if (pArrayvuelos != NULL) {

        auxListaV = ll_filter(pArrayvuelos,filtrarVueloPortugal);
    }

    return auxListaV;
}

int controller_huallpa_inprimirVuelos(LinkedList* listVuelo){

    int i;
    int ret_value = 0;
    int idvuelo;
    int idavion;
    int idpiloto;
    char fecha[51];
    char destino[51];
    int cantidadpsj;
    int h_dspg;
    int h_llegada;
    eVuelo* unVuelo;

    if(listVuelo != NULL){
        printf("+===================================================================================+\n");
        printf("| ID-VUELO | ID-AVION | ID-PILOTO |    FECHA    |    DESTINO    | C_PSJ | H_D | H_L | \n");
        printf("+===================================================================================+\n");
        for(i = 0 ; i<ll_len(listVuelo); i++){
            unVuelo = ll_get(listVuelo,i);

            if (unVuelo != NULL && vuelo_getIdVuelo(unVuelo,&idvuelo) && vuelo_getIdAvion(unVuelo,&idavion) &&
                vuelo_getIdPiloto(unVuelo,&idpiloto) && vuelo_getFecha(unVuelo,fecha) && vuelo_getDestino(unVuelo,destino) &&
                vuelo_getCantpsj(unVuelo,&cantidadpsj) && vuelo_getHoradespegue(unVuelo, &h_dspg) && vuelo_getHorallegada(unVuelo,&h_llegada)) {

                printf("|%7d%9d%11d%18s%14s%10d%7d%6d |\n",idvuelo,idavion,idpiloto,fecha,destino,cantidadpsj,h_dspg,h_llegada);
                printf("+-----------------------------------------------------------------------------------+\n");
                ret_value = 1;
            }
        }
    }
    return ret_value;
}

LinkedList* controller_huallpa_listaVuelosmenosAlex(LinkedList* pArrayvuelos ){


    LinkedList* auxListaV = NULL;

    if (pArrayvuelos != NULL) {

        auxListaV = ll_filter(pArrayvuelos,filtrarVuelomenosAlex );
    }

    return auxListaV;
}


int controller_huallpa_sortvuelos(LinkedList* pArrayvuelos) {

    int ret_value = 0;
    int order;
    int cont = 0;
    int option;

    if(pArrayvuelos != NULL) {
        if(ll_len(pArrayvuelos) > 0){
            do{ system("cls");
                if((menu_sort(&option)== 1)){

                    printf("Ingrese para ordenar : [1] Asendente - [0] descente: ");
                    scanf("%d",&order);

                    while(order != 1 && order != 0){
                         printf("Ingrese para ordenar : [1] Asendente - [0] descente: ");
                         scanf("%d",&order);
                    }
                    printf("Aguarde un momento...\n");

                    switch(option){

                        case 1:
                            if(ll_sort(pArrayvuelos,vuelo_CompareByIdVuelo,order)== 0){
                                printf("\nOrdenado por ID Vuelo finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                        case 2:
                            if(ll_sort(pArrayvuelos,vuelo_CompareByIdAvion,order) == 0){
                                printf("\nOrdenado por ID Avion finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                        case 3:
                            if(ll_sort(pArrayvuelos,vuelo_CompareByIdPiloto,order)== 0){
                                printf("\nOrdenado por ID Piloto finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                        case 4:
                            if(ll_sort(pArrayvuelos,vuelo_CompareByfecha,order)== 0){
                                printf("\nOrdenado por Fecha finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                        case 5:
                            if(ll_sort(pArrayvuelos,vuelo_CompareByDestino,order)== 0){
                                printf("\nOrdenado por Destino finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                        case 6:
                            if(ll_sort(pArrayvuelos,vuelo_ComparCantPsj,order)== 0){
                                printf("\nOrdenado por Cantidad pasajeros finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                        case 7:
                            if(ll_sort(pArrayvuelos,vuelo_ComparHdespegue,order)== 0){
                                printf("\nOrdenado por Hora llegada finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                        case 8:
                            if(ll_sort(pArrayvuelos,vuelo_ComparHllegada,order)== 0){
                                printf("\nOrdenado por Hora llegada finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                        case 9:

                        break;
                    }


                }else{
                    if(option < 1 || option > 9){
                    printf("opcion invalido.\n");
                    system("pause");
                    cont++;
                    }
                }
            }while(option != 9 && cont != 3);
        }
    }
return ret_value;
}

int menu_sort(int* option) {

    int ret_value = -1;

    printf(" +=================================================+\n");
    printf(" |              ORDERNAR EMPLEADOS                 |\n");
    printf(" +=================================================+\n");
    printf(" |  [1] Ordenar por ID VUELO.                      |\n");
    printf(" |  [2] Ordenar por ID AVION.                      |\n");
    printf(" |  [3] Ordenar por ID PILOTO.                     |\n");
    printf(" |  [4] Ordenar por FECHA.                         |\n");
    printf(" |  [5] Ordenar por DESTINO.                       |\n");
    printf(" |  [6] Ordenar por CANT_PASAJEROS.                |\n");
    printf(" |  [7] Ordenar por HORA_DESPEGUE.                 |\n");
    printf(" |  [8] Ordenar por HORA_LLEGADA.                  |\n");
    printf(" |  [9] Salir.                                     |\n");
    printf(" +-------------------------------------------------+\n\n");
    printf("ingrese una opcion: ");
    scanf("%d",option);
    if(*option > 0 && *option < 9){
        ret_value = 1;
    }
    return ret_value;
}


LinkedList* controller_huallpa_filtrarPorNombre(LinkedList* listaPiloto){

    LinkedList* filtar = NULL;
    char nombre1[51];
    if(listaPiloto != NULL){

        piloto_imprimirPilotos(listaPiloto);
        printf("\n\nIngrese nombre del piloto: ");
        fflush(stdin);
        gets(nombre1);
        filtar = ll_filter_parametro(listaPiloto,filtrarPilotoPorNombre,nombre1);

    }
 return filtar;
}






int controller_hullpa_filtraryguardar(char* path, LinkedList* listaPiloto){

      FILE* file = NULL;

      int ret_Value = 0;
      int i;
      int idPiloto;
      char nombre[50];

      ePiloto* auxpiloto;

      if (listaPiloto != NULL && ll_len(listaPiloto) > 0) {

        file = fopen(path, "w");

        if(file != NULL){
            fprintf(file,"id,Nombre\n");
            for(i=0; i < ll_len(listaPiloto) ; i++){
                auxpiloto = (ePiloto*)ll_get(listaPiloto,i);

                if(auxpiloto != NULL && piloto_getIdP(auxpiloto,&idPiloto) && piloto_getNombre(auxpiloto,nombre)){

                    fprintf(file,"%d,%s\n",idPiloto,nombre);
                    ret_Value = 1;
                }
            }
        }
        fclose(file);
    }
    return ret_Value;




}
