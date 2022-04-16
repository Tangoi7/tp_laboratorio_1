//TP N1 - Laboratorio I - Mariano Vega / 1H

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_tp1.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int kilometros = 0;
	int precioVuelosAerolineas = 0;
	int precioVuelosLatam = 0;

	int kilometrosForzados = 7090;
	int precioAerolineasForzado = 162965;
	int precioLatamForzado = 159339;

	do
	{
		fflush(stdin);
		getMenu();
		getNumero(&opcion, 1, 6, "\nIngrese una opcion: ", "\nOpcion no valida. Vuelva a ingresar otra opcion.\n");
		fflush(stdin);

		switch(opcion)
		{
		case 1:
			getKilometros(&kilometros, "\nIngrese los kilometros: ");
			fflush(stdin);

			system("pause");
			break;
		case 2:
			getPrecios(&precioVuelosAerolineas, &precioVuelosLatam);

			fflush(stdin);

			system("pause");
			break;
		case 3:
			getMenuTres();
			getDatos(kilometros, precioVuelosAerolineas, precioVuelosLatam);
			puts("\n");

			fflush(stdin);

			system("pause");
			break;
		case 4:
			getDatos(kilometros, precioVuelosAerolineas, precioVuelosLatam);

			puts("\nINFORMAR RESULTADOS.");

			printf("\n -LATAM- \n");
			printf("\na) Precio con tarjeta de debito: $%.2f",getDescuento(precioVuelosLatam));
			printf("\nb) Precio con tarjeta de crédito: $%.2f",getInteres(precioVuelosLatam));
			printf("\nc) Precio pagando con bitcoin: %.5fBTC",getBitcoin(precioVuelosLatam));
			printf("\nd) Precio unitario: $%.2f\n",getPrecioUnitario(kilometros, precioVuelosLatam));

			printf("\n -AEROLINEAS- \n");
			printf("\na) Precio con tarjeta de debito: $%.2f",getDescuento(precioVuelosAerolineas));
			printf("\nb) Precio con tarjeta de crédito: $%.2f",getInteres(precioVuelosAerolineas));
			printf("\nc) Precio pagando con bitcoin: %.5fBTC",getBitcoin(precioVuelosAerolineas));
			printf("\nd) Precio unitario: $%.2f\n",getPrecioUnitario(kilometros, precioVuelosAerolineas));

			printf("\nLa diferencia de precio es: $%.2f\n",getDiferencia(precioVuelosAerolineas, precioVuelosLatam));


			system("\npause");

			break;
		case 5:
			printf("\nKMs ingresados: %d\n",kilometrosForzados);

			printf("\nPrecio Aerolineas: $%d",precioAerolineasForzado);
			printf("\na)Precio con tarjeta de debito: $%.2f",getDescuento(precioAerolineasForzado));
			printf("\nb)Precio con tarjeta de credito: $%.2f",getInteres(precioAerolineasForzado));
			printf("\nc)Precio pagando con Bitcoin: %.5fBTC",getBitcoin(precioAerolineasForzado));
			printf("\nd)Mostrar precio Unitario: $%.2f\n",getPrecioUnitario(kilometrosForzados, precioAerolineasForzado));

			printf("\nPrecio Latam: $%d",precioLatamForzado);
			printf("\na)Precio con tarjeta de debito: $%.2f",getDescuento(precioLatamForzado));
			printf("\nb)Precio con tarjeta de credito: $%.2f",getInteres(precioLatamForzado));
			printf("\nc)Precio pagando con Bitcoin: %.5fBTC",getBitcoin(precioLatamForzado));
			printf("\nd)Mostrar precio Unitario: $%.2f\n",getPrecioUnitario(kilometrosForzados, precioLatamForzado));

			printf("\nLa diferencia de precio es: $%.2f\n",getDiferencia(precioAerolineasForzado, precioLatamForzado));

			system("\npause");
			break;
		case 6:
			break;
		default:
			break;

	}

	}while(opcion != 6);

	puts("\nHasta luego!");

	return EXIT_SUCCESS;
}

