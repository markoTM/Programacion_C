#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

int porcentaje_carga(int &carga){
      carga += 5;
	return carga;
}

void funcion_cargando(){
	int posX = 40;
	int posY = 12;
   int carga = 0;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),192);
   system("cls");
   gotoxy(posX-1,posY);printf("%d%",0); Sleep(600);
   gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
   for(int i=0;i<2;i++){
      gotoxy(posX,posY-3);printf("%c",42); 		Sleep(300);		gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
     		gotoxy(posX+3,posY-2);printf("%c",42); Sleep(300);    gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
         gotoxy(posX+1,posY-3); printf("\b \b"); Sleep(300);
		gotoxy(posX+4,posY);printf("%c",42); 		Sleep(300);  	gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
      gotoxy(posX+4,posY-2); printf("\b \b"); Sleep(300);
      	gotoxy(posX+3,posY+2);printf("%c",42); Sleep(300);  	gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
         gotoxy(posX+5,posY); printf("\b \b"); Sleep(300);
      gotoxy(posX,posY+3);printf("%c",42);		Sleep(300);  	gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
      gotoxy(posX+4,posY+2); printf("\b \b"); Sleep(300);
      	gotoxy(posX-3,posY+2);printf("%c",42);	Sleep(300);    gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
         gotoxy(posX+1,posY+3); printf("\b \b"); Sleep(300);
      gotoxy(posX-4,posY);printf("%c",42);		Sleep(300); 	gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
      gotoxy(posX-2,posY+2); printf("\b \b"); Sleep(300);
      	gotoxy(posX-3,posY-2);printf("%c",42);	Sleep(300);  	gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
         gotoxy(posX-3,posY); printf("\b \b"); Sleep(300);
      																			gotoxy(posX-2,posY-2); printf("\b \b"); Sleep(300);
   	if(i == 1){
      	gotoxy(posX,posY-3);printf("%c",42); 		Sleep(300);		gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
     			gotoxy(posX+3,posY-2);printf("%c",42); Sleep(300);    gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
         	gotoxy(posX+1,posY-3); printf("\b \b"); Sleep(300);
			gotoxy(posX+4,posY);printf("%c",42); 		Sleep(300);  	gotoxy(posX-1,posY);printf("%d%",porcentaje_carga(carga));
      	gotoxy(posX+4,posY-2); printf("\b \b"); Sleep(300);
      	gotoxy(posX+5,posY); printf("\b \b"); Sleep(300);
      }
   }
}


void funcion_apagado(){
   //system("SHUTDOWN -r -t 5");
}

void funcion_estructura(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),31);
   system("cls");
   printf("Se ha encontrado un problema y windows ha sido apagado para evitar daños al\nequipo.");
   printf("\n\nSi esa es la primera vez que ve esta pantalla de error de\ndetencion, reinicie su equipo, si esta pantalla aparece otra \nvez, siga los siguientes pasos:");
	printf("\n\nCompruebe que tiene el espacio en disco adecuado, si un \ncontrolador esta identificando en el mensaje de detencion, deshabilita el\ncontrolador o pregunte al fabricante al fabricante por controladores actualizados,\nPruebe a cambiar los adaptadores de video");
	printf("\n\nInformacion tecnica: ");
   printf("\n\n*** STOP: 0x0000008E (0xC0000005,0x8055159A, 0xAA472964, 0x99999999)");
   printf("\n\nEmpezando el volcado de memoria fisica\nvolcando memoria fisica al disco: 14");
   printf("\n\nEl equipo se reiniciara .. :(:(\n\n");
   funcion_apagado();
}

void main(){
	funcion_cargando();
   funcion_estructura();
	getch();
}
