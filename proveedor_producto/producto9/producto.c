#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "producto.h"
//#include "proveedor.h"
#include "func_Control.h"

void harcodeoProducto(sProducto listaProducto[], int tProd) //, sProveedor listaProveedor[], int tProv
{
    //Arrays paralelos.
    int idProducto[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char nombreProducto[10][50] = { "Lampara",
                                    "Cable Rojo",
                                    "Cable Verde",
                                    "Enchufe",
                                    "Cable Negro",
                                    "Lampara Led",
                                    "Alargador Amarillo",
                                    "Cable Azul",
                                    "Cable Violeta",
                                    "Alargador Rojo"
                                  };
    float precio[10] = {23.5, 45.5, 23.7, 23.1, 26.5, 12.5, 4, 50, 18.4, 43};
    int stock[10] = {43, 5, 46, 17, 28, 9, 10, 4, 10, 11};

    int idProveedor[10] = {100,100, 101,101,101, 101,102,102,102,102};//FK
    int estadoProducto[10] = {OCUPADO,OCUPADO,LIBRE,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO};

    int i;
    //Recorro y asigno el valor del array paralelo
    for(i=0; i<tProd; i++)
    {
        listaProducto[i].idProducto = idProducto[i];
        strcpy(listaProducto[i].nombreProducto, nombreProducto[i]);
        listaProducto[i].precio = precio[i];
        listaProducto[i].stock = stock[i];

        listaProducto[i].idProveedor = idProveedor[i];

        listaProducto[i].estadoProducto = estadoProducto[i];

    }
}

//Inicializacion de la lista -1
void inicializarProductos(sProducto listaProducto[], int tProd)
{
  int i;
  for(i=0;i<tProd;i++)
  {
      listaProducto[i].estadoProducto = LIBRE;
  }
}

//Funcion que busca un espacio libre en el array alumno (Funcion de complemento)
int buscarLibreProducto(sProducto listaProducto[], int tProd)
{
    int i;
    int index = -1;
    for(i=0; i<tProd; i++)
    {
        if(listaProducto[i].estadoProducto == LIBRE)
        {
            index = i;
            break;
        }
    }
    printf("Valor del index %d", index);
    return index;
}

//Funcion que permite cargar un alumno en una pocicion libre (Funcion de control)
void cargarListadoDeProducto(sProducto listaProducto[], int tProd)//convertir la funcion a un retorno entero
{
    int encontro;
    encontro = buscarLibreProducto(listaProducto, tProd);//llamaco a funcion
    if(encontro!=-1)
    {
       listaProducto[encontro] = cargarUnProducto(); //llamaco a funcion
    }
    else
    {
        printf("No hay espacio\n");
    }

}

//Funcion que carga un producto (Funcion de control y complemento)
sProducto cargarUnProducto(void)
{
    sProducto unProducto;

    unProducto.idProducto = getInt("\nIngrese el id del producto: ","\nError, el id es muy largo.\nIngrese el id del producto: ", MIN_IDPRODUCTO, MAX_IDPRODUCTO, INTEN_IDPRODUCTO);

    //getStringLetras("\nIngrese nombre de producto: ", unProducto.nombreProducto);

    printf("\nIngrese nombre del producto: "); //Nota: validar
    fflush(stdin);
    fgets(unProducto.nombreProducto,50,stdin);
    unProducto.nombreProducto[strlen(unProducto.nombreProducto)-1]='\0';

    unProducto.precio = getInt("\nIngrese el precio del producto: ","\nError, el id es muy largo.\nIngrese el Ingrese el precio del producto: ", MIN_PRECIO, MAX_PRECIO, INTEN_PRECIO);

    unProducto.stock = getInt("\nIngrese el stock del producto: ","\nError, el id es muy largo.\nIngrese el stock del producto: ", MIN_STOCK, MAX_STOCK, INTEN_STOCK);

    //unProducto.idProveedor = unProveedor.idProveedor; //Valor de la carga de la estructura .idProvedor; //Nota: FK? <----

    unProducto.estadoProducto = OCUPADO;

    return unProducto;
}

//Muestro los productos (Funcion de control)
void mostrarTodosLosProducto(sProducto listaProducto[], int tProd)
{
    int i;
    for(i=0; i<tProd; i++)
    {
        mostrarUnProducto(listaProducto[i]);
    }

}

//Funcion para imprimir un producto (Funcion de complemento)
void mostrarUnProducto (sProducto unProducto)
{
   printf("%10d %20s %14.2f %14d\n", unProducto.idProducto, unProducto.nombreProducto, unProducto.precio, unProducto.stock);
}

//Funcion para eliminar un producto (Funcion de control)
void eliminarProducto(sProducto listaProducto[], int tProd)
{
    int productoID;
    int i;

    productoID = getInt("\nIngrese el id del producto: ",
                        "\nError, el id es muy largo.\nIngrese el id del producto: ",
                        MIN_IDPRODUCTO, MAX_IDPRODUCTO, INTEN_IDPRODUCTO); //Funcion para pedir el idProducto al usuario

    for(i=0; i<tProd; i++)
    {
        if(listaProducto[i].estadoProducto == OCUPADO && productoID == listaProducto[i].idProducto)
        {
            listaProducto[i].estadoProducto = LIBRE;
            break;
        }
    }
}


void Modificarunproduct(sProducto listaProducto[], int tProd){
    int productoID;
    int opcion;
    int i;

    productoID = getInt("\nIngrese el id del producto: ","\nError, el id es muy largo.\nIngrese el id del producto: ",MIN_IDPRODUCTO, MAX_IDPRODUCTO, INTEN_IDPRODUCTO); //Funcion para pedir el idProducto al usuario

    for(i=0; i<tProd; i++)
    {
        if(listaProducto[i].estadoProducto == OCUPADO && productoID == listaProducto[i].idProducto)
        {
            printf(" \n\t\t--------ID %d-------\n\n ",listaProducto[i].idProducto);
            mostrarUnProducto(listaProducto[i]);

            printf("\n1. nombre a modificar\n");
            printf("2. precio a modificar\n");
            printf("3. stock a modificar\n");
            printf("4. salir \n");

            scanf("%d",&opcion);
            switch(opcion){
                case 1:
                     printf("\n Ingrese nuevo nombre: ");
                     fflush(stdin);
                     gets(listaProducto[i] .nombreProducto);
                    break;
                case 2:
                    printf("\n ingrese nuevo precio: ");
                    scanf("%f",&listaProducto[i].precio);
                    break;
                case 3:
                    printf("\n ingrese nuevo stock: ");
                    scanf("%d",&listaProducto[i].stock);
                    break;
                case 4:
                    printf("\n no se modifico nada!!");
                    break;
                default:
                    printf("\n no es una opcion");
                    break;
            }

            break;
        }
    }
}




