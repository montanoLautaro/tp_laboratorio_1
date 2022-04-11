/*
 ============================================================================
 Name        : TP_1.c
 Author      : Monta�o Heredia Lautaro Nahuel DIV C
 Enunciado : Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
para ofrecerlos a sus clientes.
Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciar� y contar� con un men� de opciones:
1. Ingresar Kil�metros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)
- Precio vuelo Aerol�neas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de d�bito (descuento 10%)
b) Tarjeta de cr�dito (inter�s 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)
4. Informar Resultados
�Latam:
a) Precio con tarjeta de d�bito: r
b) Precio con tarjeta de cr�dito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerol�neas:
a) Precio con tarjeta de d�bito: r
b) Precio con tarjeta de cr�dito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r �
5. Carga forzada de datos
6. Salir
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas.h"

int main(){
	setbuf(stdout,NULL);
	int opcion;
	int kilometros;
	int precioVuelosLatam;
	int precioVuelosAerolineas;
	float precioDebitoLatam;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioCreditoLatam;
	float precioBtcLatam;
	float precioBtcAerolineas;
	float precioPorKilometroLatam;
	float precioPorKilometroAerolinas;

	char seguir;
	seguir = 's';
	do{
		printf("1. Ingresar kilometros: \n");
		printf("2. Ingresar el precio de los vuelos: \n");
		printf("3. Calcular todos los costos \n");
		printf("4. Informar los resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				printf("Por favor ingrese los kilometros: ");
				kilometros=IngresarKilometros();
				break;
			case 2:
				precioVuelosLatam=IngresarPreciosVuelosLatam();
				precioVuelosAerolineas=IngresarPreciosVuelosAerolineas();
				break;
			case 3:
				printf("\na) Se estan calculando los precios con debito...");
				precioDebitoLatam=CalcularcostosDebito(precioVuelosLatam);
				precioDebitoAerolineas=CalcularcostosDebito(precioVuelosAerolineas);
				printf("\nb) Se estan calculando los precios con tarjeta de credito...");
				precioCreditoLatam=CalcularCostosCredito(precioVuelosLatam);
				precioCreditoAerolineas=CalcularCostosCredito(precioVuelosAerolineas);
				printf("\nc) Se esta calculando los precios en Bitcoins...");
				precioBtcLatam= CalcularCostosBtc(precioVuelosLatam);
				precioBtcAerolineas=CalcularCostosBtc(precioVuelosAerolineas);
				precioPorKilometroLatam=(float)precioVuelosLatam/kilometros;
				precioPorKilometroAerolinas=(float)precioVuelosAerolineas/kilometros;
				printf("\nd) Precio por kilometro en Latam: $%.2f",precioPorKilometroLatam);
				printf("\n   Precio por kilometro en Aerolineas: $%.2f \n",precioPorKilometroAerolinas);
				break;
			case 4:
				printf("precio debito: %f", precioDebitoLatam);
				break;
			case 5:
				break;
			case 6:
				printf("Gracias por usar nuestra app.");
				seguir = 'n';
				break;
			default:
				printf("Opcion incorrecta...\n");
				break;
		}
	}while(seguir == 's');
	return 0;
}
