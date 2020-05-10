
#define MIN_MENU 0
#define MAX_MENU 12
#define INTE_MENU 2

//Menu
void menuApp(void);


int getInt(char mensaje[], char mensajeError[], int Min, int Max, int Intentos);
int validacionGetInt(int valor, char mensajeError[], int Min, int Max, int Intentos);
