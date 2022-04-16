#include <stdio.h>
#include "bibliotecas.h"

float IngresarKilometros(void){
	float kilometros;
	printf("\nPor favor ingrese la cantidad de kilómetros: ");
	scanf("%f",&kilometros);
	kilometros=ValidarNumero(kilometros,1,"Ingrese un número válido:");
	return kilometros;
}
float IngresarPreciosVuelos(void){
	float precio;
	scanf("%f",&precio);
	precio=ValidarNumero(precio,1,"Ingrese un precio válido:");
	return precio;
}

float ValidarNumero(float numero, float rangoMinimo, char mensajeError[])
{
	while(numero<rangoMinimo)
	{
		printf("%s\n",mensajeError);
		scanf("%f",&numero);
	}
	return numero;
}
float CalcularcostosDebito(float precio){
	float descuento;
	descuento=0.9;
	precio = precio * descuento;
	return precio;
}
float CalcularCostosCredito(float precio){
	float aumento;
	aumento=1.25;
	precio = precio * aumento;
	return precio;
}
float CalcularCostosBtc(float precio){
	float precioBtc;
	precioBtc=4606954.55;
	precio = precio/precioBtc;
	return precio;
}
float CalcularPrecioUnitario(float precio, float kilometros){
	float precioUnitario;
	precioUnitario=precio/kilometros;
	return precioUnitario;
}
float CalcularDiferenciaPrecio(float precioUno, float precioDos){
	float diferencia;
	diferencia = precioUno - precioDos;
	if(precioDos>precioUno){
		diferencia = precioDos - precioUno;
	}
	return diferencia;
}
void MostrarResultados(float precioDebito,float precioCredito,float precioBtc,float precioUnitario){
	printf("a) Precio con tarjeta de débito: $%.2f \n", precioDebito);
	printf("b) Precio con tarjeta de crédito: $%.2f \n", precioCredito);
	printf("c) Precio pagando con bitcoin : %f BTC\n", precioBtc);
	printf("d) Precio unitario: $%.2f \n\n", precioUnitario);
}
