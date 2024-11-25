/*
 ============================================================================
 Name        : xSi0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void clear(char a[3][3]){
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			a[i][j] = '_';
		}
	}
}


void afisare(char a[3][3]){
	printf("\n");
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
}


void mutareOm(char a[3][3], char simbol){
	int linia, coloana;
	printf("Alege pozitia:\n");


	do{
		do{
		printf("Linia:\n");
		scanf_s("%d", &linia);
		}while( linia >= 3 || linia < 0);

		do{
		printf("Coloana:\n");
		scanf_s("%d", &coloana);
		}while(linia >= 3 || linia < 0);
	}while(a[linia][coloana] != '_');


	a[linia][coloana] = simbol;



}


void mutarePC(char a[3][3], char simbol){
	int linia, coloana;
	time_t t;



	//daca e spatiu pe locul din mijloc, va pune acolo
	if(a[1][1] == '_'){
		a[1][1] = simbol;
	}

	else {
//linii
		//prima linie
		if((a[0][1] == simbol && a[0][2] == simbol) && a[0][0] == '_'){
			a[0][0] = simbol;
		}
		else if((a[0][0] == simbol && a[0][2] == simbol) && a[0][1] == '_'){
			a[0][1] = simbol;
		}
		else if((a[0][0] == simbol && a[0][1] == simbol) && a[0][2] == '_'){
			a[0][2] = simbol;
		}

		//a doua linie
		else if((a[1][0] == simbol && a[1][1] == simbol) && a[1][2] == '_'){
			a[1][2] = simbol;
		}
		else if((a[1][0] == simbol && a[1][2] == simbol) && a[1][1] == '_'){
			a[1][1] = simbol;
		}
		else if((a[1][1] == simbol && a[1][2] == simbol) && a[1][0] == '_'){
			a[1][0] = simbol;
		}

		//a treia linie
		else if((a[2][0] == simbol && a[2][1] == simbol) && a[2][2] == '_'){
			a[2][2] = simbol;
		}
		else if((a[2][0] == simbol && a[2][2] == simbol) && a[2][1] == '_'){
			a[2][1] = simbol;
		}
		else if((a[2][2] == simbol && a[2][1] == simbol) && a[2][0]){
			a[2][0] = simbol;
		}


//coloane
		//prima coloana
		else if((a[0][0] == simbol && a[1][0] == simbol) && a[2][0] == '_'){
			a[2][0] = simbol;
		}
		else if((a[1][0] == simbol && a[2][0] == simbol) && a[1][0] == '_'){
			a[1][0] = simbol;
		}
		else if((a[1][0] == simbol && a[2][0] == simbol) && a[0][0] == '_'){
			a[0][0] = simbol;
		}

		//a doua coloana
		else if((a[0][1] == simbol && a[1][1] == simbol) && a[2][1] == '_'){
			a[2][1] = simbol;
		}
		else if((a[2][1] == simbol && a[1][1] == simbol) && a[0][1] == '_'){
			a[0][1] = simbol;
		}
		else if((a[0][1] == simbol && a[2][1] == simbol) && a[1][1] == '_'){
			a[1][1] = simbol;
		}

		//a treia coloana
		else if((a[0][2] == simbol && a[1][2] == simbol) && a[2][2] == '_'){
			a[2][2] = simbol;
		}
		else if((a[2][2] == simbol && a[1][2] == simbol) && a[0][2] == '_'){
			a[0][2] = simbol;
		}
		else if((a[0][2] == simbol && a[2][2] == simbol) && a[1][2] == '_'){
			a[1][2] = simbol;
		}


//diagonala principala
		else if((a[0][0] == simbol && a[1][1] == simbol) && a[2][2] == '_'){
			a[2][2] = simbol;
		}
		else if((a[2][2] == simbol && a[1][1] == simbol) && a[0][0] == '_'){
			a[1][1] = simbol;
		}
		else if((a[0][0] == simbol && a[2][2] == simbol) && a[1][1] == '_'){
			a[1][1] = simbol;
		}


//diagonala secundara

		else if((a[0][2] == simbol && a[1][1] == simbol) && a[2][0] == '_'){
			a[2][0] = simbol;
		}
		else if((a[2][0] == simbol && a[1][1] == simbol) && a[0][2] == '_'){
			a[0][2] = simbol;
		}
		else if((a[2][0] == simbol && a[0][2] == simbol) && a[1][1] == '_'){
			a[1][1] = simbol;
		}



//blocare linii
		//prima linie
		else if(( (a[0][0] != '_' && a[0][2] != '_') && (a[0][0] != simbol && a[0][2] != simbol)) && a[0][1] == '_'){
			a[0][1] = simbol;
		}
		else if(( (a[0][1] != '_' && a[0][2] != '_') && (a[0][1] != simbol && a[0][2] != simbol)) && a[0][0] == '_'){
			a[0][0] = simbol;
		}
		else if( ((a[0][0] != '_' && a[0][1] != '_') &&(a[0][0] != simbol && a[0][1] != simbol)) && a[0][2] == '_'){
			a[0][2] = simbol;
		}

		//a doua linie
		else if( ((a[1][0] != '_' && a[1][2] != '_') && (a[1][0] != simbol && a[1][2] != simbol)) && a[1][1] == '_'){
			a[1][1] = simbol;
		}
		else if( ((a[1][1] != '_' && a[1][2] != '_') && (a[1][1] != simbol && a[1][2] != simbol)) && a[1][0] == '_'){
			a[1][0] = simbol;
		}
		else if( ((a[1][0] != '_' && a[1][1] != '_') && (a[1][0] != simbol && a[1][1] != simbol)) && a[1][2] == '_'){
			a[1][2] = simbol;
		}

//a treia linie
		else if( ((a[2][0] != '_' && a[2][1] != '_') &&(a[2][0] != simbol && a[2][1] != simbol)) && a[2][2] == '_'){
			a[2][2] = simbol;
		}
		else if( ((a[2][1] != '_' && a[2][1] != '_') && (a[2][1] != simbol && a[2][1] != simbol)) && a[2][0] == '_'){
			a[2][0] = simbol;
		}
		else if( ((a[2][0] != '_' && a[2][2] != '_') && (a[2][0] != simbol && a[2][2] != simbol)) && a[2][1] == '_'){
			a[2][1] = simbol;
		}

//prima coloana
		else if( ((a[0][0] != '_' && a[1][0] != '_') && (a[0][0] != simbol && a[1][0] != simbol)) && a[2][0] == '_'){
			a[2][0] = simbol;
		}
		else if( ((a[1][0] != '_' && a[2][0] != '_') && (a[1][0] != simbol && a[2][0] != simbol)) && a[1][0] == '_'){
			a[1][0] = simbol;
		}
		else if( ((a[1][0] != '_' && a[2][0] != '_') && (a[1][0] != simbol && a[2][0] != simbol)) && a[0][0] == '_'){
			a[0][0] = simbol;
		}

//a doua coloana
		else if( ((a[0][1] != '_' && a[1][1] != '_') && (a[0][1] != simbol && a[1][1] != simbol)) && a[2][1] == '_'){
			a[2][1] = simbol;
		}
		else if( ((a[2][1] != '_' && a[1][1] != '_') && (a[2][1] != simbol && a[1][1] != simbol)) && a[0][1] == '_'){
			a[0][1] = simbol;
		}
		else if( ((a[0][1] != '_' && a[2][1] != '_') && (a[0][1] != simbol && a[2][1] != simbol)) && a[1][1] == '_'){
			a[1][1] = simbol;
		}

//a treia coloana
		else if( ((a[0][2] != '_' && a[1][2] != '_') && (a[0][2] != simbol && a[1][2] != simbol)) && a[2][2] == '_'){
			a[2][2] = simbol;
		}
		else if( ((a[2][2] != '_' && a[1][2] != '_') && (a[2][2] != simbol && a[1][2] != simbol)) && a[0][2] == '_'){
			a[0][2] = simbol;
		}
		else if( ((a[0][2] != '_' && a[2][2] != '_') && (a[0][2] != simbol && a[2][2] != simbol)) && a[1][2] == '_'){
			a[1][2] = simbol;
		}

//diagonala principala
		else if( ((a[0][0] != '_' && a[1][1] != '_') && (a[0][0] != simbol && a[1][1] != simbol)) && a[2][2] == '_'){
			a[2][2] = simbol;
		}
		else if( ((a[2][2] != '_' && a[1][1] != '_') && (a[2][2] != simbol && a[1][1] != simbol)) && a[0][0] == '_'){
			a[1][1] = simbol;
		}
		else if( ((a[0][0] != '_' && a[2][2] != '_') && (a[0][0] != simbol && a[2][2] != simbol)) && a[1][1] == '_'){
			a[1][1] = simbol;
		}

//diagonala secundara

		else if( ((a[0][2] != '_' && a[1][1] != '_') && (a[0][2] != simbol && a[1][1] != simbol)) && a[2][0] == '_'){
			a[2][0] = simbol;
		}
		else if( ((a[2][0] != '_' && a[1][1] != '_') && (a[2][0] != simbol && a[1][1] != simbol)) && a[0][2] == '_'){
			a[0][2] = simbol;
		}
		else if( ((a[2][0] != '_' && a[0][2] != '_') && (a[2][0] != simbol && a[0][2] != simbol)) && a[1][1] == '_'){
			a[1][1] = simbol;
		}


		//coltul din stanga sus
		else if(a[0][0] == '_'){
			a[0][0] = simbol;
		}
		//coltul din dreapta sus
		else if(a[0][2] == '_'){
			a[0][2] = simbol;
		}
		//coltul din stanga jos
		else if(a[2][0] == '_'){
			a[2][0] = simbol;
		}
		//coltul din dreapta jos
		else if(a[2][2] == '_'){
			a[2][2] = simbol;
		}

		//default:
		else{
		do{
			srand((unsigned) time(&t));
			linia = rand() % 3;
			coloana = rand() % 3;
			}while( a[linia][coloana] != '_');
		 a[linia][coloana] = simbol;
		}
	}

}


int final(char a[3][3], int flag){
	int diagonala1X = 0;
	int diagonala10 = 0;
	int diagonala2X = 0;
	int diagonala20 = 0;
	int linieX = 0;
	int linie0 = 0;
	int coloanaX = 0;
	int coloana0 = 0;
	int spatii = 0;

	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			if(i == j){
				if(a[i][j] == 'x'){
					diagonala1X++;
				}
				if(a[i][j] == '0'){
					diagonala10++;
				}
			}
			if( (i+j) == 2 ){
				if(a[i][j] == 'x'){
					diagonala2X++;
				}
				if(a[i][j] == '0'){
					diagonala20++;
				}
			}
		}
	}
	if(diagonala1X == 3){
		flag = 1;
		printf("\nX-ul a castigat!");
		return flag;
	}
	if(diagonala10 == 3){
		flag = 1;
		printf("\n0 a castigat!");
		return flag;
	}

	if(diagonala2X == 3){
		flag = 1;
		printf("\nX-ul a castigat!");
		return flag;
	}
	if(diagonala20 == 3){
		flag = 1;
		printf("\n0 a castigat!");
		return flag;
	}
///////////////prima coloana
	if(a[0][0] == 'x'){
		linieX++;
	}
	if(a[1][0] == 'x'){
		linieX++;
	}
	if(a[2][0] == 'x'){
		linieX++;
	}
	if(a[0][0] == '0'){
		linie0++;
	}
	if(a[1][0] == '0'){
		linie0++;
	}
	if(a[2][0] == '0'){
		linie0++;
	}
	if(linieX == 3){
		flag = 1;
		printf("\nX-ul a castigat!");
		return flag;
	}
	if(linie0 == 3){
		flag = 1;
		printf("\n0 a castigat!");
		return flag;
	}
	linieX = 0;
	linie0 = 0;

//////a doua coloana
	if(a[0][1] == 'x'){
		linieX++;
	}
	if(a[1][1] == 'x'){
		linieX++;
	}
	if(a[2][1] == 'x'){
		linieX++;
	}
	if(a[0][1] == '0'){
		linie0++;
	}
	if(a[1][1] == '0'){
		linie0++;
	}
	if(a[2][1] == '0'){
		linie0++;
	}
	if(linieX == 3){
		flag = 1;
		printf("\nX-ul a castigat!");
		return flag;
	}
	if(linie0 == 3){
		flag = 1;
		printf("\n0 a castigat!");
		return flag;
	}
	linieX = 0;
	linie0 = 0;

	/////////////a treia coloana
	if(a[0][2] == 'x'){
		linieX++;
	}
	if(a[1][2] == 'x'){
		linieX++;
	}
	if(a[2][2] == 'x'){
		linieX++;
	}
	if(a[0][2] == '0'){
		linie0++;
	}
	if(a[1][2] == '0'){
		linie0++;
	}
	if(a[2][2] == '0'){
		linie0++;
	}
	if(linieX == 3){
		flag = 1;
		printf("\nX-ul a castigat!");
		return flag;
	}
	if(linie0 == 3){
		flag = 1;
		printf("\n0 a castigat!");
		return flag;
	}
	linieX = 0;
	linie0 = 0;

	////
	if(a[0][0] == 'x'){
		coloanaX++;
	}
	if(a[0][1] == 'x'){
		coloanaX++;
	}
	if(a[0][2] == 'x'){
		coloanaX++;
	}
	if(a[0][0] == '0'){
		coloana0++;
	}
	if(a[0][1] == '0'){
		coloana0++;
	}
	if(a[0][2] == '0'){
		coloana0++;
	}
	if(coloanaX == 3){
		flag = 1;
		printf("\nX-ul a castigat!");
		return flag;
	}
	if(coloana0 == 3){
		flag = 1;
		printf("\n0 a castigat!");
		return flag;
	}
	coloanaX = 0;
	coloana0 = 0;

	if(a[1][0] == 'x'){
		coloanaX++;
	}
	if(a[1][1] == 'x'){
		coloanaX++;
	}
	if(a[1][2] == 'x'){
		coloanaX++;
	}
	if(a[1][0] == '0'){
		coloana0++;
	}
	if(a[1][1] == '0'){
		coloana0++;
	}
	if(a[1][2] == '0'){
		coloana0++;
	}
	if(coloanaX == 3){
		flag = 1;
		printf("\nX-ul a castigat!");
		return flag;
	}
	if(coloana0 == 3){
		flag = 1;
		printf("\n0 a castigat!");
		return flag;
	}
	coloanaX = 0;
	coloana0 = 0;

	if(a[2][0] == 'x'){
		coloanaX++;
	}
	if(a[2][1] == 'x'){
		coloanaX++;
	}
	if(a[2][2] == 'x'){
		coloanaX++;
	}
	if(a[2][0] == '0'){
		coloana0++;
	}
	if(a[2][1] == '0'){
		coloana0++;
	}
	if(a[2][2] == '0'){
		coloana0++;
	}
	if(coloanaX == 3){
		flag = 1;
		printf("\nX-ul a castigat!");
		return flag;
	}
	if(coloana0 == 3){
		flag = 1;
		printf("\n0 a castigat!");
		return flag;

	}
	coloanaX = 0;
	coloana0 = 0;

	spatii = 0;
	for(int i = 0; i<3;i++){
		for(int j = 0; j<3; j++){
			if(a[i][j] == '_'){
				spatii++;
			}
		}
	}
	if(spatii == 0){
		printf("Remiza!");
		flag = 1;
		return flag;
	}

	return 0;

}


int main(void) {
	char a[3][3];
	char x = 'x';
	char o = '0';
	int flag = 0;
	int inceput;
	setbuf(stdout, NULL);

	clear(a);
	afisare(a);

	//1) Cine incepe?
	do{
	printf("\nCine incepe? Tu(1) sau PC-ul(2): ");
	scanf_s("%d", &inceput);
	}while(inceput != 1 && inceput != 2);



	//Inceputul jocului
	if(inceput == 1){
		while(flag != 1){
			mutareOm(a, x);
//			fflush(stdin);
			afisare(a);
			flag = final(a, flag);
			if(flag == 1){
				break;
			}

			mutarePC(a, o);
//			fflush(stdin);
			afisare(a);
			flag = final(a, flag);
			if(flag == 1){
				break;
			}

		}
	}

	if(inceput == 2){
		while(flag != 1){
			mutarePC(a, x);
//			fflush(stdin);
			afisare(a);
			flag = final(a, flag);
			if(flag == 1)
				break;
			mutareOm(a, o);
//			fflush(stdin);
			afisare(a);
			flag = final(a, flag);
			if(flag == 1)
				break;
		}
	}


	//
	return 0;
}
