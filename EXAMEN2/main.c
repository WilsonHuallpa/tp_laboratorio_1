#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "contoller.h"
#include "vuelos.h"
#include "pilotos.h"


int main()
{
    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listapiloto = ll_newLinkedList();
    LinkedList* listaPortugal;
    LinkedList* listamenosAlex;

    int opcion;
    int quantity_Vuelo;
    int tPasajero;
    if (listaVuelos == NULL || listapiloto == NULL) {
        printf("no se encontro espacio en memoria.");
        exit(EXIT_FAILURE);
    }
    harcodearPiloto(listapiloto);
    do{
        system("cls");
        printf(" +===================================================================================+\n");
        printf(" |                                MENU AEROLINEAS                                    |\n");
        printf(" +===================================================================================+\n");
        printf(" |  [1] Cargar los datos de los VUELOS desde el archivo.                             |\n");
        printf(" |  [2] Imprimir vuelo (indicando el nombre del piloto).                             |\n");
        printf(" |  [3] Cantidad de pasajeros totales.                                               |\n");
        printf(" |  [4] Cantidad de pasajeros a Irlanda.                                             |\n");
        printf(" |  [5] Filtrar vuelos cortos (cuya duracion sea inferior 3 horas).                  |\n");
        printf(" |  [6] Listar vuelos a Portugal.                                                    |\n");
        printf(" |  [7] Filtrar a Alex Lifeson .                                                     |\n");
        printf(" |  [8] Salir del programa.                                                          |\n");
        printf(" +-----------------------------------------------------------------------------------+\n\n");
        printf("\n\nIngrese una opcion : ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                quantity_Vuelo = controller_loadFromText("Vuelos.csv",listaVuelos);
                if(quantity_Vuelo > 0){
                    printf("se cargaron %d vuelos desde el archivo de texto.\n",quantity_Vuelo);
                    system("pause");
                }else{
                    printf("ERROR... Talves ya cargo el archivo\n");
                    system("pause");
                }
            break;
            case 2:
                controller_imprimirVuelos(listaVuelos,listapiloto);
            break;
            case 3:
                tPasajero = ll_count(listaVuelos,contarpasajeros );
               if(tPasajero > 0) {
                    printf("TOTAL DE PASAJEROS [%d] \n",tPasajero);
                    system("pause");
               }else {
                    printf("TOTAL DE PASAJEROS [%d]\n",tPasajero);
               }
            break;
            case 4:
                tPasajero = ll_count(listaVuelos,contarpasajerosIrlanda);
                if(tPasajero > 0) {
                    printf("TOTAL DE PASAJEROS IRLANDA [%d] \n",tPasajero);
                    system("pause");
                }else {
                    printf("TOTAL DE PASAJEROS [%d]\n",tPasajero);
                }
            break;
            case 5:

                quantity_Vuelo = controller_saveAsText("vuelosCorto.csv",listaVuelos);
                if(quantity_Vuelo > 0){
                    printf("\nexito");
                    system("pause");
                }else{
                    printf("\nError ");
                }
            break;
            case 6:
                listaPortugal = controller_listaVuelosPortugal(listaVuelos);
                if(listaPortugal != NULL){
                   inprimirVuelos(listaPortugal);
                   system("pause");
                }

            break;
            case 7:
                listamenosAlex = controller_listaVuelosmenosAlex(listaVuelos);
                if(listamenosAlex != NULL){
                   inprimirVuelos(listamenosAlex);
                   system("pause");
                }
            break;
            case 8:

            break;
            default:
                printf("Opcion invalida\n");
                system("pause");
            break;
        }
    }while(opcion != 8);

    return 0;
}
//^ =alt94
