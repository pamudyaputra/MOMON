#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

/* MAIN MENU */
void playGame();
void scoreHistory();
void highScore();
void help();
void credit();

/* MAP */
void printMenu();
void gotoxy(int x, int y);
void printTitle(int i, int j);

/* PLAYGAME */
//void singlePlayer();
//void multiPlayer();


typedef struct {
	char date[26];
	char time[10];
	char name[10];
	char enter;
	int score;
}score;

typedef struct {
	char date[26];
	char time[10];
	char name[10];
	char enter;
	int score;
} high;

/* ALGORITMA */
int main() {
	int option;
	
	do {
		system("mode 131, 31");
		system("cls");
		printMenu();
		gotoxy(68, 22); scanf("%d", &option);
		
		if (option == 1)
		{
			//PlayGame();
		}
		else if (option == 2)
		{
			highScore();
		}
		else if (option == 3)
		{
			scoreHistory();
		}
		else if (option == 4)
		{
			help();
		}
		else if (option == 5)
		{
			credit();
		}
	}
	while (option != 6);
	
}

/*BODY PROCEDURE AND FUNCTION MAIN MENU */
void help() {
	system("mode 130, 90");
	FILE *fhelp;
	fhelp = fopen("Help.txt", "r");
	char help = getc(fhelp);
	while (help != EOF){
		putchar(help);
		help = getc(fhelp);
	}
	fclose(fhelp);
	printf ("\n");
	system ("pause");
}

void scoreHistory() {
	
	FILE *fscore;
	int iscore = 1;
	int i, j;
	score skor;
	
	system("cls");
	if ((fscore = fopen("HighScore.txt", "rb")) == NULL) {
		printf("File tidak dapat dibuka\n");
		exit(1);
	}
	gotoxy(32, 3);
	for (i = 0; i < 3; i++) {
		switch (i) {
			case 0:
				printf ("%c", 201); break;
			case 1:
				for (j = 0; j < 63; j++) {
					printf ("%c", 205);
				} break;
			case 2:
				printf ("%c", 187); break;
		}
	}
	gotoxy(32, 4)	; printf("%c                                                               %c\n", 186, 186);
	gotoxy(54, 4); printf ("MONOPOLY SCORE HISTORY");
	gotoxy(32, 5); for (i = 0; i < 65; i++) {
		switch (i) {
			case 0:
				printf ("%c", 204); break;
			case 7:
				printf("%c", 203); break;
			case 30:
				printf("%c", 203); break;
			case 40:
				printf("%c", 203); break;
			case 64:
				printf("%c", 185); break;
			default :
				printf("%c", 205); break;
		}

	}
	gotoxy(32, 6); printf ("%c  NO  %c     DATES & TIMES    %c  NAMES\t%c  \t SCORES\t\t%c\n",186,186,186,186,186);
	gotoxy(32, 7); for (i = 0; i < 65; i++) {
		switch (i) {
			case 0:
				printf("%c", 204); break;
			case 7:
				printf("%c", 206); break;
			case 30:
				printf("%c", 206); break;
			case 40:
				printf("%c", 206); break;
			case 64:
				printf("%c", 185); break;
			default :
				printf("%c", 205); break;
		}
	}
	printf("\n");
	fscanf (fscore, "%s %s %s %d%c", &skor.date, &skor.time, &skor.name, &skor.score, &skor.enter);
	
	gotoxy(32, 8);
	i = 8;
	while (!feof(fscore)) {
	gotoxy(32, i);
		printf ("%c %d    %c %s %s  %c  %s\t%c\t\t\t%c\n", 186, iscore, 186, skor.date, skor.time, 186, skor.name, 186, 186);
		fscanf (fscore, "%s %s %s %d%c", &skor.date, &skor.time, &skor.name, &skor.score, &skor.enter);
		iscore++;
		i++;
	}
	gotoxy(32, i);
	for (i = 0; i < 65; i++) {
		switch(i){
			case 0:
				printf("%c", 200); break;
			case 7:
				printf("%c", 202); break;
			case 30:
				printf("%c", 202); break;
			case 40:
				printf("%c", 202); break;
			case 64:
				printf("%c", 188); break;
			default :
				printf("%c", 205); break;
		}
	}

	rewind(fscore);
	iscore = 0;
	fscanf(fscore, "%s %s %s %d%c", &skor.date, &skor.time, &skor.name, &skor.score, &skor.enter);
	while (!feof(fscore)) {
		gotoxy(80, 8 + iscore);
		printf("$%d", skor.score);
		fscanf(fscore, "%s %s %s %d%c",&skor.date,&skor.time,&skor.name,&skor.score,&skor.enter);
		iscore++;
	}
	
	gotoxy(32, 12 + iscore); system ("pause");
}

void highScore() {
	int i, j;
	FILE *fhigh;
	int tempsc;
	char tempdat[26];
	char temptim[10];
	char tempnam[10];
	high high;
	
	system("cls");
	system("mode 131, 16");
	if((fhigh = fopen("HighScore.txt", "rb")) == NULL){ 
		printf("File tidak dapat dibuka\n");
		exit(1);
	}
	gotoxy(30, 3)	; for (i = 0; i < 3; i++) {
		switch (i) {
			case 0:
				printf ("%c", 201); break;
			case 1:
				for (j = 0; j < 68; j++) {
					printf ("%c", 205);
				} break;
			case 2:
				printf ("%c", 187); break;
		}
	}
	gotoxy(30, 4)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 5)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 6)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 7)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(52, 5)	; printf("THE HIGHEST SCORE REACHED BY");                           
	fscanf(fhigh, "%s %s %s %d%c", &high.date, &high.time, &high.name, &high.score, &high.enter);
	tempsc = high.score;
	strcpy(tempdat, high.date);
	strcpy(temptim, high.time);
	strcpy(tempnam, high.name);
	while (!feof(fhigh)) {
		if(high.score>tempsc){
			tempsc = high.score;
			strcpy(tempdat,high.date);
			strcpy(temptim,high.time);
			strcpy(tempnam,high.name);
		}
		fscanf (fhigh, "%s %s %s %d%c", &high.date, &high.time, &high.name, &high.score, &high.enter);
	}
	gotoxy(45, 6);
	printf("$%d by %s - %s %s", tempsc, tempnam, tempdat, temptim);
	fclose(fhigh);
	gotoxy(30, 8)  ; for (i = 0; i < 3; i++) {
		switch (i) {
			case 0:
				printf ("%c", 200); break;
			case 1:
				for (j = 0; j < 68; j++) {
					printf ("%c", 205);
				} break;
			case 2:
				printf ("%c", 188); break;
		}
	}
	printf ("\n");
	
	
	gotoxy(30, 12);
	system("pause");
}

void credit() {
	system("mode 131, 25");
	system ("cls");
	FILE *fptr;
	fptr = fopen("Credits.txt", "r");
	int ch = getc(fptr);
	printf ("\n");
	while(ch != EOF){
		
		putchar(ch);
		ch = getc(fptr);
		
	}
	fclose(fptr);
	printf ("\n");
	gotoxy(8, 16);
	system ("pause");
	
}

/* BODY PROCEDURE AND FUNCTION FOR MAP */
void printMenu() {
	int i, j;

	gotoxy(30, 7)	; for (i = 0; i < 3; i++) {
		switch (i) {
			case 0:
				printf ("%c", 201); break;
			case 1:
				for (j = 0; j < 68; j++) {
					printf ("%c", 205);
				} break;
			case 2:
				printf ("%c", 187); break;
		}
	}
	gotoxy(30, 8)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 9)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 10)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 11)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 12)	; for (i = 0; i < 3; i++) {
		switch (i) {
			case 0:
				printf ("%c", 204); break;
			case 1:
				for (j = 0; j < 68; j++) {
					printf ("%c", 205);
				} break;
			case 2:
				printf ("%c", 185); break;
		}
	}
	gotoxy(30, 13)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(63, 13)	; printf ("MENU");
	gotoxy(30, 14)	; for (i = 0; i < 3; i++) {
		switch (i) {
			case 0:
				printf ("%c", 204); break;
			case 1:
				for (j = 0; j < 68; j++) {
					printf ("%c", 205);
				} break;
			case 2:
				printf ("%c", 185); break;
		}
	}
	gotoxy(30, 15)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 16)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 17)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 18)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 19)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(30, 20)	; printf("%c                                                                    %c\n", 186, 186);
	gotoxy(32, 15)	; printf ("1. PLAY GAME");
	gotoxy(32, 16)	; printf ("2. HIGHSCORE ");
	gotoxy(32, 17)	; printf ("3. SCORE HISTORY");
	gotoxy(32, 18)	; printf ("4. HELP   ");
	gotoxy(32, 19)	; printf ("5. CREDIT   ");
	gotoxy(32, 20)	; printf ("6. EXIT   ");
	gotoxy(30, 21)	; for (i = 0; i < 3; i++) {
		switch (i) {
			case 0:
				printf ("%c", 204); break;
			case 1:
				for (j = 0; j < 68; j++) {
					printf ("%c", 205);
				} break;
			case 2:
				printf ("%c", 185); break;
		}
	}
 	gotoxy(30, 22)	; printf("%c                                                                    %c\n", 186, 186);
 	gotoxy(32, 22)	; printf ("INPUT THE MENU YOU WANT TO CHOOSE : ");
	gotoxy(30, 23)  ; for (i = 0; i < 3; i++) {
		switch (i) {
			case 0:
				printf ("%c", 200); break;
			case 1:
				for (j = 0; j < 68; j++) {
					printf ("%c", 205);
				} break;
			case 2:
				printf ("%c", 188); break;
		}
	}

	i = 43;
	j = 8;
	printTitle(i, j);
}

void printTitle(int i, int j) {
	
	gotoxy (i, j); printf ("%c%c%c%c%c %c%c%c%c%c %c%c%c%c%c %c%c%c%c%c %c%c%c%c%c %c%c%c%c%c %c    %c   %c",
	201, 205, 203, 205, 187, 201, 205, 205, 205, 187,
	201, 205, 205, 205, 187, 201, 205, 205, 205, 187,
	201, 205, 205, 205, 187, 201, 205, 205, 205, 187,
	186, 186, 186);

	gotoxy (i, j + 1); printf ("%c %c %c %c   %c %c   %c %c   %c %c%c%c%c%c %c   %c %c    %c%c%c%c%c",
	186, 186, 186, 186, 186,
	186, 186, 186, 186,
	204, 205, 205, 205, 188, 186, 186, 186,
	200, 205, 205, 205, 185);

	gotoxy (i, j + 2); printf ("%c %c %c %c%c%c%c%c %c   %c %c%c%c%c%c %c     %c%c%c%c%c %c%c%c%c %c%c%c%c%c",
	186, 186, 186, 200, 205, 205, 205, 188,
	186, 186, 200, 205, 205, 205, 188,
	186, 200, 205, 205, 205, 188,
	200, 205, 205, 205, 205, 205, 205, 205, 188);
	
	gotoxy (i + 22, j + 3); printf ("/ Anggita Pamudya 2021 /");
}

void gotoxy(int x, int y) {
	//Mencari posisi suatu koordinat pada layar	
  	COORD coord;
  	coord.X = x;
  	coord.Y = y;
  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


