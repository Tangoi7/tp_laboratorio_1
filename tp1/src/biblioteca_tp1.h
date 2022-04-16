/*
 * biblioteca_tp1.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Mariano
 */

#ifndef BIBLIOTECA_TP1_H_
#define BIBLIOTECA_TP1_H_
#include <stdio.h>
#include <stdlib.h>

void getMenu();
int getNumero(int *numeroPedido, int minimo, int maximo, char mensaje[], char mensajeError[]);
int getKilometros(int *km, char mensaje[]);
int getPrecios(int *vueloAerolineas, int *vueloLatam);
void getMenuTres();
int getDatos(int dato1, int dato2, int dato3);

float getDescuento(float num1);
float getInteres(float num1);
float getBitcoin(float num1);
float getDiferencia(float num1, float num2);
float getPrecioUnitario(float num1, float num2);

#endif /* BIBLIOTECA_TP1_H_ */
