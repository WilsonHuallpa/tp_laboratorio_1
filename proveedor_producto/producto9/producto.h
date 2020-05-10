#define PROD 10
//estado
#define OCUPADO 1
#define LIBRE -1
//para el id
#define MIN_IDPRODUCTO 1
#define MAX_IDPRODUCTO 200
#define INTEN_IDPRODUCTO 2
//para el precio
#define MIN_PRECIO 0
#define MAX_PRECIO 999999
#define INTEN_PRECIO 2
//para el stock
#define MIN_STOCK -1
#define MAX_STOCK 999999
#define INTEN_STOCK 2



typedef struct producto {
    int idProducto;
    char nombreProducto[50];
    float precio;
    int stock;

    int idProveedor;//FK

    int estadoProducto;
}sProducto;

//Funcion de inicio
void harcodeoProducto(sProducto[], int);
//void harcodeoProducto(sProducto listaProducto[], int tProd, sProveedor listaProveedor[], int tProv);
void inicializarProductos(sProducto[], int);
//Funciones para cargar un producto
int buscarLibreProducto(sProducto listaProducto[], int tProd);
void cargarListadoDeProducto(sProducto listaProducto[], int tProd);
sProducto cargarUnProducto(void);
//Funciones para mostrar
void mostrarTodosLosProducto(sProducto[], int);
void mostrarUnProducto (sProducto);
//Funcion para eliminar un producto
void eliminarProducto(sProducto listaProducto[], int tProd);
void Modificarunproduct(sProducto listaProdicto[], int tProd);
