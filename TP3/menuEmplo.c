
#include "menuEmplo.h"

int menu_edit(int* option)
{
    int ret_Value = -1;

    printf("+===================================================+\n");
    printf("|                   EDITAR EMPLEADO                 |\n");
    printf("+===================================================+\n");
    printf("|  1. Editar el Nombre.                             |\n");
    printf("|  2. Editar las Horas Trabajadas.                  |\n");
    printf("|  3. Editar el Salario.                            |\n");
    printf("|  4. Aplicar cambios y volver al menu principal.   |\n");
    printf("+---------------------------------------------------+\n\n");

    *option = validate_option("Ingrese opcion a modificar");
    if(*option > 0){
        ret_Value = 1;
    }
    return ret_Value;
}

int menu_sort(int* option){

    int ret_value = -1;
    printf(" +=================================================+\n");
    printf(" |              ORDERNAR EMPLEADOS                 |\n");
    printf(" +=================================================+\n");
    printf(" |  [1] Ordenar por ID.                            |\n");
    printf(" |  [2] Ordenar por Nombre.                        |\n");
    printf(" |  [3] Volver al menu principal.                  |\n");
    printf(" +-------------------------------------------------+\n\n");

    *option = validate_option("Ingrese una opcion");
    if(*option > 0){
        ret_value = 1;
    }
    return ret_value;
}
int menu_main()
{
    int option;

    printf(" +===================================================================================+\n");
    printf(" |                                NOMINA DE EMPLEADOS                                |\n");
    printf(" +===================================================================================+\n");
    printf(" |  [1] Cargar los datos de los Empleados desde el archivo data.csv (modo texto).    |\n");
    printf(" |  [2] Cargar los datos de los Empleados desde el archivo data.bin (modo binario).  |\n");
    printf(" |  [3] Alta de Empleado.                                                            |\n");
    printf(" |  [4] Modificar datos de Empleado.                                                 |\n");
    printf(" |  [5] Baja de Empleado.                                                            |\n");
    printf(" |  [6] Listar Empleados.                                                            |\n");
    printf(" |  [7] Ordenar Empleados.                                                           |\n");
    printf(" |  [8] Guardar los datos de los Empleados en el archivo data.csv (modo texto).      |\n");
    printf(" |  [9] Guardar los datos de los Empleados en el archivo data.bin (modo binario).    |\n");
    printf(" | [10] Salir del programa                                                           |\n");
    printf(" +-----------------------------------------------------------------------------------+\n\n");
    option = validate_option("Ingrese una opcion");

	return option;
}
