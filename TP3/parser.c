#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "Validacio.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int id;
    char buffer[4][100];
    int workHours;
    int salary;
    int ret_value = 0;
    Employee* aux;

    if(pFile != NULL && pArrayListEmployee != NULL && ll_clear(pArrayListEmployee) == 0){

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        while(!feof(pFile)) {
             if(feof(pFile)) {
                break;
             }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            id = atoi(buffer[0]);
            workHours = atoi(buffer[2]);
            salary = atoi(buffer[3]);
            generarMaximoid(id);

            aux = employee_newParametros(&id,buffer[1],&workHours,&salary);
            if(aux != NULL && ll_add(pArrayListEmployee,(Employee*)aux) == 0){
                ret_value++;
            }
        }
    }

    return ret_value;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret_value = 0;

    Employee auxEmployee;
    Employee* one_employee = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL && ll_clear(pArrayListEmployee) == 0)
    {
        while(!feof(pFile)){
          if(feof(pFile)){
            break;
          }
            if(fread((Employee*)&auxEmployee,sizeof(Employee),1,pFile) == 1){
                generarMaximoid(auxEmployee.id);
                one_employee = employee_newParametros(&(auxEmployee.id),auxEmployee.nombre,&(auxEmployee.horasTrabajadas),&(auxEmployee.sueldo));
                if(one_employee != NULL && ll_add(pArrayListEmployee,(Employee*)one_employee) == 0 ){
                    ret_value++;
                }
            }
        }
    }

    return ret_value;
}
