
#define PROV 4
//estado
#define OCUPADO 1
#define LIBRE -1
//para el id
#define MIN_IDPROVEEDOR 100
#define MAX_IDPROVEEDOR 300
#define INTEN_IDPROVEEDOR 2

typedef struct proveedor{
    int idProveedor;
    char nombreProveedor[50];
    char localidad[50];

    int estadoProveedor;
}sProveedor;

//Funcion de inicio
void harcodeoProveedor(sProveedor[], int);
void inicializarProvedor(sProveedor listaProveedor[], int tProv);
//Funciones para cargar un producto
int buscarLibreProveedor(sProveedor listaProveedor[], int tProv);
void cargarListaProveedor(sProveedor listaProveedor[], int tProv);
sProveedor cargarUnProveedor(void);
//Funciones para mostrar
void mostrarTodosLosProveedores(sProveedor[], int);
void mostrarUnProveedor (sProveedor);
//Funcion para eliminar un proveedor
void eliminarProveedor(sProveedor listaProveedor[], int tProv);

void ModificarProvedor(sProveedor listaProveedor[], int tProv);
