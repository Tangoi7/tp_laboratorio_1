#include "ArrayPassenger.h"
#include "utn_MV.h"

static int ePassenger_ObtenerID(void);//GENERO Y OBTENGO UN ID
static int ePassenger_ObtenerID(void)
{
	static int Passenger_idIncremental = 0;

		return Passenger_idIncremental++;
}

//Inicializo el array, cargando en su isEmpty un 1, que es igual a un lugar LIBRE
int initPassengers(Pasajero arrayPassenger[], int limite)
{
	int retorno = -1;
	int i;

	if(arrayPassenger != NULL && limite > 0)
	{
		retorno = 0;

		for(i=0;i<limite;i++)
		{
			arrayPassenger[i].isEmpty = 1; //1 (Es 1 si esta libre) || 0 (Es 0 si esta ocupado)
		}
	}
	return retorno;
}

//Busco y pido el primer isEmpty libre para ocuparlo con un usuario, es decir pasarlo de 1 a 0 (OCUPADO)
int ePassenger_indexLibre(Pasajero arrayPassenger[], int limite)
{
	int retorno = -1;
	int i;

	if(arrayPassenger != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(arrayPassenger[i].isEmpty == 1) //Buscara la primera posicion del array que este libre(1) y me la dara en el retorno
			{
				retorno = i;
				break;
			}
			else
			{
				retorno = -3;
			}
		}
	}else
	{
		retorno = -2;
	}

	return retorno;
}

//Busco por el ID a tal posicion
int findPassengerById(Pasajero arrayPassenger[], int limite,int ID)
{
	int retorno = -1;
	int i;

	if(arrayPassenger != NULL && limite > 0)
	{
		for(i = 0 ; i < limite ; i++)
		{
			if(arrayPassenger[i].id == ID && arrayPassenger[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

//Muestro datos de un solo usuario de forma encolumnada
void printPassenger(Pasajero Passenger)
{
		 // |id   |name |lastN|price  |flyC
	printf("|%-4d|%-10s|%-10s|%-10.2f|%-10s|",Passenger.id,Passenger.name,Passenger.lastName,Passenger.price,Passenger.flycode);
	switch(Passenger.typePassenger)
	{
	case 1:
		printf("%-16s|","CLASE TURISTA");
		break;
	case 2:
		printf("%-16s|","PRIMERA CLASE");
		break;
	case 3:
		printf("%-16s|","CLASE EJECUTIVA");
		break;
	default:
		break;
	}
	switch(Passenger.statusFlight)
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


}

//Muestro datos de un solo usuario de forma encolumnada y alfabeticamente
void printPassengerOrdenado(Pasajero Passenger)
{
	printf("|%-4d|%-10s|",Passenger.id,Passenger.lastName);
	switch(Passenger.typePassenger)
		{
		case 1:
			printf("%-16s|\n","CLASE TURISTA");
			break;
		case 2:
			printf("%-16s|\n","PRIMERA CLASE");
			break;
		case 3:
			printf("%-16s|\n","CLASE EJECUTIVA");
			break;
		default:
			break;
		}
}

//Muestro datos de un array de usuarios de forma encolumnada y alfabeticamente
int printArrayPassengerOrdenado(Pasajero arrayPassenger[], int limite)
{
	int retorno = -1;
	int i;

	if(arrayPassenger != NULL && limite > 0)
	{
		printf("|ID  |LAST NAME |TIPO DE PASAJERO|\n");
		for(i=0; i < limite; i++)
			{
				if(arrayPassenger[i].isEmpty == 0)
				{
				retorno = 0;
				printPassengerOrdenado(arrayPassenger[i]);
				}
				else
				{
					puts("\nNO HAY PASAJEROS!!!\n");
					break;
				}
			}
	}

	return retorno;
}

//Muestro datos de un array de usuarios de forma encolumnada
int printArrayPassenger(Pasajero arrayPassenger[], int limite)
{
	int retorno = -1;
	int i;

	if(arrayPassenger != NULL && limite > 0)
	{
		printf("|ID  |NAME      |LAST NAME |PRICE     |FLYCODE   |TIPO DE PASAJERO|ESTADO DE VUELO|\n");
		for(i=0; i < limite; i++)
		{
			if(arrayPassenger[i].isEmpty == 0)
			{
			retorno = 0;
			printPassenger(arrayPassenger[i]);
			}
		}
	}

	return retorno;
}

//Cargo los datos necesarios del usuario
Pasajero loadDataPassenger(void)
{
	Pasajero auxiliarPasajero;

	utn_getNombre(auxiliarPasajero.name, 51, "Ingrese Nombre: ", "\nERROR\n", 3);
	utn_getNombre(auxiliarPasajero.lastName, 51, "Ingrese Apellido: ", "\nERROR\n", 3);
	utn_getFloat(&auxiliarPasajero.price, "Precio: ", "\nERROR. Ingrese nuevamente: ", 1, 999999, 3);
	utn_getDescripcion(auxiliarPasajero.flycode, 10, "Ingrese codigo de vuelo: ", "\nERROR\n", 3);
	utn_getNumero(&auxiliarPasajero.typePassenger, "\nIngrese tipo de pasajero: "
			"\n1. Clase Turista\n"
			"2. Clase Primera Clase\n"
			"3. Clase Ejecutiva\n"
			"OPCION: ", "\nERROR. Ingrese nuevamente: ", 1, 3, 3);
	utn_getNumero(&auxiliarPasajero.statusFlight, "\nIngrese el estado de su vuelo: "
			"\n1 Activo"
			"\n2 Inactivo"
			"\n3 Cancelado"
			"\nOPCION: ", "\nERROR. Ingrese nuevamente: ", 1, 3, 3);

	return auxiliarPasajero;
}

//Funcion de opciones para modificar a un usuario
Pasajero modificarUno(Pasajero Passenger)
{
	Pasajero aux = Passenger;

	int opcion;

	utn_getNumero(&opcion, "\n1.Modificar Nombre: "
			"\n2.Modificar Apellido: "
			"\n3.Modificar Precio: "
			"\n4.Modificar Codigo de Vuelo: "
			"\n5.Modificar Tipo de Pasajero: "
			"\n6.Modificar Estado de vuelo: "
			"\nOPCION: "
			, "\nERROR! ingrese nuevamente", 1, 6, 5);

	switch(opcion)
	{
	case 1:
		utn_getNombre(aux.name, 51, "Ingrese Nombre: ", "\nERROR", 3);
		break;
	case 2:
		utn_getNombre(aux.lastName, 51, "Ingrese Apellido: ", "\nERROR", 3);
		break;
	case 3:
		utn_getFloat(&aux.price, "Precio: ", "\nERROR. Ingrese nuevamente: ", 1, 999999, 3);
		break;
	case 4:
		utn_getDescripcion(aux.flycode, 10, "Ingrese codgio de vuelo:", "\nERROR", 3);
		break;
	case 5:
		utn_getNumero(&aux.typePassenger, "Ingrese tipo de pasajero: "
				"\n1. Clase Turista\n"
				"2. Clase Primera Clase\n"
				"3. Clase Ejecutiva\n", "\nERROR", 1, 4, 3);
		break;
	case 6:
		utn_getNumero(&aux.statusFlight, "Ingrese el estado de su vuelo: "
					"\n1 Activo"
					"\n2 Inactivo"
					"\n3 Cancelado", "\ERROR", 1, 3, 3);
		break;
	default:
		break;
	}


	return aux;
}
//--------------ORDENAR----------------------------

//Ordeno un array alfabeticamente (a -> z)
int sortPassengers(Pasajero arrayPassenger[], int limite)
{
	int retorno = -1;
	int flagSwap;
	int i;

	Pasajero aux;

	if(arrayPassenger != NULL && limite >= 0)
	{
		do
		{
			flagSwap = 0;
			for(i = 0;i<limite-1;i++)
			{
				if(arrayPassenger[i].isEmpty || arrayPassenger[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(arrayPassenger[i].lastName,arrayPassenger[i+1].lastName,NAME_LEN) > 0)
				{
					flagSwap = 1;
					aux = arrayPassenger[i];
					arrayPassenger[i] = arrayPassenger[i+1];
					arrayPassenger[i+1] = aux;
					retorno = 0;
				}

			}
			limite--;

		}while(flagSwap);
	}
	else
	{
		puts("\nNo hay pasajeros!!!\n");
	}


	return retorno;
}

//----------------ABM------------------------------

//ALTA
int addPassenger(Pasajero arrayPassenger[], int limite)
{
	int retorno = 0;
	int index;
	Pasajero auxiliarPasajero;

	if(arrayPassenger != NULL && limite > 0)
	{
		index = ePassenger_indexLibre(arrayPassenger, limite);

		if(arrayPassenger != NULL && limite > 0)
		{
			if(index >= 0)
			{
				auxiliarPasajero = loadDataPassenger();

				auxiliarPasajero.id = ePassenger_ObtenerID();

				auxiliarPasajero.isEmpty = 0;

				arrayPassenger[index] = auxiliarPasajero;

				retorno = 1; //RETORNO 1  = Fue dado de alta correctamente
			}

		}
	}

	return retorno;
}

//BAJA
int removePassenger(Pasajero arrayPassenger[], int limite)
{
	int retorno = 0;
	int idPasajero;
	int index;
	int flag = 0;

	if(arrayPassenger != NULL && limite > 0)
	{
		if(printArrayPassenger(arrayPassenger, limite) == 0)
		{
			flag = 1; // FLAG EN 1 si es que hay pasajero cargados en el ALTA
		}

		if(flag)
		{
			printf("INGRESE ID A DAR DE BAJA: ");//ID para la BAJA
			getInt(&idPasajero);

			while(findPassengerById(arrayPassenger, limite, idPasajero) == -1)
			{
				puts("EL ID SOLICITADO NO EXISTE!!!");

				printf("INGRESE ID A DAR DE BAJA: ");//ID para la BAJA
				getInt(&idPasajero);

			}

			index = findPassengerById(arrayPassenger, limite, idPasajero);

			arrayPassenger[index].isEmpty = -1; // BAJA ACEPTADA - CAMBIO DE ESTADO

			retorno = 1; // SI RETORNA 1, la baja se realizo correctamente
		}

	}
	return retorno;
}

//MODIFICACION
int modifyPassenger(Pasajero arrayPassenger[], int limite)
{
	int retorno = 0;
	int idPasajero;
	int index;
	int flag = 0;
	Pasajero auxPasajero;

	if(arrayPassenger != NULL && limite > 0)
	{

		if(printArrayPassenger(arrayPassenger, limite) == 0)
		{
			flag = 1;
		}

		if(flag == 1)
			{
				printf("\nINGRESE ID PARA MODIFICAR: ");//ID para la MODIFICACION
				getInt(&idPasajero);

				while(findPassengerById(arrayPassenger, limite, idPasajero) == -1)
				{
					puts("EL ID SOLICITADO NO EXISTE!!!");

					printf("INGRESE ID PARA MODIFICAR: ");//ID para la MODIFICACION
					getInt(&idPasajero);

				}

				index = findPassengerById(arrayPassenger, limite, idPasajero); //INDEX DE ARRAY A MODIFICAR

				auxPasajero = modificarUno(arrayPassenger[index]); // FUNCION QUE MODIFICA

				arrayPassenger[index] = auxPasajero; //MODIFICACION ACEPTADA


				retorno = 1;

			}
	}

	return retorno;
}
