#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee)); //
}
Employee* employee_newParametros(int* idStr, char* nombreStr,int* horasTrabajadasStr,int* sueldoStr)
{
  Employee* aux = employee_new();

  if(aux != NULL ){
    employee_setId(aux, *idStr);
    employee_setName(aux, nombreStr);
    employee_setHorasTrabajadas(aux, *horasTrabajadasStr);
    employee_setSueldo(aux, *sueldoStr);
  }else{
    employee_delete(aux);
    aux = NULL;
  }
  return aux;
}

int employee_setName(Employee* this,char* name)
{
    int returnValue = 0;

    if(this != NULL
       && this->nombre !=NULL
       && name != NULL)
    {
        strcpy(this->nombre, name);
        returnValue = 1;
    }

    return returnValue;
}

int employee_getName(Employee* this,char* nombre)
{
  int returnValue = 0;

  if(this != NULL && this -> nombre != NULL){
    strcpy(nombre, this->nombre);
    returnValue = 1;
  }
  return returnValue;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int returnValue = 0;
    if(this != NULL && sueldo >= 0 && sueldo <= 50000 ){
            this->sueldo = sueldo;
        returnValue = 1;
    }
    return  returnValue;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
  int returnValue = 0 ;
  if(this != NULL){
    *sueldo = this->sueldo;
    returnValue = 1;
  }
return returnValue;
}

int employee_setId(Employee* this,int id)
{
  int returnValue = 0;
  if(this != NULL){
    this -> id = id;

    returnValue=1;
  }

  return returnValue;

}
int employee_getId(Employee* this,int* id)
{
    int returnValue = 0;
    if(this != NULL){
        *id = this ->id;
        returnValue = 1;
    }
    return returnValue;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int returnValue = 0;

    if(this != NULL && horasTrabajadas >=0 && horasTrabajadas <= 200){
        this->horasTrabajadas = horasTrabajadas;
        returnValue = 1;
    }
    return returnValue;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    int retrunValue = 0;
    if(this != NULL){
        *horasTrabajdas = this -> horasTrabajadas;
        retrunValue = 1;
    }
    return retrunValue;
}


int employee_CompareByName(void* e1, void* e2){
    int ret_value;

    Employee* emp1 = (Employee*)e1;
    Employee* emp2 = (Employee*)e2;
    if(emp1 != NULL && emp2 != NULL){

       ret_value = strcmp(emp1->nombre,emp2->nombre);
    }
    return ret_value;
}

int employee_CompareById(void* e1, void* e2) {
    int ret_value;
    Employee* emp1 = (Employee*)e1;
    Employee* emp2 = (Employee*)e2;

    if(emp1 != NULL && emp2 != NULL) {
        if(emp1->id > emp2->id) {
            ret_value = 1;
        }else {
            if(emp1->id  < emp2->id) {
                ret_value = -1;
            }else {
                ret_value = 0;
            }
        }
    }
    return ret_value;
}

void employee_delete(Employee* this){

    if(this != NULL){
        free(this);
    }
}
int employee_print(Employee* this){

    int ret_Value = -1;
    int id_empl;
    char name[100];
    int workHours;
    int salary;
    if(this != NULL){
       if(employee_getId(this,&id_empl)&& employee_getName(this,name)
          && employee_getHorasTrabajadas(this, &workHours)
          && employee_getSueldo(this,&salary)){
                printf("+=======+======================+=======+============+\n");
                printf("|   ID  |        NOMBRE        | HORAS |   SALARIO  |\n");
                printf("+=======+======================+=======+============+\n");
                printf("| %5d | %20s | %5d | %10d |\n",id_empl,name,workHours,salary);
                printf("+-------+----------------------+-------+------------+\n");
                ret_Value = 1;
          }
    }
return ret_Value;
}


