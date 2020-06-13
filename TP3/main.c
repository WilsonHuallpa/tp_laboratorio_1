#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menuEmplo.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    int quantity_Employee = 0;
    int check_Employe = 0;
    int optionmenu;
    if (listaEmpleados == NULL){
        printf("No se encontro un espacio en memoria.\n");
        exit(EXIT_FAILURE);
    }
    do{
        system("cls");
        optionmenu = menu_main();
        switch(optionmenu){
            case 1:
                quantity_Employee = controller_loadFromText("data.csv",listaEmpleados);
                if(quantity_Employee > 0){
                    printf("se cargaron %d empleados desde el archivo de texto.\n",quantity_Employee);
                    system("pause");
                }else{
                    printf("ERROR... Talves ya cargo el archivo\n");
                    system("pause");
                }
            break;
            case 2:
                quantity_Employee = controller_loadFromBinary("data.bin", listaEmpleados);
                if(quantity_Employee > 0){
                    printf("se crearon %d empleados desde el archivo binario.\n",quantity_Employee);
                    system("pause");
                }else{
                    printf("ERROR... Talves ya cargo el archivo\n");
                    system("pause");
                }
            break;
            case 3:
                system("cls");
                check_Employe = controller_addEmployee(listaEmpleados);
                if(check_Employe > 0){
                    printf("\nexito\n");
                    system("pause");
                }else{
                    printf("\nerror");
                }
            break;
            case 4:
                system("cls");
                quantity_Employee = controller_editEmployee(listaEmpleados);
                if(quantity_Employee > 0){
                    printf("\nExito\n");
                    system("pause");
                }else{
                    printf("\nError\n");
                    system("pause");
                }

            break;
            case 5:
                system("cls");
                quantity_Employee = controller_removeEmployee(listaEmpleados);
                if(quantity_Employee > 0){
                    printf("\nexito");
                    system("pause");
                }else{
                    printf("\nError el la id no es validad");
                }

            break;
            case 6:
                system("cls");
                quantity_Employee = controller_ListEmployee(listaEmpleados);
                if (quantity_Employee < 0){
                    printf(" \nNo se pudo listar los empleados\n");
                }else {
                    printf("\nListado ok! \n");
                }
            break;
            case 7:
                system("cls");
                quantity_Employee = controller_sortEmployee(listaEmpleados);
                if (quantity_Employee > 0){
                    printf(" \nexito\n");
                }
            break;
            case 8:
                system("cls");
                quantity_Employee=controller_saveAsText("data.csv",listaEmpleados);
                if(quantity_Employee > 0 ){
                    printf("Archivo de texto guardado correctamente.\n");
                }else{
                    printf("No se pudo guardar el archivo de texto.\n");
                }
            break;
            case 9:
                system("cls");
                quantity_Employee = controller_saveAsBinary("data.bin",listaEmpleados);
                if(quantity_Employee > 0){
                    printf("Archivo de binario guardado correctamente.\n");
                }else{
                    printf("No se pudo guardar el archivo Binario.\n");
                }

            break;
            case 10:
            break;
            default:
                printf("Opcion invalida\n");
                system("pause");
            break;
        }
    }while(optionmenu != 10);

return 0;
}

//^ =alt94
