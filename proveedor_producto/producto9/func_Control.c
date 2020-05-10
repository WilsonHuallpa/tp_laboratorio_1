
#include <stdio.h>
#include <string.h>
#include "func_Control.h"

//Funcion que tiene las opciones del menu (Funcion de control)
void menuApp(void)
{
    printf("\n------MENU ALUMNO------\n\n");
    printf("(1) Cargar un nuevo producto y su proveedor\n");
    printf("(2) Listar todos los productos\n");
    printf("(3) Listar todos los proveedores\n");
    printf("(4) Los proveedores con sus productos\n");
    printf("(5) El proveedores con mas productos\n");
    printf("(6) Modificar un producto\n");
    printf("(7) Modificar un proveedor\n");
    printf("(8) Eliminar un producto\n");
    printf("(9) Eliminar un provedor\n");
    //printf("(10) Eliminar un proveedor y sus productos\n");
    //printf("(11) Ordenar por producto\n");

    printf("(12) Salir\n");
    printf("\n-----------------------\n");
}

//Funcion que me permite ingresar un entero (Funcion de complemento)
int getInt(char mensaje[], char mensajeError[], int Min, int Max, int Intentos)
{
    int valor;

    printf("%s", mensaje);
    scanf("%d", &valor);

    valor = validacionGetInt(valor, mensajeError, Min, Max, Intentos); //llamo a la funcion que valida el valor ingresado entre el minimo y maximo.

    return valor;
}

//Funcion de validacion minimo y maximo (Funcion de complemento)
int validacionGetInt(int valor, char mensajeError[], int Min, int Max, int Intentos)
{
    int contador = 0;

    while(valor < Min || valor > Max)
    {
        contador++;
        printf("%s", mensajeError);
        scanf("%d", &valor);

        if(contador == Intentos)
        {
            printf("Usastes todos tus intentos...");
            valor = Max;
        }
    }
    return valor;
}
