#ifndef UTN_MV_H_
#define UTN_MV_H_

int utn_getNumero(int *pNumero, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

int getInt(int *pResultado);
int myGets(char cadena[], int longitud);
int esNumerica(char cadena[], int limite);

int utn_getFloat(float *pNumero, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
int getFloat(float *pResultado);
int esFloat(char cadena[], int limite);

int calcularMayor(int num1, int num2, int *resultado);
int calcularMenor(int num1, int num2, int *resultado);

int getString(char* cadena, int longitud);
int getNombre(char* pResultado, int longitud);
int esNombre(char* cadena,int longitud);
int utn_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getNombre(char pResultado[], int longitud, char mensaje[], char mensajeError[],int reintentos);

int esDescripcion(char* cadena,int longitud);

int getDescripcion(char* pResultado, int longitud);

int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

#endif
