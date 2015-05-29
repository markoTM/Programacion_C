/* ===================================================================================
    > Programa: Menu de Presentacion
    > Autor: Marko Antonio Tantalean M

    Colores:
    	- Negro				- Blanco					- Amarillo Claro
    	- Azul				- Gris						- Blanco Brillante
    	- Verde				- Azul Claro 				- Purpura Claro
    	- Aguamarina		- Verde Claro 				- Amarillo
    	- Rojo				- Aguamarina Claro 			- Rojo Claro
    	- Purpura

	Cabecera : "menu.h"

	Funcion:
	LeerMenu("Titulo",tablaMenu,cantOpciones,"ColorFondo","ColorTexto","ColorF Selector", "ColorT Selector");

/* ===================================================================================
	EJEMPLO :

		void procesa(int op){
			clrscr();
			printf("\nLa opcion es: %d",op);
			getch();
		}

		int main(){
			int op;
			char *tablaMenu[] = {"Registra","Mostrar","Salir"};
			int cantOpciones = 3;
			op = LeerMenu("MENU PRINCIPAL",tablaMenu, cantOpciones, "azul","blanco", "verde", "blanco");
			procesa(op);
			return 0;
		}
=================================================================================== */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define ARR 72
#define ABA 80
#define ENTER 13

/* ===================================================================================
	FUNCIONES GENERALES
=================================================================================== */

int filtrar_color(char colorFondo[], char colorTexto[]){
	int numColor = -1;
	int numColorFondo = 0;
	int numColorTexto = 15;
	char listaColores[16][20] = {"Negro","Azul","Verde","Aguamarina","Rojo","Purpura","Amarillo","Blanco","Gris","Azul claro","Verde claro","Aguamarina claro","Rojo claro","Purpura claro","Amarillo claro","Blanco brillante"};
	for(int i = 0; i < 16; i++){
		if(strcmpi(colorFondo, listaColores[i] ) == 0)
			numColorFondo = i;
		if(strcmpi(colorTexto, listaColores[i] ) == 0)
			numColorTexto = i;
	}
	if(numColorFondo == numColorTexto)
		numColorTexto = 15;

	numColor = numColorFondo * 16 + numColorTexto;
	return numColor;
}

void Color(char colorFondo[], char colorTexto[]){
	int numColor = filtrar_color(colorFondo, colorTexto);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),numColor);
}

void lineas_estructura(int max){
	for(int i = 0; i < max; i++)
		printf("%c", 205);
};

void crear_estructura(char *titulo, int cantOpciones){
	system("cls");
	int posX = 5, posY = 3;
	unsigned int margenIzq = (60 - strlen(titulo))/2;

	gotoxy(posX, posY);
	printf("%c", 201);
	lineas_estructura(61);
	printf("%c", 187);
	gotoxy(posX, ++posY);
	printf("%c", 186);
	gotoxy(posX + margenIzq, posY);
	printf(" %s", titulo);
	gotoxy(posX + 62, posY);
	printf("%c", 186);
	gotoxy(posX, ++posY);
	printf("%c", 204);
	lineas_estructura(61);
	printf("%c", 185);
	for (int i = 0; i < cantOpciones*2+1; ++i) {
		gotoxy(posX, ++posY);
		printf("%c", 186);
		gotoxy(posX + 62, posY);
		printf("%c", 186);
	}
	gotoxy(posX, ++posY);
	printf("%c", 200);
	lineas_estructura(61);
	printf("%c", 188);
}

void crear_menu(char *Titulo, int cantOpciones, char *ColorFondo, char *ColorTexto){
	clrscr();
	Color(ColorFondo,ColorTexto);
	crear_estructura(Titulo,cantOpciones);
}

void Color_Menu_Opciones(char *tablaMenu[], int cantOpciones, int pos, char *ColorFondo, char *ColorTexto, char *ColorFS, char *ColorTS){

	int posX = 7;
	int posY = 5;
	for (int i = 1; i <= cantOpciones; ++i) {
		gotoxy(posX,posY+=2);
		if(i == pos){
			Color(ColorFS,ColorTS);
			printf(" > %s",tablaMenu[i-1]);
		}else{
			Color(ColorFondo,ColorTexto);
			printf(" > %s",tablaMenu[i-1]);
		}
	}
}

/* ===================================================================================
	FUNCION PRINCIPAL
=================================================================================== */
int LeerMenu(char *Titulo, char *tablaMenu[], int cantOpciones, char *ColorFondo, char *ColorTexto, char *ColorFS, char *ColorTS){
	int i = 1;
	char tecla;
	//Se crea la estructura del menu
	crear_menu(Titulo,cantOpciones,ColorFondo,ColorTexto);
	do{
		//Se cambia el color al selector
		Color_Menu_Opciones(tablaMenu,cantOpciones,i,ColorFondo,ColorTexto,ColorFS,ColorTS);
		switch (tecla = getch()){
			case ARR:
				if(i == 1)
					i = cantOpciones;
				else
					i--;
				break;

			case ABA:
				if(i == cantOpciones)
					i = 1;
				else
					i++;
				break;

			case ENTER:
				if(i == cantOpciones)
					//se termina el programa
					exit(0);
				else
					//Retorna a sus colores originales
					Color("Negro","Blanco");
					//Retorna el valor de la seleccion escogida
					return i;
				break;
		}
	} while(tecla != ENTER);
	return i;
}