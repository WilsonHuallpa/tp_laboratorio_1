#include <stdio.h>
#include <string.h>
#include "proveedor.h"
#include "func_Control.h"


void harcodeoProveedor(sProveedor listaProveedor[], int tProv)
{
    //Arrays paralelos.
    int idProveedor[4] = {100, 101, 102, 103};
    char nombreProveedor[4][50] = {"Osmar","ArgentinaLuz","FereteLuz","Luz"};
    char localidad[4][50] = {"Lanus","Avellaneda","San Fernando","Recoleta"};
    int estadoProveedor[4] = {OCUPADO,OCUPADO,OCUPADO,LIBRE};


    int i;
    //Recorro y asigno el valor del array paralelo
    for(i=0; i<tProv; i++)
    {
        listaProveedor[i].idProveedor = idProveedor[i];
        strcpy(listaProveedor[i].nombreProveedor, nombreProveedor[i]);
        strcpy(listaProveedor[i].localidad, localidad[i]);

        listaProveedor[i].estadoProveedor = estadoProveedor[i];
    }
}

//Inicializacion de la lista -1
void inicializarProveedor(sProveedor listaProveedor[], int tProv)
{
  int i;
  for(i=0; i<tProv; i++)
  {
      listaProveedor[i].estadoProveedor = LIBRE;
  }
}

//Funcion que busca un espacio libre en el array alumno (Funcion de complemento)
int buscarLibreProveedor(sProveedor listaProveedor[], int tProv)
{
    int i;
    int index = -1;
    for(i=0; i<tProv; i++)
    {
        if(listaProveedor[i].estadoProveedor == LIBRE)
        {
            index = i;
            break;
        }
    }
    printf("\nValor del index %d\n", index);
    return index;
}

//Funcion que permite cargar un proveedor en una pocicion libre (Funcion de control)
void cargarListaProveedor(sProveedor listaProveedor[], int tProv)//convertir la funcion a un retorno entero
{
    int encontro;
    encontro = buscarLibreProveedor(listaProveedor, tProv);//llamaco a funcion
    if(encontro!=-1)
    {
       listaProveedor[encontro] = cargarUnProveedor(); //llamaco a funcion
    }
    else
    {
        printf("No hay espacio\n");
    }

}

//Funcion que carga un producto (Funcion de control y complemento)
sProveedor cargarUnProveedor(void)
{
    sProveedor unProveedor;

    unProveedor.idProveedor = getInt("\nIngrese el id del proveedor: ","\nError, el id es muy largo.\nIngrese el id del proveedor: ", MIN_IDPROVEEDOR, MAX_IDPROVEEDOR, INTEN_IDPROVEEDOR);

    //getStringLetras("\nIngrese nombre de producto: ", unProducto.nombreProducto);


    printf("\nIngrese nombre del proveedor: "); //Nota: validar
    fflush(stdin);
    fgets(unProveedor.nombreProveedor,50,stdin);
    unProveedor.nombreProveedor[strlen(unProveedor.nombreProveedor)-1]='\0';

    //getStringLetras("\nIngrese nombre de producto: ", unProducto.nombreProducto);

    printf("\nIngrese nombre de la localidad: "); //Nota: validar
    fflush(stdin);
    fgets(unProveedor.localidad,50,stdin);
    unProveedor.localidad[strlen(unProveedor.localidad)-1]='\0';

    unProveedor.estadoProveedor = OCUPADO;

    return unProveedor;
}

void mostrarTodosLosProveedores(sProveedor listaProveedor[], int tProv)
{
    int i;
    for(i=0; i<tProv; i++)
    {
        mostrarUnProveedor(listaProveedor[i]);
    }

}
void mostrarUnProveedor (sProveedor unProveedor)
{
  printf ("%10d %19s %18s\n", unProveedor.idProveedor, unProveedor.nombreProveedor, unProveedor.localidad);
}

//Funcion para eliminar un proveedor (Funcion de control)
void eliminarProveedor(sProveedor listaProveedor[], int tProv)
{
    int proveedorID;
    int i;

    proveedorID = getInt("\nIngrese el id del proveedor: ",
                         "\nError, el id es muy largo.\nIngrese el id del proveedor: ",
                         MIN_IDPROVEEDOR, MAX_IDPROVEEDOR, INTEN_IDPROVEEDOR);

    for(i=0; i<tProv; i++)
    {
        if(listaProveedor[i].estadoProveedor == OCUPADO && proveedorID == listaProveedor[i].idProveedor)
        {
            listaProveedor[i].estadoProveedor = LIBRE;
            break;
        }
    }

}
void ModificarProvedor(sProveedor listaProveedor[], int tProv){
    int proveedorID;
    int opcion;
    int i;

    productoID = getInt("\nIngrese el id del proveedor: ","\nError, el id es muy largo.\nIngrese el id del proveedor: ",MIN_IDPROVEEDOR , MAX_IDPROVEEDOR, INTEN_IDPROVEEDOR); //Funcion para pedir el idProducto al usuario
    for(i=0; i<tProv; i++)
    {
        if(listaProveedor[i].estadoProveedor == OCUPADO && proveedorID == listaProveedor[i].idProveedor)
        {
            printf(" \n\t\t--------ID %d-------\n\n ",listaProveedor[i].idProveedor);
            mostrarUnProveedor(listaProveedor[i]);

            printf("\n1.nombre a modificar\n");
            printf("2. localidad a modificar\n");
            printf("3. salir \n");

            scanf("%d",&opcion);
            switch(opcion){
                case 1:
                     printf("\n Ingrese nuevo nombre: ");
                     fflush(stdin);
                     gets(listaProveedor[i].nombreProveedor);
                    break;
                case 2:
                    printf("\n Ingrese nuevo localidad: ");
                     fflush(stdin);
                     gets(listaProveedor[i].localidad);
                    break;
                case 3:
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
