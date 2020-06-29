
#ifndef __VUELOS
#define __VUELOS
typedef struct {

    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[25];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

}eVuelo;

eVuelo* vuelo_new(void);
eVuelo* vuelo_newParametros(int* p_idVuelo, int* p_idAvion ,int* p_idPiloto, char* p_fecha,
                             char* p_Destino, int* p_cantpsj,int* p_horaDpg, int* p_horaLlegd);

int vuelo_setIdVuelo(eVuelo* unVuelo ,int p_idVuelo);
int vuelo_getIdVuelo(eVuelo* unVuelo ,int* p_idVuelo);

int vuelo_setIdAvion(eVuelo* unVuelo ,int p_idAvion);
int vuelo_getIdAvion(eVuelo* unVuelo ,int* p_idAvion);

int vuelo_setIdPiloto(eVuelo* unVuelo ,int p_idPiloto);

int vuelo_getIdPiloto(eVuelo* unVuelo ,int* p_idPiloto);

int vuelo_setFecha(eVuelo* unVuelo, char* p_fecha);
int vuelo_getFecha(eVuelo* unVuelo,char* p_fecha);

int vuelo_setDestino(eVuelo* unVuelo, char* p_Destino);

int vuelo_getDestino(eVuelo* unVuelo, char* p_Destino);
int vuelo_setCantpsj(eVuelo* unVuelo, int p_cantpsj);
int vuelo_getCantpsj(eVuelo* unVuelo, int* p_cantpsj);

int vuelo_setHoradespegue(eVuelo* unVuelo,int p_horaDpg);
int vuelo_getHoradespegue(eVuelo* unVuelo,int* p_horaDpg);

int vuelo_setHorallegada(eVuelo* unVuelo, int p_horaLlegd);
int vuelo_getHorallegada(eVuelo* unVuelo, int* p_horaLlegd);

int contarpasajeros(void* element);
int contarpasajerosIrlanda(void* element);
int filtrarVueloCorto(void* element);
int filtrarVueloPortugal(void* element);
int filtrarVuelomenosAlex(void* element);


#endif // __VUELOS
