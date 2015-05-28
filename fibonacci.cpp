/*Programa que lea un numero y verificar si pertenece a la serie de Fibonacci*/

#include <stdio.h>
#include <conio.h>

void main(){
	int num;
	int num1 = 0, num2 = 1, num3 = 0;
	int sw = 0;
	do{
		printf("\nIngresa numero: ");
		scanf("%d",&num);
		if (num < 1) printf("\nNumero no valido");
	}while(num < 1);

	int i = 0;
	while (i < num && sw == 0) {
		num3 = num1 + num2;
		if(num3 == num){
			printf("\nEl %d le pertenece a la serie de fibonacci",num);
			sw = 1;
		}
		num1 = num2;
		num2 = num3;
		i++;
	};

	if(sw == 0)
		printf("\nEl %d no le pertenece a la serie de fibonacci",num);

	getch();
}