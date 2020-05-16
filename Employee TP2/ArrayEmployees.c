#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TRUE 1
#define OCCUPIED 0


int initEmployees(Employee ListEmployee[], int len) {

    int index;
    int returno = 1;
    if(len > 0) {
        for(index = 0; index < len; index++) {

            ListEmployee[index].isEmpty = TRUE;
        }
    returno = 0;
    }
return returno;
}

int searchFreeEmployee(Employee ListEmployee[], int len) {

    int index;
    int returno = -1;

    if(len > 0) {
        for(index = 0; index < len; index++) {

            if(ListEmployee[index].isEmpty == TRUE) {

                returno = index;
                break;
            }
        }
    }

return returno;
}

int selectId(Employee list[], int len) {

    int id = -1;

    if(printEmployees(list, len) != -1) {

        printf("\nIngrese id Employee: ");
        fflush(stdin);
        scanf("%d",&id);
    }

return id;
}

int addEmployee(Employee List[], int len, int cont) {
    int index = -1;

    if(len > 0) {
        index = searchFreeEmployee(List, len);

        if(index != -1) {

            printf("*************************\n");
            printf(">     ALTA EMPLOYEE     <\n");
            printf("*************************\n");
            GetString("Ingrese nombre del empleado: ", List[index].name);
            GetString("Ingrese apellido del empleado: ", List[index].lastName);
            List[index].salary=GetFloat("Ingrese salario: ");
            List[index].sector=GetInt("Ingrese sector: ");
            List[index].id = GenerarId(999,cont);
            List[index].isEmpty = OCCUPIED;
            index = 0;
        }else{
            printf("NO se encontro lugar disponibles\n");
        }
    }

    return index;
}

int findEmployeeById(Employee ListEmployee[], int len, int id) {

    int index;
    int returno = -1;

    if(len > 0 ) {

        for(index = 0; index < len; index++) {

            if(ListEmployee[index].id == id) {
                returno = index;
                break;
            }
        }
    }

return returno;
}

void printEmployee(Employee TheEmployee) {

    if(TheEmployee.isEmpty == OCCUPIED) {

        printf( "\t\t%d\t\t%s\t\t%s\t\t%.2f\t\t%d\n",TheEmployee.id,TheEmployee.name,TheEmployee.lastName,
                                                    TheEmployee.salary,TheEmployee.sector);
    }
}

int printEmployees(Employee List[], int length) {

    int index;
    int returno = -1;

    if(length > 0) {
        printf("\t\tID\t\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR\n");
        for(index = 0; index < length; index++) {
            printEmployee(List[index]);
            if(List[index].isEmpty == OCCUPIED){
              returno = 0;
            }
        }
    }

    return returno;
}

int removeEmployee(Employee ListEmployee[], int len, int id) {
    int index;
    int returno = -1;
    char eliminar;

    if(id >= 0) {

        index = findEmployeeById(ListEmployee, len, id);

        if(index != -1) {

            printf("\n\t\t------------Employee: %s, %s--------------\n",ListEmployee[index].lastName,ListEmployee[index].name);
            printf("\t\tID\t\tSALARIO\t\tSECTOR\n");
            printf("\t\t%d\t\t%.2f\t\t%d\n",ListEmployee[index].id,ListEmployee[index].salary,
                                           ListEmployee[index].sector);

           eliminar= GetChar("\nPara eliminar oprima 's'\n");
            if(eliminar == 's') {
                ListEmployee[index].isEmpty = TRUE;
                returno = 1;
            }
        }
    }
return returno;
}

int sortEmployees(Employee List[], int len, int order) {
    Employee aux;
    int i;
    int j;
    int returno = -1;

    for(i = 0; i < len -1; i++) {

        for(j = i + 1; j < len; j++){
            if(order == DOWN){

                if(strcmp(List[i].lastName, List[j].lastName) > 0){

                    aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;

                }else if(strcmp(List[i].lastName, List[j].lastName) == 0) {

                    if(List[i].sector < List[j].sector) {
                        aux = List[i];
                        List[i] = List[j];
                        List[j] = aux;
                    }
                }
            }

            if(order == UPP){
                if(strcmp(List[i].lastName, List[j].lastName) < 0) {

                    aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }else if(strcmp(List[i].lastName, List[j].lastName) == 0) {

                    if(List[i].sector > List[j].sector) {

                        aux = List[i];
                        List[i] = List[j];
                        List[j] = aux;
                    }
                }
            }

            returno = 0;
        }
    }

return returno;
}

int totalSalary(Employee List[], int len, float Promedy, float Suma) {

    int Counter = 0;
    int CounterMaxim = 0;
    int flag = 0;
    int index = 0;
    int returno = -1;
    float Acum = 0;

    for(index = 0; index < len; index++) {
        if(List[index].isEmpty == OCCUPIED) {
            Acum += List[index].salary;
            Counter++;
            returno = 0;
        }
    }

    Promedy = Acum / Counter;

    Suma = Acum;

    for(index = 0; index < len;  index++) {
        if(flag == 0 || List[index].salary > Promedy) {
            CounterMaxim++;
            returno = 1;
        }
    }
    printf("\n-Suma de los salarios: %.2f\n", Suma);
    printf("\n-Promedio de los salarios: %.2f\n", Promedy);

    return returno;
}

