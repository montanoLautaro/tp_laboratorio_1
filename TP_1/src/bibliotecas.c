#include <stdio.h>
#include "bibliotecas.h"

int IngresarKilometros(void){
	int kilometros;
	printf("Por favor ingrese los kilometros: ");
	scanf("%d",&kilometros);
	return kilometros;
}
int IngresarPreciosVuelosLatam(void){
	int precio;
	printf("Por favor ingrese el precio de los vuelos de LATAM: ");
	scanf("%d",&precio);
	return precio;
}
int IngresarPreciosVuelosAerolineas(void){
	int precio;
	printf("Por favor ingrese el precio de los vuelos de Aerolíneas: ");
	scanf("%d",&precio);
	return precio;
}
float CalcularcostosDebito(int precio){
	float descuento;
	descuento=0.9;
	precio = (float)precio * descuento;
	return precio;
}
float CalcularCostosCredito(int precio){
	float aumento;
	aumento=1.25;
	precio = (float)precio * aumento;
	return precio;
}
float CalcularCostosBtc(int precio){
	float precioBtc;
	precioBtc=4606954.55;
	precio = precio * precioBtc;
	return precio;
}

