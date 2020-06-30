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
    LinkedList* listaFiltrada;

    int opcion;
    int quantity_Vuelo;
    int quantity_piloto;
    int tPasajero;
    int sort;

    if (listaVuelos == NULL || listapiloto == NULL) {
        printf("No se encontro espacio en memoria.");
        exit(EXIT_FAILURE);
    }

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
        printf(" |  [8] Filtrar la lista de piloto por nombre.                                       |\n");
        printf(" |  [9] Ordenar lista vuelos.                                                        |\n");
        printf(" |  [10] Salir del programa.                                                         |\n");
        printf(" +-----------------------------------------------------------------------------------+\n\n");
        printf("\n\nIngrese una opcion : ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                system("cls");
                printf("Archivo Disponible [Vuelos.csv] [pilotos.csv] \n\n");

                quantity_Vuelo = controller_huallpa_loadFromText("Vuelos.csv",listaVuelos);
                quantity_piloto = controller_huallpa_loadpiloto("pilotos.csv",listapiloto);

                if(quantity_Vuelo > 0 && quantity_piloto > 0){
                    printf("se cargaron %d vuelos desde el archivo de texto.\n",quantity_Vuelo);
                    printf("se cargaron %d pilotos desde el archivo de texto.\n\n",quantity_piloto);

                    system("pause");
                }else{
                    printf("ERROR...\n");
                    system("pause");
                }
            break;
            case 2:
                controller_huallpa_imprimirVuelos(listaVuelos,listapiloto);
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
                quantity_Vuelo = controller_huallpa_saveAsText("vuelosCorto.csv",listaVuelos);
                if(quantity_Vuelo > 0){
                    printf("\nexito");
                    system("pause");
                }else{
                    printf("\nError ");
                }
            break;
            case 6:
                listaPortugal = controller_huallpa_listaVuelosPortugal(listaVuelos);
                if(listaPortugal != NULL){
                   controller_huallpa_inprimirVuelos(listaPortugal);
                   system("pause");
                }

            break;
            case 7:
                listamenosAlex = controller_huallpa_listaVuelosmenosAlex(listaVuelos);
                if(listamenosAlex != NULL){
                   controller_huallpa_inprimirVuelos(listamenosAlex);
                   system("pause");
                }
            break;
            case 8:
                listaFiltrada = controller_huallpa_filtrarPorNombre(listapiloto);
                if(listaFiltrada != NULL){
                     piloto_imprimirPilotos(listaFiltrada);
                     system("pause");
                }

            break;
            case 9:
                sort = controller_huallpa_sortvuelos(listaVuelos);
                if(sort == 1){
                    controller_huallpa_inprimirVuelos(listaVuelos);
                    system("pause");
                }
            break;
            case 10:
                 printf("GRACIAS POR USAR EL PROGRAMA...\n");
                 system("pause");
            break;
            default:
                printf("Opcion invalida\n");
                system("pause");
            break;

        }
    }while(opcion != 10);

    return 0;
}
//^ =alt94
