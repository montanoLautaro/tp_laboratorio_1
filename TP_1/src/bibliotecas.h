/// \fn float IngresarKilometros(void)
/// \brief ingreso de kilometros en la opcion 1
float IngresarKilometros(void);

/// \fn float IngresarPreciosVuelos(void)
/// \brief ingreso de precio de los vuelos de la opcion 2
float IngresarPreciosVuelos(void);

/// \fn float ValidarNumero(float, float, char[])
/// \brief validacion de los numeros de las funciones IngresarKilometros y IngresarPreciosVuelos
float ValidarNumero(float,float,char[]);

/// \fn float CalcularcostosDebito(float)
/// \brief costos de tarjeta de débito, descuento 10% al precio ingresado
float CalcularCostosDebito(float);

/// \fn float CalcularCostosCredito(float)
/// \brief costos de tarjeta de crédito, interés 25% al precio ingresado
float CalcularCostosCredito(float);

/// \fn float CalcularCostosBtc(float)
/// \brief costos en Bitcoin (1BTC -> 4606954.55 Pesos Argentinos) al precio ingresado
float CalcularCostosBtc(float);

/// \fn float CalcularPrecioPorKilometro(float)
/// \brief precio ingresado / kilometros ingresados
float CalcularPrecioUnitario(float, float);

/// \fn float CalcularDiferenciaPrecio(float, float)
/// \brief
float CalcularDiferenciaPrecio(float, float);

/// \fn void MostrarResultados(float, float, float, float)
/// \brief muestras los datos solicitados en la opcion 4 y 5
void MostrarResultados(float,float,float,float);
