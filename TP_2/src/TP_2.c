/*
 ============================================================================
 Name        : TP_2.c
 Author      : Montaño Heredia Lautaro Nahuel DIV C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "TP_2.h"


int main(void) {
	setbuf(stdout,NULL);
	sPassenger pasajeros[TAM];
	sTypesPassenger typePassenger[4];
	sStatusFlight statusFlight[4];
	int opcion;
	int contadorPasajerosActivos;
	int retorno;
	int retornoAlta;
	int retornoModificar;
	int retornoBaja;
	int retornoMostrar;

	contadorPasajerosActivos = 0;

	HarcodearTipoPasajeros(typePassenger, 4);
	HarcodearStatusVuelo(statusFlight, 4);
	retorno = initPassengers(pasajeros, TAM);
	if(retorno == -1){
		printf("\nError al iniciar el programa, Contactese con el soporte tecnico\n");
	}

	do{
		contadorPasajerosActivos = ContarCargasRealizadas(pasajeros, TAM);
		opcion = LlamarMenu();

		switch(opcion){
		case 1:
			retornoAlta = AgregarPasajeroEnLista(pasajeros, TAM);
			Resultado(retornoAlta);
			break;
		case 2:
			retornoModificar = ModificarDatosPasajero(pasajeros, TAM, contadorPasajerosActivos);
			Resultado(retornoModificar);
			break;
		case 3:
			retornoBaja = BajaDePasajero(pasajeros, TAM, contadorPasajerosActivos);
			Resultado(retornoBaja);
			break;
		case 4:
			retornoMostrar = MostrarListado(pasajeros, TAM, contadorPasajerosActivos, typePassenger, 4, statusFlight, 4);
			Resultado(retornoMostrar);
			break;
		case 5:
			Resultado(HarcodearPasajeros(pasajeros, 6));
			break;
		case 9:
			printf("Gracias por usar nuestra app!.");
			break;
		default:
			printf("La opcion ingresada es invalida.\n");
			break;
		}

	}while(opcion != 9);
	return 0;
}

