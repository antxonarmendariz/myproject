#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <typeinfo.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <dos.h>
#include <dir.h>
#define altura 3
#define ancho 35
char matriz[altura][ancho];
void hacermatriz();
void dibujarmatriz();
void cambiarmatrizjug(int h);
int ganador();
void iafacil();
int dosjugadores(int i);
void marcador(int gan1, int gan2);
int tablas();
int contralamaquina(int i);
void textcolor(int ForgC);
int n;
int main (){
	int i, ganar, ganadas1, ganadas2, partidas, j, h, g, nulo;
	hacermatriz();
	i = 0;
	srand(time(NULL));
	printf("elige a que jugar:{(1)dos jugadores, (2)ordenadorfacil(1 solo jugador)\t");
	scanf("%i", &i);
	switch(i){
		case 1:
		{
			printf("a cuanto quereis jugar?\t");
			scanf("%i", &partidas);
			ganadas1 = 0;
			ganadas2 = 0;
			j = 0;
			marcador(ganadas1, ganadas2);
			do{
				n = 0;
				hacermatriz();
				j++;
				h = j % 2;
				if (h == 0){
					g = 1;
				}
				else{
					g = 0;
				}
				ganar = dosjugadores(g);
				system("cls");
				if(ganar == 1){
					ganadas1++;
					printf("\t\t\tjugador 1 gana\n");
				}
				if(ganar == 2){
					ganadas2++;
					printf("\t\t\tjugador 2 gana\n");
				}
				if(ganar == 0){
					printf("\t\t\ttablas\n");
				}				
				marcador(ganadas1, ganadas2);
				dibujarmatriz();
				printf("\n\n\nmeter cualquier numero para continuar");
				scanf("%i", &nulo);
			}while(partidas != ganadas1 && partidas != ganadas2);
			break;	
		}
		case 2:
		{
			printf("a cuanto quereis jugar?\t");
			scanf("%i", &partidas);
			ganadas1 = 0;
			ganadas2 = 0;
			j = 0;
			marcador(ganadas1, ganadas2);
			do{
				n = 0;
				hacermatriz();
				j++;
				h = j % 2;
				if (h == 0){
					g = 1;
				}
				else{
					g = 0;
				}
				ganar = contralamaquina(g);
				system("cls");
				if(ganar == 1){
					ganadas1++;
					printf("\t\t\tjugador 1 gana\n");
				}
				if(ganar == 2){
					ganadas2++;
					printf("\t\t\tjugador 2 gana\n");
				}
				if(ganar == 0){
					printf("\t\t\ttablas\n");
				}				
				marcador(ganadas1, ganadas2);
				dibujarmatriz();
				printf("\n\n\nmeter cualquier numero para continuar");
				scanf("%i", &nulo);
			}while(partidas != ganadas1 && partidas != ganadas2);
			break;
		}
		
	}
	return 0;
} 
void hacermatriz(){
	int i, j, h;
	i = 0;
	h = 48;
	do{
		i++;
		j = ancho-3;
		do{
			j++;
			h++;
			matriz[i][j] = h;
		}while(j < ancho);
	}while(i < altura);
}
void dibujarmatriz(){
int j, i, y;

	i = 0;
	do{
		i++;
		j = 0;	
		do{
			j++;
			switch(n){
				case 1:
				{
					if(matriz[i][j] == 'X' && matriz[i+1][j] == 'X' && matriz[i+2][j] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-1][j] == 'X' && matriz[i][j] == 'X' && matriz[i+1][j] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-2][j] == 'X' && matriz[i-1][j] == 'X' && matriz[i][j] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else{
						textcolor(8);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					break;
				}
				case 2:
				{
					if(matriz[i][j] == 'X' && matriz[i][j+1] == 'X' && matriz[i][j+2] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i][j-1] == 'X' && matriz[i][j] == 'X' && matriz[i][j+1] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i][j-2] == 'X' && matriz[i][j-1] == 'X' && matriz[i][j] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else{
						textcolor(8);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					break;
				}
				case 3:
				{
					if(matriz[i][j] == 'X' && matriz[i+1][j+1] == 'X' && matriz[i+2][j+2] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-1][j-1] == 'X' && matriz[i][j] == 'X' && matriz[i+1][j+1] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-2][j-2] == 'X' && matriz[i-1][j-1] == 'X' && matriz[i][j] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else{
						textcolor(8);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}				
					break;
				}
				case 4:
				{
					if(matriz[i][j] == 'X' && matriz[i+1][j-1] == 'X' && matriz[i+2][j-2] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-1][j+1] == 'X' && matriz[i][j] == 'X' && matriz[i+1][j-1] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-2][j+2] == 'X' && matriz[i-1][j+1] == 'X' && matriz[i][j] == 'X'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else{
						textcolor(8);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}							
					break;
				}
				case 5:
				{
					if(matriz[i][j] == 'O' && matriz[i+1][j] == 'O' && matriz[i+2][j] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-1][j] == 'O' && matriz[i][j] == 'O' && matriz[i+1][j] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-2][j] == 'O' && matriz[i-1][j] == 'O' && matriz[i][j] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else{
						textcolor(8);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}				
					break;
				}
				case 6:
				{
					y = 0;
					if(matriz[i][j] == 'O' && matriz[i][j+1] == 'O' && matriz[i][j+2] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
						y = 1;
					}
					else if(matriz[i][j-1] == 'O' && matriz[i][j] == 'O' && matriz[i][j+1] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
						y = 1;
					}
					else if(matriz[i][j-2] == 'O' && matriz[i][j-1] == 'O' && matriz[i][j] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
						y = 1;
					}
					if (y != 1){
						textcolor(8);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}	
					break;				
				}
				case 7:
				{
					if(matriz[i][j] == 'O' && matriz[i+1][j+1] == 'O' && matriz[i+2][j+2] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-1][j-1] == 'O' && matriz[i][j] == 'O' && matriz[i+1][j+1] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-2][j-2] == 'O' && matriz[i-1][j-1] == 'O' && matriz[i][j] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else{
						if(j == 3 && i == 3){
							printf(" ");
						}
						textcolor(8);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}				
					break;
				}
				case 8:
				{
					if(matriz[i][j] == 'O' && matriz[i+1][j-1] == 'O' && matriz[i+2][j-2] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-1][j+1] == 'O' && matriz[i][j] == 'O' && matriz[i+1][j-1] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else if(matriz[i-2][j+2] == 'O' && matriz[i-1][j+1] == 'O' && matriz[i][j] == 'O'){
						textcolor(2);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					else{
						textcolor(8);
						if(j == 3 && i == 3){
							printf("  ");
						}
						printf("%c",matriz[i][j]);
						textcolor(7);
					}				
					break;
				}
				default:
				{
					if(matriz[i][j] == 'X'){
						textcolor(9);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					if(matriz[i][j] == 'O'){
						textcolor(6);
						printf("%c",matriz[i][j]);
						textcolor(7);
					}
					if(matriz[i][j] != 'X' && matriz[i][j] != 'O'){
						printf("%c",matriz[i][j]);
					}
					break;
				}
			}						
			if( j > ancho-4){
				printf("|");		
			}
		}while(j < ancho);
		printf("\n");
		if(i != altura){
			printf("\t\t\t\t");
			printf("-------");
			printf("\n");		
		}
	}while(i < altura);
}
void cambiarmatrizjug(int h){
	int i, j, encontrado, p, r;
	char cambio;
	encontrado = 0;
	do{
		scanf("%c", &cambio);
		r = cambio;
		if((r < 58 && r > 48 )){
			i = -1;
			do{
				i++;
				j = ancho-3;
				do{
					j++;
					p = matriz[i][j]; 
					if(p == r){
						if(h == 0){
							matriz[i][j] = 'X';
							encontrado = 1;
						}
						if(h != 0){
							matriz[i][j] = 'O';
							encontrado = 1;
						}
					}
				}while(matriz[i][j] != r && j < ancho);
			}while(matriz[i][j] != r && i < altura);
		}	
	}while(encontrado == 0);
}
int ganador(){
	int i, j, h;
	h = 0;
	i = -1;
	do{
		i++;
		j = -1;
		do{
			j++;
			if(matriz[i][j] == 'X' && matriz[i+1][j] == 'X' && matriz[i+2][j] == 'X'){
				h = 1;
				n = 1;
			}
			if(matriz[i][j] == 'X' && matriz[i][j+1] == 'X' && matriz[i][j+2] == 'X'){
				h = 1;
				n = 2;
			}
			if(matriz[i][ancho-2] == 'X' && matriz[i+1][ancho-1] == 'X' && matriz[i+2][ancho] == 'X'){
				h = 1;
				n = 3;
			}
			if(matriz[i][ancho] == 'X' && matriz[i+1][ancho-1] == 'X' && matriz[i+2][ancho-2] == 'X'){
				h = 1;
				n = 4;
			}
			if(matriz[i][j] == 'O' && matriz[i+1][j] == 'O' && matriz[i+2][j] == 'O'){
				h = 2;
				n = 5;
			}
			if(matriz[i][j] == 'O' && matriz[i][j+1] == 'O' && matriz[i][j+2] == 'O'){
				h = 2;
				n = 6;
			}
			if(matriz[i][ancho-2] == 'O' && matriz[i+1][ancho-1] == 'O' && matriz[i+2][ancho] == 'O'){
				h = 2;
				n = 7;
			}
			if(matriz[i][ancho] == 'O' && matriz[i+1][ancho-1] == 'O' && matriz[i+2][ancho-2] == 'O'){
				h = 2;
				n = 8;
			}
		}while(j < ancho);
	}while(i < altura);
	return h;
}
void iafacil(){
	int i, j, r, encontrado, p, k;
	char h;
	h = 48;
	do{
		k = rand() % 9;
		r = h + k;
		encontrado = 0;
		if(r < 58 && r > 48 ){
			i = -1;
			do{
				i++;
				j = ancho-3;
				do{
					j++;
					p = matriz[i][j]; 
					if(p == r){
						matriz[i][j] = 'O';
						encontrado = 1;
					}
				}while(matriz[i][j] != r && j < ancho);
			}while(matriz[i][j] != r && i < altura);
		}	
	}while(encontrado == 0);
}
int dosjugadores(int i){
	int k, win, ta, n;
	n = 0;
	do{
		system("cls");
		dibujarmatriz();
		i++;
		k = i % 2;
		printf("\n\n\ndame el numero en el que quieres poner la ficha:	");
		cambiarmatrizjug(k);
		win = ganador();
		ta = tablas();
	}while(win == 0 && ta != 9);
	system("cls");
	dibujarmatriz();	
	return win;
}
void marcador(int gan1, int gan2){
	int i, j;
	char h1[18];
	h1[0] = 'j', h1[1] = 'u', h1[2] = 'g', h1[3] = 'a', h1[4] = 'd', h1[5] = 'o', h1[6] = 'r', h1[7] = '1', h1[8] = ' ';
	h1 [9]= 'j', h1[10] = 'u', h1[11] = 'g', h1[12] = 'a', h1[13] = 'd', h1[14] = 'o', h1[15] = 'r', h1[16] = '2';
	j = 1;
	do{
		j++;
		matriz[1][j] = h1[j-2];
	}while(j < 18);
	matriz[2][5] = gan1 + 48;
	matriz[2][14] = gan2 + 48;
}
int tablas(){
	int i, j, h;
	i = 0;
	h = 0;
	do{
		i++;
		j = ancho-3;
		do{
			j++;
			if(matriz[i][j] == 'X' || matriz[i][j] == 'O'){
				h++;
			}
		}while(j < ancho);
	}while(i < altura);
	return h;
}
int contralamaquina(int i){
	int h, win, ta, n;
	n = 0;
	do{
		system("cls");
		dibujarmatriz();
		i++;
		h = i % 2;
		printf("\n\n\ndame el numero en el que quieres poner la ficha:	");
		if(h != 0){
			cambiarmatrizjug(0);
		}
		else{
			iafacil();
		}
		win = ganador();
		ta = tablas();
	}while(win == 0 && ta != 9);
	system("cls");
	dibujarmatriz();	
	return win;
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





































































