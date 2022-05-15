#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esNumerica(char cadena[], int limite)
{
	int retorno = -1; //ERROR
	int i;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i = 0; i < limite && cadena[i] != '\0' ; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] > '9' ||cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int myGets(char cadena[], int longitud)
{
	int retorno = -1;
	char auxiliarString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(auxiliarString, sizeof(auxiliarString),stdin) != NULL)
		{
			if(auxiliarString[strnlen(auxiliarString,sizeof(auxiliarString))-1] == '\n')
			{
				auxiliarString[strnlen(auxiliarString,sizeof(auxiliarString))-1] = '\0';
			}
			if(strnlen(auxiliarString,sizeof(auxiliarString)) <= longitud)
			{
				strncpy(cadena,auxiliarString,longitud);
				retorno = 0;
			}
		}

	}

	return retorno;
}
int getInt(int *pResultado)
{
	int retorno = -1;
	char auxiliarString[50];

	if (pResultado != NULL)
	{
		if(myGets(auxiliarString, sizeof(auxiliarString)) == 0 && esNumerica(auxiliarString,sizeof(auxiliarString)) == 1)
		{
			retorno = 0;
			*pResultado = atoi(auxiliarString);
		}

	}

	return retorno;
}
int utn_getNumero(int *pNumero, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int auxiliarInt;

	if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo)
	{
		printf("%s",mensaje);
		while(reintentos>=0)
		{
			reintentos--;
			if(getInt(&auxiliarInt) == 0)
			{
				if(auxiliarInt >= minimo && auxiliarInt <= maximo)
				{
				retorno = 0;
				*pNumero = auxiliarInt;
					break;
				}
				printf("%s",mensajeError);
			}
		}

	}

	return retorno;
}
int calcularMayor(int num1, int num2, int *resultado)
{
	int retorno = -1;
	if(resultado != NULL)
	{

		if(num1 == num2)
			{
				retorno = 0; // Retornara 1 si los numeros son iguales
			}
		else
			{
				if(num1 > num2)
				{
					*resultado = num1;
				}
				else
				{
					*resultado = num2;
				}
				retorno = 1;
			}

	}

	return retorno;
}
int calcularMenor(int num1, int num2, int *resultado)
{
	int retorno = -1;
	if(resultado != NULL)
	{
		if(num1 == num2)
			{
				retorno = 0; // Retornara 1 si los numeros son iguales
			}
		else
			{
			if(num1 < num2)
			{
				*resultado = num1;
			}
			else
				{
					*resultado = num2;
				}
					retorno = 1;
				}
	}
	return retorno;
}
int esFloat(char cadena[], int limite)
{
	int retorno = -1; //ERROR
	int i;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+' || cadena[i] == '.'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int getFloat(float *pResultado)
{
	int retorno = -1;
	char auxiliarString[50];

	if (pResultado != NULL)
	{
		if(myGets(auxiliarString, sizeof(auxiliarString)) == 0 && esFloat(auxiliarString,sizeof(auxiliarString)) == 0)
		{
			retorno = 0;
			*pResultado = atof(auxiliarString);
		}
	}

		return retorno;
}
int utn_getFloat(float *pNumero, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	float auxiliarInt;

	if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos > 0)
	{
		printf("%s",mensaje);
		while(reintentos>=0)
		{
			reintentos--;
			if(getFloat(&auxiliarInt) == 0)
			{
				if(auxiliarInt > minimo && auxiliarInt < maximo)
				{
				retorno = 0;
				*pNumero = auxiliarInt;
					break;
				}
				printf("%s",mensajeError);
			}
			else
			{
				puts("\nTe falta el punto!!!'");
			}
		}

	}

	return retorno;
}
int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
int utn_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
int utn_getNombre(char pResultado[], int longitud, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char auxiliarString[4096];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && longitud > 0 && reintentos > 0)
	{
		while(reintentos>=0)
			{
				reintentos--;
				printf("%s",mensaje);
				if(getNombre(auxiliarString,sizeof(auxiliarString)) == 0 && strnlen(auxiliarString, sizeof(auxiliarString)) < longitud)
				{
				strncpy(pResultado,auxiliarString,longitud);
				retorno = 0;
					break;
				}
				printf("%s",mensajeError);

			}
	}

	return retorno;
}
int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != ' ' && cadena[i] != ',' && cadena[i] != '.' && (cadena[i] < 'A' || cadena[i] > 'Z' ) &&	(cadena[i] < 'a' || cadena[i] > 'z' ) &&	(cadena[i] < '0' || cadena[i] > '9' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


