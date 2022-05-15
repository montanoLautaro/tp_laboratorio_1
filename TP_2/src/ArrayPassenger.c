#include "TP_2.h"

int initPassengers(sPassenger list[], int len){
	int resultado;
	resultado = -1;

	if(list != NULL){
		if(len >= 0){
			for(int i=0; i<len; i++){
				list[i].isEmpty = TRUE;
			}
			resultado = 1;
		}
	}
	return resultado;
}

int addPassenger(sPassenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight, int isEmpty){
	int resultado;
	int indiceLibre;
	resultado = -1;

	indiceLibre = BuscarEspacioLibre(list, len);
	if(indiceLibre != -1){
		list[indiceLibre].id = id;
		strcpy(list[indiceLibre].name, name);
		strcpy(list[indiceLibre].lastName, lastName);
		list[indiceLibre].price = price;
		list[indiceLibre].typePassenger = typePassenger;
		strcpy(list[indiceLibre].flycode, flycode);
		list[indiceLibre].statusFlight = statusFlight;
		list[indiceLibre].isEmpty = isEmpty;

		resultado = 1;
	}

	if(indiceLibre == -1){
		printf("Se excedio el maximo de vuelos a cargar. \n");
	}
	return resultado;
}

int findPassengerById(sPassenger list[], int len,int id)
{
	int indice;
	indice = -1;

	for(int i=0; i<len; i++){
		if((list[i].isEmpty == FALSE) && (list[i].id == id)){
			indice = i;
		}
	}
	if(indice == -1){
		printf("No se encontro el id ingresado: \n");
	}
	return indice;
}
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(sPassenger list[], int len, int id){
	int resultado;
	int indice;
	resultado = -1;
	indice = findPassengerById(list, len, id);
	if(indice != -1){
		list[indice].isEmpty = TRUE;
		resultado = 1;
	}

	return resultado;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(sPassenger listaPasajeros[], int sizePasajeros, sTypesPassenger listaTipo[], int sizeTipo, int order, sStatusFlight listaStatus[], int sizeStatus){
	int resultado;
	resultado = -1;

	if(order == 1){
		OrdenarDeManeraCreciente(listaPasajeros, sizePasajeros, listaTipo, sizeTipo);
		resultado = printPassenger(listaPasajeros, sizePasajeros, listaTipo, sizeTipo, listaStatus, sizeStatus);
	}
	if(order == 0){
		OrdenarDeManeraDecreciente(listaPasajeros, sizePasajeros, listaTipo, sizeTipo);
		resultado = printPassenger(listaPasajeros, sizePasajeros, listaTipo, sizeTipo, listaStatus, sizeStatus);
	}
	return resultado;
}
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(sPassenger listaPasajero[], int len, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus){
	int resultado;
	resultado = -1;
	int anchoColumnaNombres = -20;
	int anchoColumnaApellidos = -20;
	int anchoColumnaTipoPasajero = -20;
	int anchoColumnaPrecio = -15;
	int anchoColumnaEstadoVuelo = -15;
	int anchoColumnaID = -6;
	int anchoColumnaCodigoVuelo = -20;

	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|  %*s|  %*s|  %*s|  %*s|  %*s|  %*s|  %*s|\n",anchoColumnaID, "ID", anchoColumnaApellidos," APELLIDOS",anchoColumnaNombres, " NOMBRES", anchoColumnaPrecio," PRECIO", anchoColumnaCodigoVuelo, "CODIGO DE VUELO", anchoColumnaTipoPasajero, "TIPO DE PASAJERO", anchoColumnaEstadoVuelo, "ESTADO DE VUELO");
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	if((listaPasajero != NULL) && (len >= 0)){
		for(int i=0; i<len; i++){
			if(listaPasajero[i].isEmpty == FALSE){
				printf("|  %*d|  %*s|  %*s|  %*.2f|  %*s|",anchoColumnaID, listaPasajero[i].id, anchoColumnaApellidos, listaPasajero[i].lastName, anchoColumnaNombres, listaPasajero[i].name, anchoColumnaPrecio, listaPasajero[i].price, anchoColumnaCodigoVuelo, listaPasajero[i].flycode);
				printTipoPasajero(listaPasajero[i], listaTipo, sizeTipo, anchoColumnaTipoPasajero);
				printEstadoVuelo(listaPasajero[i], listaStatus, sizeStatus, anchoColumnaEstadoVuelo);
				resultado = 1;
			}
		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	return resultado;
}




void printTipoPasajero(sPassenger listaPasajero, sTypesPassenger listaTipo[], int sizeTipo, int anchoColumnaTipoPasajero){
	for(int j=0; j<sizeTipo; j++){
		if(listaPasajero.typePassenger == listaTipo[j].typePassenger){
			printf("  %*s|", anchoColumnaTipoPasajero, listaTipo[j].description);
		}
	}
}

void printEstadoVuelo(sPassenger listaPasajero, sStatusFlight listaStatus[], int sizeStatus, int anchoColumnaEstadoVuelo){
	for(int j=0; j<sizeStatus; j++){
		if(listaPasajero.statusFlight == listaStatus[j].statusFlight){
			printf("  %*s|\n", anchoColumnaEstadoVuelo, listaStatus[j].description);
		}
	}
}
