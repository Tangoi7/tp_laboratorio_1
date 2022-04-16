/*
 * biblioteca_tp1.c
 *
 *  Created on: 15 abr. 2022
 *      Author: Mariano
 */

#include <stdio.h>
#include <stdlib.h>

void getMenu()
{
	printf("\n\tMENU DE OPCIONES\n");
	printf("\n1. Ingresar Kilómetros: ");
	printf("\n2. Ingresar Precio de Vuelos:");
	printf("\n3. Calcular todos los costos:");
	printf("\n4. Informar Resultados");
	printf("\n5. Carga forzada de datos");
	printf("\n6. Salir");
}
int getNumero(int *numeroPedido, int minimo, int maximo, char mensaje[], char mensajeError[])
{
	int retorno;
	int auxiliarInt;
	if(numeroPedido != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo)
	{
		printf("%s",mensaje);
		scanf("%d",&auxiliarInt);
		fflush(stdin);
		if(auxiliarInt > maximo || auxiliarInt < minimo)
		{
			retorno = printf("%s",mensajeError);
		}
		else
		{
			*numeroPedido = auxiliarInt;
			retorno = *numeroPedido;
		}
	}

	return retorno;
}
int getKilometros(int *km, char mensaje[])
{
	int retorno;
	int auxiliarKm = 0;

	if(km != NULL && mensaje != NULL)
	{
		printf("%s",mensaje);
		scanf("%d",&auxiliarKm);
		fflush(stdin);
		if(auxiliarKm < 1)
		{
			retorno = printf("\nAlerta, no esta ingresando un kilometro valido\n");
		}
		else
		{
			fflush(stdin);
			*km = auxiliarKm;
			retorno = *km;
		}

	}
	return retorno;

}
int getPrecios(int *vueloAerolineas, int *vueloLatam)
{
	int retorno;
	int auxiliarPrecioA = 0;
	int auxiliarPrecioL = 0;

	if(vueloAerolineas != NULL && vueloLatam != NULL)
	{
		printf("\n\t-Ingresar Precio de Vuelos: -\n");
		printf("\n- Precio vuelo Aerolíneas:");
		scanf("%d",&auxiliarPrecioA);
		fflush(stdin);
		printf("\n- Precio vuelo Latam:");
		scanf("%d",&auxiliarPrecioL);
		fflush(stdin);
		if(auxiliarPrecioA < 1)
		{
			retorno = printf("\n!Alerta no se ingreso un precio para el vuelo de Aerolineas. \n");
		}
		else
		{
			*vueloAerolineas = auxiliarPrecioA;
			retorno = *vueloAerolineas;
		}

		if(auxiliarPrecioL < 1)
		{
			retorno = printf("\n!Alerta no se ingreso un precio para el vuelo de Latam. \n");
		}
		else
		{
			*vueloLatam = auxiliarPrecioL;
			retorno = *vueloLatam;
		}
	}

	return retorno;
}
void getMenuTres()
{

	puts("\nSe calcularan todas estas opciones: ");
	puts("\na) Tarjeta de débito (descuento 10%)");
	puts("\nb) Tarjeta de crédito (interés 25%.)");
	puts("\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)");
	puts("\nd) Mostrar precio por km (precio unitario) ");
	puts("\ne) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");

}
int getDatos(int dato1, int dato2, int dato3)
{
	int retorno;
	//dato1 = kilometros.
	//dato2 = precio para el vuelo de Aerolineas.
	//dato3 = precio para el vuelo de Latam.

	if(dato1<1)
	{
		retorno = printf("\nAlerta!!.No se han igresado kilometros.\n");
	}
	if(dato2<1)
	{
		retorno = printf("\nAlerta!!.No se ha ingresado un precio para el vuelo de Aerolineas.\n");
	}
	if(dato3<1)
	{
		retorno = printf("\nAlerta!!.No se ha ingresado un precio para el vuelo de Latam.\n");
	}


	return retorno;

}

float getDescuento(float num1)
{
	float precioDescuento;

	precioDescuento = num1 - (num1 * 0.10);

	return precioDescuento;
}
float getInteres(float num1)
{
	float precioInteres;

	precioInteres = num1 + (num1 * 0.25);

	return precioInteres;
}
float getBitcoin(float num1)
{
	float precioFinal;
	float bitcoin = 4606954.55;

	precioFinal = num1 / bitcoin;

	return precioFinal;
}
float getDiferencia(float num1, float num2)
{
	float diferenciaPrecio;

	if(num1 > num2)
	{
		diferenciaPrecio = num1 - num2;
	}
	else
	{
		diferenciaPrecio = num2 - num1;
	}

	return diferenciaPrecio;
}
float getPrecioUnitario(float num1, float num2)
{
	float precioUnitario;
	//num1 = kilometros
	//num2 = vuelo aerolineas/latam

	if(num2 == 0 && num1 == 0)
	{
		precioUnitario = puts("\nNo hay datos ingresados");
	}
	else
	{
		if(num1 == 0)
		{
			precioUnitario  = puts("\nNo se ingreso ningun kilometro.");
		}
		else
		{
		precioUnitario = num2 / num1;
		}
	}

	return precioUnitario;
}

