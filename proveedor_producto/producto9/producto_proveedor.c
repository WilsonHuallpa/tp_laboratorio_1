#include <stdio.h>
#include "producto_proveedor.h"

//Funcion que me permite mostrar los proveedores con sus Productos (Funcion de control)
void mostrarProveedorConProducto(sProveedor listaProveedor[], int tProv, sProducto listaProducto[], int tProd)
{
    int i;//Proveedores
    int j;//Productos
    char flagTieneProducto;//bandera

    for(i=0; i<tProv; i++)
    {
        printf("\n\t\t------------Proveedor: %s--------------", listaProveedor[i].nombreProveedor);
        printf("\n\tID_PRODUCTO\t\tNOMBRE_PRODUCTO\t\tNOMBRE_PROVEEDOR\n");
        flagTieneProducto = 'n';

        for(j=0; j<tProd; j++)
        {
            if(listaProducto[j].idProveedor == listaProveedor[i].idProveedor)
            {

                printf("%19d %27s %24s\n", listaProducto[j].idProducto, listaProducto[j].nombreProducto, listaProveedor[i].nombreProveedor);
                flagTieneProducto = 's';
            }
        }

        if(flagTieneProducto == 'n')
        {
            printf("\t\t\tNo tiene productos el proveedor: %s\n", listaProveedor[i].nombreProveedor);

        }
    }

}

//Funcion que me permite mostrar el proveedor con mas Productos (Funcion de control)
void mostrarProveedorConMasProducto(sProveedor listaProveedor[], int tProv, sProducto listaProducto[], int tProd)
{
    sProd_Prov aux_ProvProd[tProv];//Array aux de la estructura producto_proveedor
    int i;//Proveedores
    int j;//Productos
    int maxProveedor;//Proveedor

    //for que inicializa
    for(i=0; i<tProv; i++)
    {
        aux_ProvProd[i].idProveedor = listaProveedor[i].idProveedor;
        aux_ProvProd[i].cantidadProducto = 0;
    }

    //inicializaArray(listaProveedor, tProv, listaProducto, tProd);

    //for que recorre los arrays y asigna el maximo al aux_ProvProd[i].cantidadProducto++;
    for(i=0; i<tProv; i++)
    {
        for(j=0; j<tProd; j++)
        {
            if(listaProducto[j].idProveedor == aux_ProvProd[i].idProveedor)
            {
                aux_ProvProd[i].cantidadProducto++;
            }
        }
    }

    //provMaxvoid(listaProveedor, tProv, listaProducto, tProd);

    //for que recorre los proveedores y busca el maximo
    for(i=0; i<tProv; i++)
    {
        if(i==0 ||  aux_ProvProd[i].cantidadProducto > maxProveedor)
        {
            maxProveedor = aux_ProvProd[i].cantidadProducto;
        }
    }

    //buscarMax(listaProveedor, tProv, listaProducto, tProd)

    //for que muestra la relacion
    for(i=0; i<tProv; i++)
    {
        for(j=0; j<tProv; j++)
        {
            if(listaProveedor[j].idProveedor == aux_ProvProd[i].idProveedor && aux_ProvProd[i].cantidadProducto == maxProveedor)
            {
                printf("\n\t\t------------Proveedor: %s-------------", listaProveedor[j].nombreProveedor);
                printf("\n\tNOMBRE_PROVEEDOR \tCANTIDAD_PRODUCTO\n");
                printf("%24s %24d\n", listaProveedor[j].nombreProveedor, maxProveedor);
            }
        }
    }

    //muestroRelacion(listaProveedor, tProv, listaProducto, tProd);
}

/*
//for que inicializa
void inicializaArray(sProveedor listaProveedor[], int tProv, sProducto listaProducto[], int tProd)
{
    sProd_Prov aux_ProvProd[tProv];//Array aux de la estructura producto_proveedor
    int i;//Proveedores

    for(i=0; i<tProv; i++)
    {
        aux_ProvProd[i].idProveedor = listaProveedor[i].idProveedor;
        aux_ProvProd[i].cantidadProducto = 0;
    }
}

//for que recorre los arrays y asigna el maximo al aux_ProvProd[i].cantidadProducto++;
void provMaxvoid(sProveedor listaProveedor[], int tProv, sProducto listaProducto[], int tProd)
{
    int i;
    int j;
    for(i=0; i<tProv; i++)
    {
        for(j=0; j<tProd; j++)
        {
            if(listaProducto[j].idProveedor == aux_ProvProd[i].idProveedor)
            {
                aux_ProvProd[i].cantidadProducto++;
            }
        }
    }

}

//for que recorre los proveedores y busca el maximo
void buscarMax(sProveedor listaProveedor[], int tProv, sProducto listaProducto[], int tProd)
{
    int i;
    int maxProveedor;//Proveedor
    for(i=0; i<tProv; i++)
    {
        if(i==0 ||  aux_ProvProd[i].cantidadProducto > maxProveedor)
        {
            maxProveedor = aux_ProvProd[i].cantidadProducto;
        }
    }
}

//for que muestra la relacion
void muestroRelacion(sProveedor listaProveedor[], int tProv, sProducto listaProducto[], int tProd)
{
    int i;
    int j;
    int maxProveedor;//Proveedor
    for(i=0; i<tProv; i++)
    {
        for(j=0; j<tProv; j++)
        {
            if(listaProveedor[j].idProveedor == aux_ProvProd[i].idProveedor && aux_ProvProd[i].cantidadProducto == maxProveedor)
            {
                printf("\n\t\t------------Proveedor: %s-------------", listaProveedor[j].nombreProveedor);
                printf("\n\tNOMBRE_PROVEEDOR \tCANTIDAD_PRODUCTO\n");
                printf("%24s %24d\n", listaProveedor[j].nombreProveedor, maxProveedor);
            }
        }
    }
}
*/
