#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Validacio.h"

int validate_option(char mensaje[]) {

    int num = 0;
    char auxNum[31];
    printf("%s: ",mensaje);
    fflush(stdin);
    gets(auxNum);

    while(validate_number(auxNum)!= 1 || auxNum[0]=='\0') {
        printf("ERROR...No es Numero. \n%s: ",mensaje);
        fflush(stdin);
        gets(auxNum);
    }
    num = atoi(auxNum);
return num;
}

int validate_number(char numero[]) {
    int i;
    int retorno = 1;
    for(i=0 ; i<strlen(numero) ; i++){
        if(!(isdigit(numero[i]))){
            retorno = 0;
            break;
        }
    }
  return retorno;
}

int validate_Word(char palabra[]) {
    int i;
    int retorno = 1;
    for(i=0; i<strlen(palabra);i++){
        if(!(isalpha(palabra[i]))) {
            retorno = 0;
            break;
        }
    }
return retorno;
}

void GetString(char message[],char input[]) {

    printf("%s",message);
    fflush(stdin);
    gets(input);

    while(validate_Word(input)!=1 || input[0]=='\0' || input[0]==' ' || (strlen(input)<3)) {

        printf("ERROR..INGRESE DATOS VALIDOS...\n ");
        printf("%s",message);
        fflush(stdin);
        gets(input);
    }

}

int GetInt(char message[]) {
    int num;
    char auxNum[11];
    printf("%s",message);
    fflush(stdin);
    gets(auxNum);
    while(validate_number(auxNum)!=1 || auxNum[0]=='\0')
    {
        printf("ERROR..INGRESE DATOS VALIDOS...\n");
        printf("%s",message);
        fflush(stdin);
        gets(auxNum);
    }
    num=atoi(auxNum);
    return num;
}

float GetFloat(char message[]) {
    float salary;
    printf("%s",message);
    scanf("%f",&salary);
    return salary;
}

char GetChar(char message[]) {

    char letter;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&letter);
    while((letter != 's' && letter !='S' && letter !='n' && letter !='N')) {
        printf("INGRESE CARACTER VALIDO (s/n):  ");
        fflush(stdin);
        scanf("%c",&letter);
    }

return letter;
}

int GenerarId(int id,int cont) {

    return id+cont;
}

int generarMaximoid(int num){

    static int auxid = 0;

    if(num > auxid){

        auxid = num;

    }else if(num == -1){
        auxid++;
    }
 return auxid;
}

