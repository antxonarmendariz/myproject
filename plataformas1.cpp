#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <typeinfo.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Winuser.h>
#define ancho 70
#define altura 16
#define alto 2
#define gordo 1
char matriz[altura][ancho], personaje[alto][gordo];
void hacercuadrodejuego();
int dibujarmatrizxy();
void cambiarmatrizjug(int h);
int ganador();
void iafacil();
int dosjugadores(int i);
void marcador(int gan1, int gan2);
int tablas();
int contralamaquina(int i);
void textcolor(int ForgC);
void clrscr();
int moverpersonaje(int k);
void crearpersonaje();
void caer();
bool isKeyDown(int vkey);
void dibujarmatrizx();
int aloslados();
int quetecla();
void moverpersonajelados(int k);
void hacermapa();
int main (){
	int i, m, k, l, y;
	char a;
	m = 0;
	k = 0;
	hacercuadrodejuego();
	crearpersonaje();
	hacermapa();
	system("cls");
	do{
		y = dibujarmatrizxy();	
		k = moverpersonaje(y);
		while (k > 0){
			system("cls");
			caer();
			dibujarmatrizx();
			k--;				
		}
		system("cls");	
	}while (m == 0);
	
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
int dibujarmatrizxy(){
	int j, i, y, p;
	i = -1;
	p = 0;
	do{
		i++;
		j = -1;	
		do{
			j++;
			y = 0;
			printf("%c", matriz[i][j]);	
			y = quetecla();	
			if (y != 0){
				p = y;
			}		
		}while(j < ancho-1);
		printf("\n");
	}while(i < altura-1);
	return p;
}
int quetecla(){
	int h;
	h = 0;
	if(isKeyDown(0x26)){ 
		h = 1;
    } else 
	if(isKeyDown(0x25)){ 
        h = 2;
    } else
    if(isKeyDown(0x27)){ 
        h = 3;
    } 
	return h;
}
void crearpersonaje(){
	int i;
	i = 0;
	do{
		i++;
		matriz[11+i][20] = personaje[i][0] = '*';
	}while (i < alto);
}
void caer(){
	int i, j, u, k;
	i = altura - 1;
	u = 0;
	k = 0;
	do{
		i--;
		j = ancho - 1;
		do{
			j--;
			if(matriz[i][j] == '*'){
				matriz[i+1][j] = '*';
				matriz[i][j] = ' ';
				do{
					k = aloslados();	
					u++;
				}while(k == 0 && u < 1000000);				
			}
		} while (j > 1);
	} while (i > 1);
	if (k != 0){
		moverpersonajelados(k);
	}
}
bool isKeyDown(int vkey) {
    return GetKeyState(vkey) < 0;
} 
int aloslados(){
	int i, j;
	if(isKeyDown(0x25)){ 
       i = 2;
    } else
    if(isKeyDown(0x27)){ 
        i = 3;
    } 
    return i;
}
void dibujarmatrizx(){
	int j, i;
	i = -1;
	do{
		i++;
		j = -1;	
		do{
			j++;
			printf("%c", matriz[i][j]);						
		}while(j < ancho-1);
		printf("\n");
		aloslados();
	}while(i < altura-1);
}
int moverpersonaje(int k){
	int i, j, h;
	h = 0;
	switch(k){
		case 1:
		{
			i = 1;
	        do{
				i++;
				j = 1;	
				do{
					j++;
					if(matriz[i][j] == '*'){
					matriz[i-3][j] = '*';
					matriz[i][j] = ' ';	
					}
				}while(j < ancho-1);
			}while(i < altura-1);
			h += 3;
			return h;
		}
		case 2:
		{
			i = 1;
	        do{
				i++;
				j = 1;	
				do{
					j++;
					if(matriz[i][j] == '*'){
					matriz[i][j-1] = '*';
					matriz[i][j] = ' ';	
					}	
				}while(j < ancho-1);
			}while(i < altura-1);
			return h;
		}
		case 3:
		{
			i = altura - 1;
			do{
				i--;
				j = ancho - 1;
				do{
					j--;
					if(matriz[i][j] == '*'){
					matriz[i][j+1] = '*';
					matriz[i][j] = ' ';
					}
				} while (j > 1);
			} while (i > 1);
			return h;
		}
		default:	
		{
			do{
				k = quetecla();	
			}while(k == 0);	
			moverpersonaje(k);	
		}
	}
}
void moverpersonajelados(int k){
	int i, j;
	switch(k){
		case 2:
		{
			i = 1;
	        do{
				i++;
				j = 1;	
				do{
					j++;
					if(matriz[i][j] == '*'){
					matriz[i][j-1] = '*';
					matriz[i][j] = ' ';	
					}	
				}while(j < ancho-1);
			}while(i < altura-1);
		}
		case 3:
		{
			i = altura - 1;
			do{
				i--;
				j = ancho - 1;
				do{
					j--;
					if(matriz[i][j] == '*'){
					matriz[i][j+1] = '*';
					matriz[i][j] = ' ';
					}
				} while (j > 1);
			} while (i > 1);
		}
	}
}
void hacermapa(){
	int i, j;
	i = 0;
	do{
		i++;
		j = 1;
		do{
			if (i == 14){
				matriz[i][j] = '^';
			}
			if (i > 11 && j == 30 && i < 14){
				matriz[i][j] = '<';
			}
			j++;
		}while(j < ancho-2);
	}while(i < altura-2);
	
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

























