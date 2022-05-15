#include "ArrayPassenger.h"
#include "utn_MV.h"


int totalPromedioPasajes(Pasajero arrayVuelo[], int limite)
{
	int retorno = -1;
	int i;
	float total;
	double totalacumulado;

	if(arrayVuelo != NULL && limite > 0)
	{
				if(arrayVuelo->isEmpty == 0)
				{
					for(i = 0; i<limite; i++)
					{
						total = arrayVuelo[i].price;
						totalacumulado = total + totalacumulado;
						retorno = 0;
					}
				}

	}

	printf("Total: %.2f",totalacumulado);

	return retorno;
}

int vueloActivos(Pasajero arrayVuelo[], int limite)
{
	int retorno = -1;
	int i;

	if(arrayVuelo != NULL && limite > 0)
	{
		printf("|ID  |CODIGO DE VUELO|ESTADO DE VUELO|\n");
		for(i=0; i < limite; i++)
			{
				if(arrayVuelo[i].isEmpty == 0)
				{
				printf("|%-4d|%-15s|",arrayVuelo[i].id,arrayVuelo[i].flycode);
					switch(arrayVuelo[i].statusFlight)
					{
							case 1:
								printf("%-15s|\n","ACTIVO");
								break;
							case 2:
								printf("%-15s|\n","INACTIVO");
								break;
							case 3:
								printf("%-15s|\n","CANCELADO");
								break;
							default:
								break;
					}
					retorno = 0;
				}

			}
	}

	return retorno;
}
