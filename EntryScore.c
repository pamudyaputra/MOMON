// Program : EntryScore
// Author : Adriana Anggita Daeli & Pamudya Putra Pamungkas
// Description : Module for putting time, name, and score to file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void EntryScore(){ //parameter : nama, skor
	FILE *fentryscore;
	char date[20];
	char waktu[20];
	char space='\n';
	time_t t;
	struct tm* tm_info;
	t = time(NULL);
	tm_info = localtime(&t);
	
	//Konversi tanggal DD/MM/YYYY ke string
	strftime(date,sizeof(date), "%d/%m/%Y", tm_info);
	//Konversi waktu HH:MM:SS ke string
	strftime(waktu,sizeof(waktu), "%H:%M:%S", tm_info);
	
	fentryscore = fopen("HighScore.txt", "ab");
	fprintf(fentryscore, "%s %s %s %d%c",date,waktu,/*nama*/,/*skor*/,space);
	fclose(fentryscore);
}
