#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacio.h"
#include "ArrayEmployees.h"
#define ELEMENT 3

int main()
{
    int id;
    int index;
    int contadorId= 0;
    int contador = 0;
    float suma = 0;
    float promedio = 0;
    char seguir;
    int opcion;
    int opcion2;

    Employee listEmployee[ELEMENT];
    initEmployees(listEmployee, ELEMENT);

    do  {
        printf("*************************\n");
        printf(">     MENU EMPLOYEE     <\n");
        printf("*************************\n\n");
        printf(" 1. ALTA EMPLOYEE \n");
        printf(" 2. MODIFICAR EMPLOYEE \n");
        printf(" 3. BAJA EMPLOYEE \n");
        printf(" 4. INFORMES EMPLOYEE \n");
        printf(" 5. SALIR \n\n");
        opcion = validate_option("INGRESE UNA OPCION: ");
        switch(opcion) {
            case 1:
                contadorId++;
                addEmployee(listEmployee, ELEMENT,contadorId);
                break;
            case 2:
                   index = findEmployeeById(listEmployee, ELEMENT, selectId(listEmployee, ELEMENT));
                    if(index!= -1){
                    printf("\t\t\t\t\t*************************\n");
                    printf("\t\t\t\t\t>    MODIFICAR EMPLOYEE      <\n");
                    printf("\t\t\t\t\t*************************\n\n");
                    printf("  1. NOMBRE\n");
                    printf("  2. APELLIDO\n");
                    printf("  3. SALARIO\n");
                    printf("  4. SECTOR\n");
                    printf("  5. SALIR\n\n\n");
                    opcion2 = validate_option("INGRESE UNA OPCION: ");
                    switch(opcion2) {
                        case 1:
                            printf("\n\t\t------------Employee NAME: %s\t ID:%d--------------\n",listEmployee[index].name,listEmployee[index].id);
                            GetString("\n-Ingrese nuevo nombre del empleado: ", listEmployee[index].name);
                            break;
                        case 2:
                            printf("\n\t\t------------Employee LASNAME: %s\t ID:%d--------------\n",listEmployee[index].lastName,listEmployee[index].id);
                            GetString("\n-Ingrese nuevo Apellido del empleado: ", listEmployee[index].lastName);
                            break;
                        case 3:
                            printf("\n\t\t------------Employee SALARY: %.2f\t ID:%d--------------\n",listEmployee[index].salary,listEmployee[index].id);
                            listEmployee[index].salary=GetFloat("Ingrese nuevo salario: ");
                            break;
                        case 4:
                            printf("\n\t\t------------Employee SALARY: %d \t ID:%d--------------\n",listEmployee[index].sector,listEmployee[index].id);
                            listEmployee[index].sector=GetInt("Ingrese nuevo  sector: ");
                            break;
                        case 5:
                            printf("Modificacion cancelada\n");
                            break;
                        default:
                            printf("\nOPCION INVALIDAD\n");
                    }
                }else{
                    printf("\nNO  HAY EMPLEADOS INGRESADO\n"); }
                break;
            case 3:
                    printf("\t\t\t\t\t*************************\n");
                    printf("\t\t\t\t\t>     BAJA EMPLOYEE     <\n");
                    printf("\t\t\t\t\t*************************\n\n");
                id = selectId(listEmployee, ELEMENT);
                if((removeEmployee(listEmployee , ELEMENT, id)) == -1) {
                    printf("\nNo hay empleados ingresados con ese id\n");
                }
                break;
            case 4:
                    printf("\t\t\t\t\t************************\n");
                    printf("\t\t\t\t\t>     IMFORMES         <\n");
                    printf("\t\t\t\t\t************************\n\n");
                    sortEmployees(listEmployee, ELEMENT, DOWN);
                    if((printEmployees(listEmployee, ELEMENT)) == -1){
                        printf("\nNo hay empleados ingresados\n");
                    }else {
                           contador = totalSalary(listEmployee, ELEMENT, promedio, suma);
                           printf("\n-Cantidad de empleados que superan el salario promedio: %d\n", contador);
                    }

                break;
            case 5:
                seguir = GetChar("\nPara salir oprima 's'\n");
                break;
            default:
                printf("\n\nOpcion invalida\n\n");
        }
        system("pause");
        system("cls");
    } while(seguir != 's');
}
