#include "TP_2.h"

static int idIncremental = 100;
static int GenerarID();
static int GenerarID(){
	return idIncremental++;
}

int LlamarMenu(){
	int opcion;

	printf("\n\n--MENU PRINCIPAL--\n");
	printf("1. ALTAS\n");
	printf("2. MODIFICAR\n");
	printf("3. BAJA\n");
	printf("4. INFORMAR\n");
	printf("5. CARGA FORZADA\n");
	printf("9. SALIR\n");
	utn_getNumero(&opcion,"\nElija una opcion: \n","el numero ingresado es invalido, intentelo nuevamente \n", 1, 9, 10);


	return opcion;
}

void Resultado(int resultado){
	switch(resultado){
		case -1:
			printf("Error en la operacion\n");
			break;
		default:
			printf("\nLa operacion fue exitosa\n");
			break;
	}
}
int ContarCargasRealizadas(sPassenger lista[], int size){
	int contador;
	contador = 0;
	for(int i=0; i<size; i++){
		if(lista[i].isEmpty == FALSE){
			contador++;
		}
	}
	return contador;
}

void HarcodearTipoPasajeros(sTypesPassenger tipoPasajero[], int size){
	int tipo[4] = {0, 1, 2, 3};
	char descripcion[4][15] = {"VACIO","Turist","Business","First class"};

	for(int i=0; i<size; i++){
		tipoPasajero[i].typePassenger = tipo[i];
		strcpy(tipoPasajero[i].description, descripcion[i]);
	}
}

void HarcodearStatusVuelo(sStatusFlight statusPasajero[], int size){
	int status[4] = {0, 1, 2, 3};
	char descripcion[4][15] = {"VACIO", "ACTIVO", "CANCELADO", "DEMORADO"};

	for(int i=0; i<size; i++){
		statusPasajero[i].statusFlight = status[i];
		strcpy(statusPasajero[i].description, descripcion[i]);
	}
}

int HarcodearPasajeros(sPassenger lista[], int size){
	int resultado;
	resultado = -1;

	char nombre[6][51] = {"Juan", "Armando", "Pedro", "Luis", "Pepe", "Fernando"};
	char apellido[6][51] = {"Perez", "Perez", "Gonzalez", "Gonzalez", "Zeta", "Abcd"};
	float precio[6] = {100,200,300,200,300,100};
	char flyCode[6][10] = {"INACTIVO", "BRC", "ARG", "CHI", "ENG", "POR"};
	int typePassanger[6] = {1,2,3,2,2,3};
	int statusFlight[6] = {1,2,3,2,2,3};



	if(lista != NULL && size >= 0){
		for(int i=0; i<size; i++){
			lista[i].id = GenerarID();
			lista[i].isEmpty = FALSE;
			strcpy(lista[i].name, nombre[i]);
			strcpy(lista[i].lastName, apellido[i]);
			lista[i].price = precio[i];
			strcpy(lista[i].flycode, flyCode[i]);
			lista[i].typePassenger = typePassanger[i];
			lista[i].statusFlight = statusFlight[i];
		}
		resultado = 1;
	}
	return resultado;
}

//ALTA

int AgregarPasajeroEnLista(sPassenger lista[], int size){
	int resultado;
	sPassenger auxiliar;

	resultado = -1;


	printf("--MENU ALTA DE PASAJERO--\n");

	if((lista != NULL) && (size >= 0)){
		auxiliar = CargarPasajero(&resultado);
		if(resultado != -1){
			resultado = addPassenger(lista, size, auxiliar.id, auxiliar.name, auxiliar.lastName, auxiliar.price, auxiliar.typePassenger, auxiliar.flycode, auxiliar.statusFlight, auxiliar.isEmpty);
		}
	}
	return resultado;
}

int BuscarEspacioLibre(sPassenger lista[], int size){
	int indice;

	indice = -1;

	for(int i=0; i<size; i++){
		if(lista[i].isEmpty == TRUE){
			indice = i;
			break;
		}
	}
	return indice;
}

sPassenger CargarPasajero(int* resultado){
	sPassenger auxiliar;
	auxiliar.id = GenerarID();
	auxiliar.isEmpty = FALSE;
	strcpy(auxiliar.flycode, "INACTIVO");

	printf("\nIngrese el nombre del pasajero: \n");
	fflush(stdin);
	gets(auxiliar.name);
	FormatearCadena(auxiliar.name);
	printf("Ingrese el apellido: \n");
	fflush(stdin);
	gets(auxiliar.lastName);
	FormatearCadena(auxiliar.lastName);
	printf("Ingrese el precio del vuelo: \n");
	scanf("%f", &auxiliar.price);

	printf("Ingrese codigo de vuelo: \n");
	fflush(stdin);
	gets(auxiliar.flycode);
	do{
		*resultado = utn_getNumero(&auxiliar.typePassenger,"\nSeleccione el tipo de pasajero (1. Turist, 2. Business, 3.First class): \n","el numero ingresado es invalido, intentelo nuevamente \n", 1, 3, 3);
		if(*resultado == -1){
			printf("Supero el limite de intentos. \n");
			break;
		}
		*resultado = utn_getNumero(&auxiliar.statusFlight,"Seleccione el estado del vuelo (1. ACTIVO, 2. CANCELADO, 3.DEMORADO): \n","el numero ingresado es invalido, intentelo nuevamente \n", 1, 3, 3);
		if(*resultado == -1){
			printf("Supero el limite de intentos. \n");
			break;
		}
	}while(*resultado != 1);
	 return auxiliar;
}

//MODIFICAR
int ModificarDatosPasajero(sPassenger lista[], int size, int contadorPasajerosActivos){
	int resultado;
	int id;
	int indice;
	resultado = -1;

	printf("--MENU MODIFICAR DATOS DEL PASAJERO--\n");
	if((lista != NULL) && (contadorPasajerosActivos >= 1)){
		resultado = utn_getNumero(&id, "\nIngrese el id a modificar: \n","el numero ingresado es invalido, intentelo nuevamente \n", 100, 2000, 5);
		indice = findPassengerById(lista, size, id);
		if((resultado != -1) && (indice != -1)){
			SubmenuModificarDatosPasajeros(lista, size, indice);
		}
	}
	else{
		printf("Todavia no se ingresaron pasajeros: \n");
	}


	return resultado;
}
void SubmenuModificarDatosPasajeros(sPassenger lista[], int size, int indice){
	int opcion;
	do{
		printf("1. Modificar el nombre\n");
		printf("2. Modificar el apellido\n");
		printf("3. Modificar el precio\n");
		printf("4. Modificar el tipo de pasajero\n");
		printf("5. Modificar el codigo de vuelo\n");
		printf("9. SALIR\n");
		utn_getNumero(&opcion,"\nElija una opcion: \n","el numero ingresado es invalido, intentelo nuevamente \n", 1, 9, 10);
		switch(opcion){
		case 1:
			printf("Ingrese el nombre: \n");
			fflush(stdin);
			gets(lista[indice].name);
			break;
		case 2:
			printf("Ingrese el apellido: \n");
			fflush(stdin);
			gets(lista[indice].lastName);
			break;
		case 3:
			printf("Ingrese el precio: \n");
			scanf("%f", &lista[indice].price);
			break;
		case 4:
			Resultado(utn_getNumero(&lista[indice].typePassenger,"Seleccione el tipo de pasajero (1. Turist, 2. Business, 3.First class): \n","el numero ingresado es invalido, intentelo nuevamente \n", 1, 3, 5));
			break;
		case 5:
			printf("Ingrese el codigo de vuelo: \n");
			fflush(stdin);
			gets(lista[indice].flycode);
			break;
		case 9:
			printf("Esta volviendo al menu principal: \n");
			break;
		default:
			printf("Ingrese una opcion valida: \n");
			break;
		}
	}while(opcion != 9);
}
//BAJA
int BajaDePasajero(sPassenger lista[], int size, int contadorAltas){
	int resultado;
	int id;
	resultado = -1;
	printf("--MENU BAJA DE PASAJERO--\n");
	if((lista != NULL) && (contadorAltas >= 1)){
		resultado = utn_getNumero(&id, "Ingrese el id a modificar: \n","el numero ingresado es invalido, intentelo nuevamente \n", 100, 2000, 5);
		if((resultado != -1)){
			resultado = removePassenger(lista, size, id);
		}
	}
	else{
		printf("Todavia no se ingresaron pasajeros: \n");
	}
	return resultado;
}

//MOSTRAR
int MostrarListado(sPassenger listaPasajeros[], int sizePasajeros, int contadorAltas, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus){
	int resultado;
	int opcion;
	int opcionOrdenamiento;
	resultado = -1;
	if((listaPasajeros != NULL) && (listaTipo != NULL) && (listaStatus != NULL) && (contadorAltas >= 1)){
		printf("--MENU MOSTRAR--\n");
		printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero. \n");
		printf("2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
		printf("3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.  \n");
		printf("9. SALIR\n");
		do{
			resultado = utn_getNumero(&opcion, "Elija una opcion: \n","el numero ingresado es invalido, intentelo nuevamente \n", 1, 9, 10);
			switch(opcion){
			case 1:
				resultado = utn_getNumero(&opcionOrdenamiento, "Ingrese 1 para ordenar de manera creciente o 2 para ordenar de manera decreciente: \n","el numero ingresado es invalido, intentelo nuevamente \n", 1, 2, 5);
				switch(opcionOrdenamiento){
				case 1:
					printf("ordenado alfabeticamente de forma creciente: \n");
					Resultado(sortPassengers(listaPasajeros, sizePasajeros, listaTipo, sizeTipo, 1, listaStatus, sizeStatus));
					break;
				case 2:
					printf("ordenado alfabeticamente de forma decreciente: \n");
					Resultado(sortPassengers(listaPasajeros, sizePasajeros, listaTipo, sizeTipo, 0, listaStatus, sizeStatus));
					break;
				}
				break;
			case 2:
				resultado = CalcularPrecios(listaPasajeros, sizePasajeros, contadorAltas, listaTipo, sizeTipo, listaStatus, sizeStatus);
				if(resultado != 1){
					printf("No se encontraron pasajeros que cumplan estas condiciones. \n");
				}
				break;
			case 3:
				resultado = printPassengerVueloYCodigoActivo(listaPasajeros, sizePasajeros, listaTipo, sizeTipo, listaStatus, sizeStatus);
				if(resultado != 1){
					printf("No se encontraron pasajeros que cumplan estas condiciones. \n");
				}
				break;
			case 9:
				printf("Volviendo al menu principal\n");
				break;
			default:
				printf("La opcion ingresada es invalida. \n");
				break;
			}
		}while(opcion != 9);
	}
	else{
		printf("Todavia no se ingresaron pasajeros: \n");
	}

	return resultado;
}

void OrdenarDeManeraCreciente(sPassenger list[], int size,  sTypesPassenger listaTipo[], int sizeTipo){
	int i;
	int j;
	sPassenger auxiliar;
	for(i=0; i<size-1; i++){
		for(j=i+1; j<size; j++){
			if((strcmp(list[i].lastName, list[j].lastName)) > 0 ){
				auxiliar = list[i];
				list[i] = list[j];
				list[j] = auxiliar;
			}
			if(strcmp(list[i].lastName, list[j].lastName) == 0){
				if(list[i].typePassenger > list[j].typePassenger){
					ordenarAlfabeticamenteTipoCreciente(&list[i], &list[j], listaTipo, sizeTipo);
				}
			}
		}
	}
}

void OrdenarDeManeraDecreciente(sPassenger list[], int size,  sTypesPassenger listaTipo[], int sizeTipo){

	int i;
	int j;
	sPassenger auxiliar;
	for(i=0; i<size-1; i++){
		for(j=i+1; j<size; j++){
			if((strcmp(list[i].lastName, list[j].lastName)) < 0 ){
				auxiliar = list[i];
				list[i] = list[j];
				list[j] = auxiliar;
			}
			if(strcmp(list[i].lastName, list[j].lastName) == 0){
				ordenarAlfabeticamenteTipoDecreciente(&list[i], &list[j], listaTipo, sizeTipo);
			}
		}
	}
}

void FormatearCadena(char cadena[]){
	int contadorCaracteres;
	int i;
	strlwr(cadena);
	contadorCaracteres = strlen(cadena);
	for(i=0; i<contadorCaracteres;i++){
		if(cadena[i-1]==32 || i==0){
			cadena[i] = toupper(cadena[i]);
		}
	}
}

void ordenarAlfabeticamenteTipoCreciente(sPassenger* pasajeroUno, sPassenger* pasajeroDos, sTypesPassenger listaTipo[], int sizeTipo){
	sPassenger auxiliar;

	for(int i=0; i<sizeTipo; i++){
		if(pasajeroUno->typePassenger == listaTipo[i].typePassenger){
			for(int j=0; j<sizeTipo; j++){
				if(pasajeroDos->typePassenger == listaTipo[j].typePassenger){
					if(strcmp(listaTipo[i].description,listaTipo[j].description) > 0){
						auxiliar = *pasajeroUno;
						*pasajeroUno = *pasajeroDos;
						*pasajeroDos = auxiliar;
					}
				}
			}
		}
	}
}

void ordenarAlfabeticamenteTipoDecreciente(sPassenger* pasajeroUno, sPassenger* pasajeroDos, sTypesPassenger listaTipo[], int sizeTipo){
	sPassenger auxiliar;

	for(int i=0; i<sizeTipo; i++){
		if(pasajeroUno->typePassenger == listaTipo[i].typePassenger){
			for(int j=0; j<sizeTipo; j++){
				if(pasajeroDos->typePassenger == listaTipo[j].typePassenger){
					if(strcmp(listaTipo[i].description,listaTipo[j].description) < 0){
						auxiliar = *pasajeroUno;
						*pasajeroUno = *pasajeroDos;
						*pasajeroDos = auxiliar;
					}
				}
			}
		}
	}
}

int CalcularPrecios(sPassenger list[], int size, int contadorAltas, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus){
	int resultado;
	float acumuladorPrecio;
	float promedioPrecio;
	acumuladorPrecio = 0;

	resultado = -1;

	for(int i=0; i<size; i++){
		if(list[i].isEmpty == FALSE){
			acumuladorPrecio += list[i].price;
			resultado = 1;
		}
	}
	promedioPrecio = acumuladorPrecio / contadorAltas;

	printf("PRECIO TOTAL PASAJES: $%.2f\n", acumuladorPrecio);
	printf("PROMEDIO DE LOS PRECIOS DE LOS PASAJES: %.2f\n", promedioPrecio);
	printf("PASAJES CON PRECIOS MAYORES AL PROMEDIO TOTAL \n");
	printPassengerMayorAlPromedio(list, size, listaTipo, sizeTipo, listaStatus, sizeStatus, promedioPrecio);

	return resultado;
}

int printPassengerMayorAlPromedio(sPassenger listaPasajero[], int len, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus, float promedioPrecio){
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
			if((listaPasajero[i].isEmpty == FALSE) && (listaPasajero[i].price > promedioPrecio)){
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

int printPassengerVueloYCodigoActivo(sPassenger listaPasajero[], int len, sTypesPassenger listaTipo[], int sizeTipo, sStatusFlight listaStatus[], int sizeStatus){
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
			if((listaPasajero[i].isEmpty == FALSE) && (listaPasajero[i].statusFlight == 1) && (strcmp(listaPasajero[i].flycode, "VACIO") != 0)){
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
