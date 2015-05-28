/* ===================================================================================
   basicas.h - librería C++  -- by MarkTM

   Contiene las siguientes funciones para usar :

	====== Funciones para mostrar mensajes ======
   	- void mensaje(char cadena);
   	- void mensaje_ok(char cadena);
   	- void mensaje_error(char cadena);

 	====== Funciones para Leer ======
   	- void leer_entero_valido(char msje,int min, int max, char msjeError, int variable);
   	- void leer_real_valido(char msje,float min, float max, char msjeError, float variable);
	- void leer_double_valido(char msje,double min, double max, char msjeError, double variable);
	- void leer_cadena(char msje, char cadena, int maxCaracteres);
	- void leer_cadena_valida(char msje, char cadena, int max);
	- void leer_cadena_numerica(char msje, char cadena, int max);

	====== Funciones para imprimir ======
   	- void escribir_entero(char msje, int variable);
	- void escribir_real(char msje, int variable);
	- void escribir_double(char msje, double variable);
	- void escribir_cadena(char msje, char cadena);

	====== Funciones para presentacion ======
	- int elegir_opcion(char msje, char tablaOpciones, int cantOpciones, char msjeError);
=================================================================================== */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/* ===================================================================================
   FUNCIONES BASICAS
=================================================================================== */

void prefix_lee(){
	printf("\n < ");
}

void prefix_escribir(){
	printf("\n > ");
}

void mensaje(char *msje){
	printf("%s: ",msje);
}

void mensaje_ok(char *msje){
	printf("\n\tExito -> %s\n",msje);
}

void mensaje_error(char *msje){
	printf("\n\tError -> %s\n",msje);
}


/* ===================================================================================
   FUNCIONES CON ENTEROS
=================================================================================== */

void leer_entero(char *msje, int &entero){
	prefix_lee();
	mensaje(msje);
	scanf("%d",&entero);
}

void leer_entero_valido(char *msje,int min, int max, char *msjeError, int &entero){
	do{
		leer_entero(msje,entero);
		if(entero < min || entero > max){
			mensaje_error(msjeError);
		}
	}while(entero < min || entero > max);
}

void escribir_entero(char *msje, int entero){
	prefix_escribir();
	printf("%s: %d",msje,entero);
}

/*====================================================================================
	FUNCIONES CON REALES
=================================================================================== */

void leer_real(char *msje, float &real){
	prefix_lee();
	mensaje(msje);
	scanf("%.2f",&real);
}

void leer_real_valido(char *msje,float min, float max, char *msjeError, float &real){
	do{
		leer_real(msje,real);
		if(real < min || real > max){
			mensaje_error(msjeError);
		}
	}while(real < min || real > max);
}

void escribir_real(char *msje, int real){
	prefix_escribir();
	printf("%s: %.2f",msje,real);
}

/*====================================================================================
	FUNCIONES CON DOUBLE
=================================================================================== */

void leer_double(char *msje, double &real){
	prefix_lee();
	mensaje(msje);
	scanf("%lf",&real);
}

void leer_double_valido(char *msje,double min, double max, char *msjeError, double &real){
	do{
		leer_double(msje,real);
		if(real < min || real > max){
			mensaje_error(msjeError);
		}
	}while(real < min || real > max);
}

void escribir_double(char *msje, double real){
	prefix_escribir();
	printf("%s: %lf",msje,real);
}

/*====================================================================================
	FUNCIONES CON CADENA
=================================================================================== */

void leer_cadena(char *msje, char cadena[], int max){
	int repeticiones;
	int maxCaracteres;
	do{
		prefix_lee();
		mensaje(msje);
		fflush(stdin);
		gets(cadena);
		maxCaracteres = strlen(cadena);
		if(maxCaracteres < 1 || maxCaracteres > (max-1))
			mensaje_error("No ingreso caracteres o sobre paso el limite");
	} while (maxCaracteres < 1 || maxCaracteres > (max-1));
}

void leer_cadena_valida(char *msje, char cadena[] , int max){
	int repeticiones;
	int maxCaracteres;
	do{
		repeticiones = 0;
		leer_cadena(msje,cadena,max);
		maxCaracteres = strlen(cadena);
		for (int i = 0; i < maxCaracteres; ++i){
			if (isalpha(cadena[i]) || cadena[i] == ' ')
				repeticiones++;
		}
		if (repeticiones != maxCaracteres)
			mensaje_error("Solo acepta letras");
	}while(repeticiones != maxCaracteres);
}

void leer_cadena_numerica(char *msje, char cadena[], int max){
	int repeticiones;
	int maxCaracteres;
	do{
		repeticiones = 0;
		leer_cadena(msje,cadena,max);
		maxCaracteres = strlen(cadena);
		for (int i = 0; i < maxCaracteres; ++i){
			if (isdigit(cadena[i]))
				repeticiones++;
		}
		if (repeticiones != maxCaracteres)
			mensaje_error("Solo acepta numeros");
	}while(repeticiones != maxCaracteres);
}

void escribir_cadena(char *msje, char cadena[]){
	prefix_escribir();
	printf("%s: %s",msje,cadena);
}

/*====================================================================================
	FUNCIONES DE PRESENTACION
=================================================================================== */

int elegir_opcion(char *msje, char *tablaOpciones[], int cantOpciones, char *msjeError){
	int op;
	for (int i = 0; i < cantOpciones; ++i){
		printf("\n [%d] %s",i+1,tablaOpciones[i]);
	}
	leer_entero_valido(msje,1,cantOpciones,msjeError,op);
	return op;
}

holiwwi