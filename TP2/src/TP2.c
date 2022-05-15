#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_MV.h"
#include "ArrayPassenger.h"
#include "Vuelo.h"

#define QTY_PASAJEROS 200

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int opcion4;

	Pasajero arrayPasajero[QTY_PASAJEROS];

	if(initPassengers(arrayPasajero, QTY_PASAJEROS)== 0)
	{
		printf("***TP - N2***\n\n");
	}

	do
		{
			utn_getNumero(&opcion, "\tMENU"
									"\n1.ALTAS"
									"\n2.MODIFICAR"
									"\n3.BAJA"
									"\n4.INFORMAR"
									"\n5.SALIR"
					                "\nOPCION: ", "\nOpcion incorrecta. Vuelva a ingresar: ", 1, 5, 3);

			switch(opcion)
			{
			case 1:
				if(addPassenger(arrayPasajero, QTY_PASAJEROS) == 1)
				{
					puts("\n\tALTA REALIZADA!!!");
				}
				else
				{
					puts("ERROR EN ALTA");
				}
				break;
			case 2:
				if(modifyPassenger(arrayPasajero, QTY_PASAJEROS) == 1)
				{
					puts("\n\tMODIFICACION REALIZADA!!!");
				}
				else
				{
					puts("\n\tNo hay a nadie a quien modificar!!!\n");
				}
				break;
			case 3:
				if(removePassenger(arrayPasajero, QTY_PASAJEROS) == 1)
				{
					puts("\n\tBAJA REALIZADA!!!");
				}
				else
				{
					puts("\n\tNo hay nadie a quien darle de baja!!!\n");
				}
				break;
			case 4:
				utn_getNumero(&opcion4, "1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
						"\n2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
						"\n3.Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ "
						"\nOPCION: ", "\nERROR", 1, 3, 5);

				switch(opcion4)
				{
				case 1:
					sortPassengers(arrayPasajero, QTY_PASAJEROS);
					printArrayPassengerOrdenado(arrayPasajero, QTY_PASAJEROS);
					break;
				case 2:

					break;
				case 3:
					if(vueloActivos(arrayPasajero, QTY_PASAJEROS) == 0)
					{

					}
					else
					{
						puts("\nNo hay pasajeros!!!\n");
					}
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}

		}while(opcion != 5);

	puts("\nFinalizando...");

	return EXIT_SUCCESS;
}
