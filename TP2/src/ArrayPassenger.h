#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 51

typedef struct
{
	int id;
	char name[NAME_LEN];
	char lastName[NAME_LEN];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}Pasajero;

int initPassengers(Pasajero arrayPassenger[], int limite);
int ePassenger_indexLibre(Pasajero arrayPassenger[], int limite);
int findPassengerById(Pasajero arrayPassenger[], int limite,int ID);
Pasajero loadDataPassenger(void);
void printPassenger(Pasajero Passenger);
void printPassengerOrdenado(Pasajero Passenger);
int printArrayPassengerOrdenado(Pasajero arrayPassenger[], int limite);
Pasajero modificarUno(Pasajero Passenger);
int printArrayPassenger(Pasajero arrayPassenger[], int limite);
//-----------ORDENAR--------
int sortPassengers(Pasajero arrayPassenger[], int limite);
int sortPassengersByCode(Pasajero arrayPassenger[], int limite, int order);
//-----------ABM------------
int addPassenger(Pasajero arrayPassenger[], int limite); //ALTA
int removePassenger(Pasajero arrayPassenger[], int limite); //BAJA
int modifyPassenger(Pasajero arrayPassenger[], int limite); //MODIFICACION


#endif /* ARRAYPASSENGER_H_ */
