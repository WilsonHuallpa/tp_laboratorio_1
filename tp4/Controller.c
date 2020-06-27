#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Validacio.h"
#include "Controller.h"
#include "menuEmplo.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret_value = 0;
    FILE* fileText;

    if(pArrayListEmployee != NULL ){

        fileText = fopen(path,"r");

        if(fileText != NULL){

            ret_value = parser_EmployeeFromText(fileText,pArrayListEmployee);
        }
        fclose(fileText);
    }
    return ret_value;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret_value = 0;
    FILE* archivoBinario;

    if(pArrayListEmployee != NULL){

        archivoBinario = fopen(path,"rb");
        if(archivoBinario !=NULL){

            ret_value = parser_EmployeeFromBinary(archivoBinario,pArrayListEmployee);

        }
        fclose(archivoBinario);
    }
return ret_value;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret_value = 0;
    int id = -1;
    char name[100];
    int idMax;
    int workHours;
    int salary;
    Employee* aux = NULL;
    if (pArrayListEmployee != NULL){
            printf("+===================================================+\n");
            printf("|                   AGREGAR EMPLEADO                |\n");
            printf("+===================================================+\n\n");
            idMax = generarMaximoid(id);
            GetString("INGRESE NOMBRE: ",name);
            workHours = GetInt("INGRESE HORAS TRABAJADAS: ");
            salary = GetInt("INGRESE SUELDO: ");
            aux = employee_newParametros(&idMax,name,&workHours,&salary);
            if(aux != NULL && ll_add(pArrayListEmployee, (Employee*)aux) == 0){
             ret_value = 1;
            }
    }
    return ret_value;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret_value = 0;
    int id;
    int option;
    int index;
    char follow;

    Employee* editEmployee = employee_new();
    Employee* auxemployee;

    if(pArrayListEmployee != NULL && editEmployee != NULL){
        id = GetInt("Ingrese id del empleado: ");
        index = controller_findEmployeeById(pArrayListEmployee,id);
        if(index > -1){
            editEmployee = (Employee*)ll_get(pArrayListEmployee,index);
            if(editEmployee != NULL){
                auxemployee = employee_newParametros(&editEmployee->id,editEmployee->nombre,&editEmployee->horasTrabajadas,&editEmployee->sueldo);
                do{ system("cls");
                    if(employee_print(auxemployee) == 1 && menu_edit(&option) == 1){
                        ret_value = 1;
                        switch(option){
                            case 1:
                                    GetString("Ingrese nuevo nombre: ",auxemployee->nombre);
                                    if(employee_getName(auxemployee,auxemployee->nombre) == 1){
                                      printf("Nombre cambiado, elija la opcion 4 para aplicarlo.\n");
                                      system("pause");
                                    }
                            break;
                             case 2:
                                 auxemployee->horasTrabajadas = GetInt("ingrese nuevo horas trabajadas: ");
                                 if(employee_getHorasTrabajadas(auxemployee,&auxemployee->horasTrabajadas)){
                                    printf(" cambiado, elija la opcion 4 para aplicarlo.\n");
                                    system("pause");
                                 }
                            break;
                             case 3:
                                 auxemployee->sueldo = GetInt("Ingrese nuevo salario: ");
                                 if(employee_getSueldo(auxemployee,&auxemployee->sueldo)){
                                    printf("Cambiado, elija la opcion 4 para aplicarlo.\n");
                                    system("");
                                 }
                            break;
                             case 4:
                                 printf("EL siguente empleado:\n");
                                 if(employee_print(editEmployee)){
                                    printf("Sera modificado de la siguiente forma: \n");
                                    if(employee_print(auxemployee)){
                                       follow = GetChar("acepta la modificacion? [S]o[N]:");
                                        if(follow == 's' || follow == 'S'){
                                            ll_set(pArrayListEmployee,index,(Employee*)auxemployee);
                                        }
                                    }
                                 }
                            break;
                            default:
                                 printf("opcion invalidad\n");
                                 system("pause");
                            break;
                        }
                    }
                }while(option != 4);
            }
        }
    }
return ret_value;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    int idaux;
    char seguir;
    int index;
    Employee* aux = employee_new();
    if(pArrayListEmployee != NULL && aux != NULL){
        printf("ingrese id a eliminar : ");
        scanf("%d",&idaux);
        index = controller_findEmployeeById(pArrayListEmployee,idaux);

        if(index > -1 ){

            aux = (Employee*)ll_get(pArrayListEmployee,index);

            printf("\n\t\t------------Employee: %s--------------\n",aux->nombre);
            printf("\t\tID\t\tHORAS TRABAJADAS\t\tSUELDO\n");
            printf("\t\t%d\t\t%d\t\t%d\n",aux->id,aux->horasTrabajadas,aux->sueldo);

            seguir = GetChar("Deseas seguir (s/n)?");

            if(seguir == 's'){
              ll_remove(pArrayListEmployee,index);
              ret = 1;
            }
        }
    }
    employee_delete(aux);
    return ret;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int value = 0;
    int len;
    int counter;
    int lismax = 0;
    int lismin = 0;
    Employee* aux = employee_new();
    LinkedList* subList = ll_newLinkedList();
    if(pArrayListEmployee != NULL && subList != NULL ){

        len = ll_len(pArrayListEmployee);

        while(lismin < len){
            value++;

            if(len > (value * 20)){
                lismax = lismin + 20;
            } else{
                lismax = len;
            }
            subList = ll_subList(pArrayListEmployee,lismin,lismax);
            for(counter = lismin; counter < lismax ; counter++){
                  if(counter ==  lismin){
                    printf("+---------------------------------------------------------------+\n");
                    printf("\tID\t\tNOMBRE\t\tHORAS\t\tSUELDO\n");
                    printf("+---------------------------------------------------------------+\n");
                  }
                  aux=(Employee*)ll_get(pArrayListEmployee,counter);
                  if (aux != NULL){

                    printf("|%10d|%18s|%16d|%16d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
                  }
            }
            if(counter > 0 && counter == lismax && ll_clear(subList)== 0){
               printf("+---------------------------------------------------------------+\n");
            }
            lismin = counter;
            if(lismax <=len){
                system("pause");
                system("clear");
            }
            if(ll_len(subList) != 0 || ll_deleteLinkedList(subList) != 0){
                lismax = 0;
            }

        }
    }
return lismax;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret_value = 0;
    int order;
    int cont = 0;
    int option;

    if(pArrayListEmployee != NULL) {
        if(ll_len(pArrayListEmployee) > 0){
            do{ system("cls");
                if((menu_sort(&option)== 1) && option >=1 && option < 3){
                    order = GetInt("Ingrese para ordenar : [1] Asendente - [0] descente: ");
                    while(order != 1 && order != 0){
                        order = GetInt("Ingrese para ordenar : [1] Asendente - [0] descente: ");
                    }
                    printf("Aguarde un momento.\n");
                    switch(option){
                        case 1:
                            if(ll_sort(pArrayListEmployee,employee_CompareById,order)== 0){
                                printf("Ordenado por ID finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                        case 2:
                            if(ll_sort(pArrayListEmployee,employee_CompareByName,order)== 0){
                                printf("Ordenado por Nombre finalizado.\n");
                                system("pause");
                                ret_value = 1;
                            }
                        break;
                    }
                }else{
                    if(option > 3){
                    printf("opcion invalido.\n");
                    system("pause");
                    cont++;
                    }
                }
            }while(option != 3 && cont != 3);
        }
    }
return ret_value;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
      FILE* file = NULL;
      int ret_Value = 0;
      int arraylength;
      int i;

      Employee* aux;

      if (pArrayListEmployee != NULL){

            arraylength = ll_len(pArrayListEmployee);

            file = fopen(path, "w");

            if(file != NULL && arraylength > 0){

                fprintf(file,"Id,Nombre,Horastrabajasdas,Sueldo\n");

                for(i=0; i<arraylength; i++){

                    aux = (Employee*)ll_get(pArrayListEmployee,i);

                    if(aux != NULL ){

                    fprintf(file,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
                    ret_Value = 1;
                    }
                }
            }
      }
    fclose(file);
    return ret_Value;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* file = NULL;

    int ret_Value = 0;
    int arraylength;
    int i;
    Employee* aux;

    if(pArrayListEmployee != NULL){

        arraylength = ll_len(pArrayListEmployee);
        file = fopen(path, "wb");

        if(file != NULL && arraylength > 0){

            for(i=0 ; i < arraylength ; i++){

                aux = (Employee*)ll_get(pArrayListEmployee, i);

                if(aux != NULL){

                    fwrite((Employee*)aux,sizeof(Employee),1,file);
                    ret_Value = 1;
                }
            }
        }
    }
    fclose(file);
    return ret_Value;
}


int controller_findEmployeeById(LinkedList* pArrayListEmployee, int index) {

    int auxIndex = -1;
    int len;
    int i;
    Employee*  aux;
    if(pArrayListEmployee != NULL){
        len = ll_len(pArrayListEmployee);
        for(i=0 ; i<len ;  i++){
            aux = (Employee*)ll_get(pArrayListEmployee,i);
            if(aux->id == index){
                auxIndex = i;
                break;
            }
        }
    }
return auxIndex;
}


