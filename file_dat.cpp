/* Nama file : File_Dat.cpp
Deskripsi : Pengelolaan data file dalam C, meliputi entry, tampil dan sort
Author	 : Ade Chandra
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {char Kelas[3];
			 char NIM[11];
			 char JK;
			 float IP; } Mhs;

void Entry_file();
void Sort_file();
void Tampil_file();

int main()
{
	int pil = 0;
	for (;;)
	{
		printf("\t\tMenu : \n");
		printf("\t 1. Entry data \n");
		printf("\t 2. Sort data \n");
		printf("\t 3. Tampil isi file \n");
		printf("\t 4. S e l e s a i \n");
		printf("\n\t Pilihan : "); scanf("%d", &pil);
		switch (pil)
		{
			case 1 : {  Entry_file();
							break; }
			case 2 : {  Sort_file();
							break; }
			case 3 : { Tampil_file();
							break; }
			default : { return(0);}
		}
	}
}

void Entry_file()
// Procedure untuk mengentrykan data ke file Mhs_jtk.dat
{
	Mhs dt;
	char lagi;
	FILE *f_mhs;


	if ((f_mhs=fopen("Mhs_jtk.dat", "ab+"))==NULL)
	{
		printf ("File tidak dapat dibuka\n");
		exit(1);
	}
	for (;;)
	{
		fflush(stdin);
		printf("Kelas : "); scanf("%s",&dt.Kelas);
		fflush(stdin);
		printf("N I M : "); scanf("%s",&dt.NIM);
		fflush(stdin);
		printf("Jenis Kelamin : "); scanf("%c", &dt.JK);
		printf("I P   : "); scanf("%f", &dt.IP);
		// Sebelum nyimpan ke file, Hapus dulu isi penampung keyboard
		fflush(stdin);
		// Save to file
	fprintf(f_mhs, " %s %s %c %3.2f", dt.Kelas, dt.NIM, dt.JK,dt.IP);

		printf("Entry data lagi ? (Y/T) ");
		lagi = getche();
		printf("\n");
		if (lagi == 't' || lagi == 'T')
			break;
	}
	fclose(f_mhs);
}

void Tampil_file()
// Procedure untuk Menampilkan isi file mahasiswa
{
	Mhs dt;
	FILE *f_mhs;

	if ((f_mhs=fopen("Mhs_jtk.dat", "rb"))==NULL)
	{
		printf ("File tidak dapat dibuka\n");
		exit(1);
	}
	printf ("\nISI FILE MHS_JTK.dat ADALAH : \n\n");
	printf ("Kelas	 NIM	       JK   IP \n");

	while (!feof(f_mhs))
	{
	fscanf(f_mhs,"%s %s %c %f", &dt.Kelas, &dt.NIM, &dt.JK, &dt.IP );
	printf("%s     %s     %c    %3.2f\n", dt.Kelas, dt.NIM, dt.JK,dt.IP);
	}
	fclose(f_mhs);
}
void Sort_file()
//sort file berdasarkan Kelas+NIM (Asc)
{
	FILE *f_mhs;
	long i=0, j;
	Mhs dt, Temp;

	if ((f_mhs=fopen("Mhs_jtk.dat", "rb+"))==NULL)
	{
		printf ("File tidak dapat dibuka\n");
		exit(1);
	}
	while (!feof(f_mhs))
	{
		fseek(f_mhs, (i*(sizeof(Mhs)+1))+i, SEEK_SET);
	fscanf(f_mhs,"%s %s %c %f", &dt.Kelas, &dt.NIM, &dt.JK, &dt.IP );
		j = i;
		while (!feof(f_mhs))
		{
			j++;
			fseek(f_mhs, (j*(sizeof(Mhs)+1))+j, SEEK_SET);
	fscanf(f_mhs,"%s %s %c %f",&Temp.Kelas,&Temp.NIM,&Temp.JK,&Temp.IP);
			if ((strcmp(dt.Kelas,Temp.Kelas)>0) ||
	 ((strcmp(dt.Kelas,Temp.Kelas)==0) && (strcmp(dt.NIM,Temp.NIM)>0)))
			{
	fseek(f_mhs, i*(sizeof(Mhs)+1)+i, SEEK_SET);
	fprintf(f_mhs," %s %s %c %3.2f",Temp.Kelas,Temp.NIM,Temp.JK,Temp.IP);
	fseek(f_mhs, j*(sizeof(Mhs)+1)+j, SEEK_SET);
	fprintf(f_mhs, " %s %s %c %3.2f", dt.Kelas, dt.NIM, dt.JK,dt.IP);
				strcpy(dt.Kelas,Temp.Kelas);
				strcpy(dt.NIM,Temp.NIM);
				dt.JK = Temp.JK;
				dt.IP = Temp.IP;
			}
		}
		if (i < j)
		{
			fseek(f_mhs, 0, SEEK_SET);
			i++;
		}
	}
printf("Sort File Berdasarkan Kelas dan NIM sudah selesai, hasilnya : ");
	fclose(f_mhs);
	Tampil_file();
}
