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
/// \return opcion elejida en el menu del main
int ContarCargasRealizadas(sPassenger lista[], int size);

void HarcodearTipoPasajeros(sTypesPassenger tipoPasajero[], int size);

void HarcodearStatusVuelo(sStatusFlight statusPasajero[], int size);

int HarcodearPasajeros(sPassenger lista[], int size);

/// \fn void Resultado(int)
/// \brief funcion para devolver si se pudo realizar la operacion o no
/// \param resultado 1 OK, -1 ERROR
void Resultado(int resultado);

/// \fn void FormatearCadena(char[])
/// \brief le da formato a las cadenas de nombre y apellido, la primer letra en mayuscula y las otras en minuscula
/// \param cadena
void FormatearCadena(char cadena[]);


//ALTA
/// \fn int AgregarPasajeroEnLista(sPassenger[], int)
/// \brief funcion para agregar un psajero
/// \param lista
/// \param size
/// \return si la carga se hizo ok 1, error -1
int AgregarPasajeroEnLista(sPassenger lista[], int size);

/// \fn sPassenger CargarPasajero(int*)
/// \brief carga los datos ingresados en una posicion del array de estructura de pasajeros
/// \param resultado
/// \return retorna los datos de la estructura auxiliar
sPassenger CargarPasajero(int* resultado);

/// \fn int BuscarEspacioLibre(sPassenger[], int)
/// \brief busca un espacio libre en el array de estructuras de pasajeros
/// \param lista
/// \param size
/// \return 1 ok, -1 error
int BuscarEspacioLibre(sPassenger lista[], int size);

//MODIFICACION
/// \fn int ModificarDatosPasajero(sPassenger[], int, int)
/// \brief modifica los datos de un pasajero
/// \param lista
/// \param size
/// \param contadorAltas
/// \return 1 si pudo modificar, -1 error
int ModificarDatosPasajero(sPassenger lista[], int size, int contadorAltas);

void SubmenuModificarDatosPasajeros(sPassenger lista[], int size, int indice);

//BAJA
/// \fn int BajaDePasajero(sPassenger[], int, int)
/// \brief da de baja a un pasajero, poniendo su campo isEmpty en TRUE
/// \param lista
/// \param size
/// \param contadorAltas
/// \return 1 OK, -1 ERROR
int BajaDePasajero(sPassenger lista[], int size, int contadorAltas);

//MOSTRAR
/// \fn int MostrarListado(sPassenger[], int, int, sTypesPassenger[], int, sStatusFlight[], int)
/// \brief submenu para mostrar listado
/// \param listaPasajeros
/// \param sizePasajeros
/// \param contadorAltas
/// \param listaTipo
/// \param sizeTipo
/// \param listaStatus
/// \param sizeStatus
/// \return si pudo mostrar un listado 1, de lo contraro -1 error
int MostrarListado(sPassenger listaPasajeros[], int sizePasajeros, int contadorAltas, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus);
/// \fn void OrdenarDeManeraDecreciente(sPassenger[], int, sTypesPassenger[], int)
/// \brief ordena a los pasajeros de manera decreciente
/// \param list
/// \param size
/// \param listaTipo
/// \param sizeTipo
void OrdenarDeManeraDecreciente(sPassenger list[], int size, sTypesPassenger listaTipo[], int sizeTipo);
/// \fn void OrdenarDeManeraCreciente(sPassenger[], int, sTypesPassenger[], int)
/// \brief ordena a los pasajeros  manera creciente
/// \param list
/// \param size
/// \param listaTipo
/// \param sizeTipo
void OrdenarDeManeraCreciente(sPassenger list[], int size,  sTypesPassenger listaTipo[], int sizeTipo);
/// \fn void ordenarAlfabeticamenteTipoCreciente(sPassenger*, sPassenger*, sTypesPassenger[], int)
/// \brief ordena a los pasajeros por apellido de  manera creciente
/// \param pasajeroUno
/// \param pasajeroDos
/// \param listaTipo
/// \param sizeTipo
void ordenarAlfabeticamenteTipoCreciente(sPassenger* pasajeroUno, sPassenger* pasajeroDos, sTypesPassenger listaTipo[], int sizeTipo);
/// \fn void ordenarAlfabeticamenteTipoDecreciente(sPassenger*, sPassenger*, sTypesPassenger[], int)
/// \brief ordena a los pasajeros por apellido de  manera decreciente
/// \param pasajeroUno
/// \param pasajeroDos
/// \param listaTipo
/// \param sizeTipo
void ordenarAlfabeticamenteTipoDecreciente(sPassenger* pasajeroUno, sPassenger* pasajeroDos, sTypesPassenger listaTipo[], int sizeTipo);
/// \fn void printTipoPasajero(sPassenger, sTypesPassenger[], int, int)
/// \brief imprime del pasajero el tipo de pasajero
/// \param listaPasajero
/// \param listaTipo
/// \param sizeTipo
/// \param anchoColumnaTipoPasajero
void printTipoPasajero(sPassenger listaPasajero, sTypesPassenger listaTipo[], int sizeTipo, int anchoColumnaTipoPasajero);
/// \fn void printEstadoVuelo(sPassenger, sStatusFlight[], int, int)
/// \brief imprime del pasajero el estado de vuelo
/// \param listaPasajero
/// \param listaStatus
/// \param sizeStatus
/// \param anchoColumnaEstadoVuelo
void printEstadoVuelo(sPassenger listaPasajero, sStatusFlight listaStatus[], int sizeStatus, int anchoColumnaEstadoVuelo);
/// \fn int CalcularPrecios(sPassenger[], int, int, sTypesPassenger[], int, sStatusFlight[], int)
/// \brief calcula precio total y promedio de los pasajeros
/// \param list
/// \param size
/// \param contadorAltas
/// \param listaTipo
/// \param sizeTipo
/// \param listaStatus
/// \param sizeStatus
/// \return 1 ok, -1 error
int CalcularPrecios(sPassenger list[], int size, int contadorAltas, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus);
/// \fn int printPassengerMayorAlPromedio(sPassenger[], int, sTypesPassenger[], int, sStatusFlight[], int, float)
/// \brief imprime a los pasajeros con precios mayores al promedio del total
/// \param listaPasajero
/// \param len
/// \param listaTipo
/// \param sizeTipo
/// \param listaStatus
/// \param sizeStatus
/// \param promedioPrecio
/// \return
int printPassengerMayorAlPromedio(sPassenger listaPasajero[], int len, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus, float promedioPrecio);
/// \fn int printPassengerEstadoVueloYCodigoActivo(sPassenger[], int, sTypesPassenger[], int, sStatusFlight[], int)
/// \brief imprime a los pasajeros con el codigo de vuelo y estado activo
/// \param listaPasajero
/// \param len
/// \param listaTipo
/// \param sizeTipo
/// \param listaStatus
/// \param sizeStatus
/// \return
int printPassengerEstadoVueloYCodigoActivo(sPassenger listaPasajero[], int len, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus);

//ARRAYPASSENGER.C
/// \fn int initPassengers(sPassenger[], int)
/// \brief inicializa al array de pasajeros en isEmpty == TRUE
/// \param list
/// \param len
/// \return 1 OK, -1 ERROR
int initPassengers(sPassenger list[], int len);
/// \fn int addPassenger(sPassenger[], int, int, char[], char[], float, int, char[], int, int)
/// \brief agrega lso datos de una estructura auxiliar a la estructura con espacio disponible
/// \param list
/// \param len
/// \param id
/// \param name
/// \param lastName
/// \param price
/// \param typePassenger
/// \param flycode
/// \param statusFlight
/// \param isEmpty
/// \return 1 ok , -1 error
int addPassenger(sPassenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight, int isEmpty);
/// \fn int findPassengerById(sPassenger[], int, int)
/// \brief busca al pasajero con estado activo por id
/// \param list
/// \param len
/// \param id
/// \return 1 ok, -1 error
int findPassengerById(sPassenger list[], int len,int id);
/// \fn int removePassenger(sPassenger[], int, int)
/// \brief borra al pasajero de la listas poniendo su campo isEmpty == TRUE
/// \param list
/// \param len
/// \param id
/// \return 1 OK, -1 ERROR
int removePassenger(sPassenger list[], int len, int id);
/// \fn int sortPassengers(sPassenger[], int, sTypesPassenger[], int, int, sStatusFlight[], int)
/// \brief ordena la lista de pasajeros segun el criterio
/// \param listaPasajeros
/// \param sizePasajeros
/// \param listaTipo
/// \param sizeTipo
/// \param order
/// \param listaStatus
/// \param sizeStatus
/// \return 1 ok, -1 error
int sortPassengers(sPassenger listaPasajeros[], int sizePasajeros, sTypesPassenger listaTipo[], int sizeTipo, int order, sStatusFlight listaStatus[], int sizeStatus);
/// \fn int printPassenger(sPassenger[], int, sTypesPassenger[], int, sStatusFlight[], int)
/// \brief imprime la lista de psajeros
/// \param listaPasajero
/// \param len
/// \param listaTipo
/// \param sizeTipo
/// \param listaStatus
/// \param sizeStatus
/// \return 1 ok, -1 error
int printPassenger(sPassenger listaPasajero[], int len, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus);


//INPUTS
///comentados en su carpeta inputs.c
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

int utn_getNumeroConDecimales(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
