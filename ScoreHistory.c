// Program : ScoreHistory
// Author : Adriana Anggita Daeli & Pamudya Putra Pamungkas
// Description : Module for showing scores history

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
//Mencari posisi suatu koordinat pada layar
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

typedef struct {
	
	char date[26];
	char time[10];
	char name[10];
	char enter;
	int score;
}score;

void ScoreHistory(){
	FILE *fscore;
	int iscore = 1;
	int i;
	score skor;
//	time(&skor.time);
	if((fscore=fopen("HighScore.txt", "rb"))==NULL){
		printf("File tidak dapat dibuka\n");
		exit(1);
	}
	printf("\t\t\tRiwayat Skor Monopoli\n");
	for(i=0;i<65;i++){
		switch(i){
			case 0:
				printf("%c", 201);
				break;
			case 8:
				printf("%c", 203);
				break;
			case 30:
				printf("%c", 203);
				break;
			case 40:
				printf("%c", 203);
				break;
			case 64:
				printf("%c", 187);
				break;
			default :
				printf("%c", 205);
				break;
		}
		
	}
	printf("\n%cNo. \t%c DD/MM/YYYY HH:MM:SS %c  Names\t%c  \t Scores\t\t%c\n",186,186,186,186,186);
	for(i=0;i<65;i++){
		switch(i){
			case 0:
				printf("%c", 204);
				break;
			case 8:
				printf("%c", 206);
				break;
			case 30:
				printf("%c", 206);
				break;
			case 40:
				printf("%c", 206);
				break;
			case 64:
				printf("%c", 185);
				break;
			default :
				printf("%c", 205);
				break;
		}
	}
	printf("\n");
	fscanf(fscore, "%s %s %s %d%c",&skor.date,&skor.time,&skor.name,&skor.score,&skor.enter);
	while(!feof(fscore)){
		printf("%c%d.\t%c %s %s %c  %s\t%c\t\t\t%c\n",186,iscore,186,skor.date,skor.time,186,skor.name,186,186);
		fscanf(fscore, "%s %s %s %d%c",&skor.date,&skor.time,&skor.name,&skor.score,&skor.enter);
		iscore++;
	}
	for(i=0;i<65;i++){
		switch(i){
			case 0:
				printf("%c", 200);
				break;
			case 8:
				printf("%c", 202);
				break;
			case 30:
				printf("%c", 202);
				break;
			case 40:
				printf("%c", 202);
				break;
			case 64:
				printf("%c", 188);
				break;
			default :
				printf("%c", 205);
				break;
		}
	}

	rewind(fscore);
	iscore = 0;
	fscanf(fscore, "%s %s %s %d%c",&skor.date,&skor.time,&skor.name,&skor.score,&skor.enter);
	while(!feof(fscore)){
		gotoxy(48,4+iscore); printf("%d", skor.score);
		fscanf(fscore, "%s %s %s %d%c",&skor.date,&skor.time,&skor.name,&skor.score,&skor.enter);
		iscore++;
	}
	gotoxy(0, 3+iscore); printf ("\n");
}

int main(){
	ScoreHistory();
	return 0;
}
