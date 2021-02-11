// Program : HighScore()
// Author : Pamudya Putra Pamungkas
// Description : Module for showing highest score reached by a player

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


typedef struct {
	char date[26];
	char time[10];
	char name[10];
	char enter;
	int score;
}high;

void HighScore(){
	FILE *fhigh;
	int tempsc;
	char tempdat[26];
	char temptim[10];
	char tempnam[10];
	high high;
	if((fhigh=fopen("HighScore.txt", "rb"))==NULL){
		printf("File tidak dapat dibuka\n");
		exit(1);
	}
	printf("\t\t\t      Skor tertinggi yang dicapai sampai saat ini\n");
	fscanf(fhigh, "%s %s %s %d%c",&high.date,&high.time,&high.name,&high.score,&high.enter);
	tempsc = high.score;
	strcpy(tempdat,high.date);
	strcpy(temptim,high.time);
	strcpy(tempnam,high.name);
	while(!feof(fhigh)){
		if(high.score>tempsc){
			tempsc = high.score;
			strcpy(tempdat,high.date);
			strcpy(temptim,high.time);
			strcpy(tempnam,high.name);
		}
		fscanf(fhigh, "%s %s %s %d%c",&high.date,&high.time,&high.name,&high.score,&high.enter);
	}
	printf("\t\t\t\t%d oleh %s - %s %s",tempsc,tempnam,tempdat,temptim);
	fclose(fhigh);
}

int main(){
	HighScore();
	return 0;
}








