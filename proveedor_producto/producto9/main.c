/******************************************************************************

estructuras:
producto: id , nombre , precio , stock
proveedor:id , nombre , localidad

Cada producto puede tener un solo proveedor
Cada proveedor puede tener muchos productos

crear 4 proveedores
crear 10 productos
con la siguiente distribución

proveedor 1: dos productos
proveedor 2: tres productos
proveedor 3: cinco productos
proveedor 4 : sin productos


1- mostrar todos los proveedores, con sus productos o informar si no tiene ningún producto.
2- mostrar el proveedor que tiene más productos. (Respuesta: proveedor 3: cinco productos).
3- dar de alta un producto.<---
4- dar de baja un producto
5- dar de baja un proveedor y todos los productos de ese proveedor(borrado en cascada)

Nota:
1. Alta de Producto.
2. Modificación de Producto.
3. Baja Proveedor en cascada.


Listados
a- mostrar todos los proveedores, con sus productos o informar si no tiene ningún producto.
b- mostrar el proveedor que tiene más productos
*******************************************************************************/
#include <stdio.h>
//#include "producto.h"
//#include "proveedor.h"
#include "producto_proveedor.h"
#include "func_Control.h"



int main()
{
    //Array de las estructuras
    sProducto listaProducto[PROD];
    sProveedor listaProveedor[PROV];

    //Harcodeo de datos en una funcion
    harcodeoProducto(listaProducto, PROD); //, listaProveedor, PROV
    harcodeoProveedor(listaProveedor, PROV);

    //Alta de producto
    //inicializarProductos(listaProducto, PROD);//Nota: importante si quiero inicializar el array debo comentar el harcodeo


    int opcionMenu;

	do{

	    menuApp(); //Menu.
		opcionMenu = getInt("\nIngrese una opcion: ",
							        "\nError Ingrese una opcion: \n", MIN_MENU, MAX_MENU, INTE_MENU); //Opcion del menu

		switch(opcionMenu){
			case 1:
				printf("\n--------CARGANDO UN PRODUCTO-------------\n");
                cargarListadoDeProducto(listaProducto, PROD);
                cargarListaProveedor(listaProveedor, PROV);
			case 2:
				//Muestro los datos harcodeados
                printf("\n--------LOS PRODUCTOS-------------\n");
                printf("\n\tID\t\t NOMBRE\t\tPRECIO\t\tSTOCK\n");
                mostrarTodosLosProducto(listaProducto, PROD);
			break;
			case 3:
				printf("\n--------LOS PROVEEDORES-------------\n");
                printf("\n\tID\t\tNOMBRE\t\tLOCALIDAD\n");
                mostrarTodosLosProveedores(listaProveedor, PROV);
			break;
			case 4:
				printf("\n--------LOS PROVEEDORES CON SUS PRODUCTOS-------------\n");
                mostrarProveedorConProducto(listaProveedor, PROV, listaProducto, PROD);
			break;
			case 5:
				printf("\n--------EL PROVEEDORES CON MAS PRODUCTOS-------------\n");
                mostrarProveedorConMasProducto(listaProveedor, PROV, listaProducto, PROD);
			break;
			case 6:
				printf("\n--------MODIFICAR UN PRODUCTO-------------\n");
                Modificarunproduct(listaProducto,PROD);
			break;
			case 7:
			     printf("\n--------MODIFICAR UN PROVEEDOR-------------\n");
                ModificarProvedor(listaProveedor,PROV);
            break;
			case 8:
				printf("\n--------ELIMINAR UN PRODUCTO POR ID-------------\n");
				mostrarTodosLosProducto(listaProducto, PROD);
                eliminarProducto(listaProducto, PROD);
			break;
			case 9:
				printf("\n--------ELIMINAR UN PROVEDOR POR ID-------------\n");
				mostrarTodosLosProveedores(listaProveedor, PROV);
                eliminarProveedor(listaProveedor, PROV);
			break;
			case 12:
				printf("\nGRACIAS. PROGRAMA TERMINADO.\n");
			break;
			default:
			    printf("\nOPCION NO VALIDA... CASOS NO AGREGADOS\n");
			break;
		}

	}while(opcionMenu != 12);

    return 0;
}
