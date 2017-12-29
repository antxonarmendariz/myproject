#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <typeinfo.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define ancho 70
#define altura 16
char matriz[altura][ancho];
void hacercuadrodejuego();
void dibujarmatriz();
void cambiarmatrizjug(int h);
int ganador();
void iafacil();
int dosjugadores(int i);
void marcador(int gan1, int gan2);
int tablas();
int contralamaquina(int i);
void textcolor(int ForgC);
void clrscr();
int main (){
	int i;
	i = -3;
	hacercuadrodejuego();
	do{
		dibujarmatriz();
		system("cls");
		i++;
	}while (i != 0);
	
	return 0;
} 
void hacercuadrodejuego(){
	int i, j, h;
	i = -1;
	do{
		i++;
		j = 0;
		do{
			if (i > 0 && i < altura-1){
				matriz[i][j] = '|';
				j = j + ancho - 3;
			}
			else{
				matriz[i][j] = '-';
			}
			j++;
		}while(j < ancho-1);
	}while(i < altura-1);
}
void dibujarmatriz(){
int j, i, y;

	i = -1;
	do{
		i++;
		j = -1;	
		do{
			j++;
			printf("%c", matriz[i][j]);						
		}while(j < ancho-1);
		printf("\n");
	}while(i < altura-1);
}

void textcolor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

























