#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 2000
#define TRUE 1
#define FALSE 0

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
	int statusFlight;
}sPassenger;

typedef struct{
	int typePassenger;
	char description[15];
}sTypesPassenger;

typedef struct{
	int statusFlight;
	char description[15];
}sStatusFlight;

int LlamarMenu();

/// \fn int ContarCargasRealizadas(sPassenger[], int)
/// \brief cuenta la cantidad de cargas realizadas para validar
/// \param lista
/// \param size
/// \return
int ContarCargasRealizadas(sPassenger lista[], int size);

void HarcodearTipoPasajeros(sTypesPassenger tipoPasajero[], int size);

void HarcodearStatusVuelo(sStatusFlight statusPasajero[], int size);

int HarcodearPasajeros(sPassenger lista[], int size);

void Resultado(int resultado);

void FormatearCadena(char cadena[]);


//ALTA

int AgregarPasajeroEnLista(sPassenger lista[], int size);

sPassenger CargarPasajero(int* resultado);

int BuscarEspacioLibre(sPassenger lista[], int size);

//MODIFICACION
int ModificarDatosPasajero(sPassenger lista[], int size, int contadorAltas);

void SubmenuModificarDatosPasajeros(sPassenger lista[], int size, int indice);

//BAJA
int BajaDePasajero(sPassenger lista[], int size, int contadorAltas);

//MOSTRAR
int MostrarListado(sPassenger listaPasajeros[], int sizePasajeros, int contadorAltas, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus);

void OrdenarDeManeraDecreciente(sPassenger list[], int size, sTypesPassenger listaTipo[], int sizeTipo);

void OrdenarDeManeraCreciente(sPassenger list[], int size,  sTypesPassenger listaTipo[], int sizeTipo);

void ordenarAlfabeticamenteTipoCreciente(sPassenger* pasajeroUno, sPassenger* pasajeroDos, sTypesPassenger listaTipo[], int sizeTipo);

void ordenarAlfabeticamenteTipoDecreciente(sPassenger* pasajeroUno, sPassenger* pasajeroDos, sTypesPassenger listaTipo[], int sizeTipo);

void printTipoPasajero(sPassenger listaPasajero, sTypesPassenger listaTipo[], int sizeTipo, int anchoColumnaTipoPasajero);

void printEstadoVuelo(sPassenger listaPasajero, sStatusFlight listaStatus[], int sizeStatus, int anchoColumnaEstadoVuelo);

int CalcularPrecios(sPassenger list[], int size, int contadorAltas, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus);

int printPassengerMayorAlPromedio(sPassenger listaPasajero[], int len, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus, float promedioPrecio);

int printPassengerVueloYCodigoActivo(sPassenger listaPasajero[], int len, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus);

//ARRAYPASSENGER.C
int initPassengers(sPassenger list[], int len);

int addPassenger(sPassenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight, int isEmpty);

int findPassengerById(sPassenger list[], int len,int id);

int removePassenger(sPassenger list[], int len, int id);

int sortPassengers(sPassenger listaPasajeros[], int sizePasajeros, sTypesPassenger listaTipo[], int sizeTipo, int order, sStatusFlight listaStatus[], int sizeStatus);

int printPassenger(sPassenger listaPasajero[], int len, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus);


//INPUTS
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getNumeroConDecimales(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
