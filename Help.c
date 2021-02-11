// Program : Help
// Author : Adriana Anggita Daeli & Pamudya Putra Pamungkas
// Description : Module for showing how to play the game

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	system("mode 131, 90");
	FILE *fhelp;
	fhelp = fopen("Help.txt", "r");
	int help = getc(fhelp);
	while (help != EOF){
		putchar(help);
		help = getc(fhelp);
	}
	fclose(fhelp);
}
