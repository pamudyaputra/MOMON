// Program : Credits()
// Author : Pamudya Putra Pamungkas
// Description : Module for showing credits

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fptr;
	fptr = fopen("Credits.txt", "r");
	int ch = getc(fptr);
	while(ch != EOF){
		putchar(ch);
		ch = getc(fptr);
	}
	fclose(fptr);
	
}
