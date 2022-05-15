#include "TP_2.h"


/// \fn int utn_getCaracter(char*, char*, char*, char, char, int)
/// \brief validar que se ingresen caracteres
/// \param pResultado
/// \param mensaje
/// \param mensajeError
/// \param minimo
/// \param maximo
/// \param reintentos
/// \return si se ingresaron caracteres devuelve 1, si hubo un error devuelve -1

//int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
	int resultado;
	char buffer;
	resultado = -1;

	if((pResultado != NULL) && (mensaje != NULL) && (mensajeError != NULL) && (minimo <= maximo)){//verificar que los punteros apunten a una direccion de memoria
		fflush(stdin);
		do{
			printf("%s", mensaje);
			scanf("%c", &buffer);
			if(buffer <= minimo && buffer <= maximo){
				*pResultado = buffer;
				resultado = 1;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}

	return resultado;
}

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int myGets(char* cadena, int longitud){
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena){
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if(cadena[strlen(cadena)-1] == '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
		return 0;
	}
	return -1;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/
static int getInt(int* pResultado){
	int retorno;
	retorno = -1;
	char buffer[64];
	if(pResultado != NULL){
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer)){
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena ES la Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
static int esNumerica(char* cadena){
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0){
		while(cadena[i] != '\0'){
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
			retorno = 0;
			break;
			}
			i++;
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el numero minimo a ser aceptado
 * \return Retorna 1 si se obtuvo el numero y -1 si no
 */
//int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int bufferInt;
	int retorno = -1;
	if((pResultado != NULL) && (mensaje != NULL) && (mensajeError != NULL) && (minimo <= maximo)){
		fflush(stdin);
		while(reintentos>0){
			reintentos--;
			printf("%s",mensaje);
			if(getInt(&bufferInt) == 0){
				if(bufferInt >= minimo && bufferInt <= maximo){
					*pResultado = bufferInt;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}


static float esNumericafloat(char* cadena);
static float getFloat(float* pResultado);
static float getFloat(float* pResultado){
	float retorno;
	retorno = -1;
	char buffer[64];
	if(pResultado != NULL){
		if(myGets(buffer,sizeof(buffer))==0 && esNumericafloat(buffer)){
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static float esNumericafloat(char* cadena){
	int i=0;
	float retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0){
		while(cadena[i] != '\0'){
			if(cadena[i] < '0' || cadena[i] > '9' || cadena[i+3] != '.')
			{
			retorno = 0;
			break;
			}
			i++;
		}
	}
	return retorno;
}

//int utn_getNumeroConDecimales(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNumeroConDecimales(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
	int retorno;
	float bufferFloat;
	retorno = 1;

	if((pResultado != NULL) && (mensaje != NULL) && (mensajeError != NULL) && (minimo <= maximo)){
		fflush(stdin);
		while(reintentos>0){
			reintentos--;
			printf("%s",mensaje);
			if(getFloat(&bufferFloat) == 0){
				if(bufferFloat >= minimo && bufferFloat <= maximo){
					*pResultado = bufferFloat;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}
