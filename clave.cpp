/* ===================================================================================
	Programa: Leer clave ---- by mark TM

	//El programa necesita estas bibliotecas
	#include <conio.h>
	#include <stdio.h>
	#include <windows.h>

	//Definir ENTER
	#define ENTER 13

	La funcion :   leerClave("Titulo",max,variable);
=================================================================================== */

void leer_clave(char *titulo, int maxCaracteres, char *clave){
	printf("%s: ",titulo);
	char c;
	int i = 0;
	while((c = getch()) != ENTER && i < maxCaracteres-1){
		if(c == 8){
			if(i > 0){
				i--;
				printf("\b \b");
			}
		} else {
			printf("*");
			clave[i] = c;
			i++;
		}
	}
	clave[i] = '\0';
}

