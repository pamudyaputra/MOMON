/*
 "program input angka output kata"

 *program ini menggunakan variabel bertipe data integer;
  keterangan : s = Satuan, b = belasan, p = puluhan,
  r = ratusan dan rb = ribuan;
  tipe data integer ini mempermudah program menunjuk aray.
 *pogram ini juga menggunakan array karakter dua dimensi,
  array ini berfungsi sebagai database program untuk
  mengeluarkan kata sesua yang diininkan;
 *modulo digunakan untuk mendapatkan sisa bagi dari nilai yang dimasukkan;
*/

#include <stdio.h>

int main()
{
 // deklarasi variabel bertipe data integer
 int x;
 int s, b, p, r, rb;

 // aray bertipe data karakter 2D
 char kata[][15] = {{""}, {"Satu"}, {"Dua"}, {"Tiga"}, {"Empat"},{"Lima"},
       {"Enam"}, {"Tujuh"}, {"Delapan"}, {"Sembilan"}};

 //menginput angka
 printf("Masukkan angka : ");
 scanf("%d", &x);

 // menggunakan modulo (%)
 s = x % 10;
 x = x / 10;
 b = s;

 p = x % 10;
 x = x / 10;

 r = x % 10;
 x = x / 10;

 rb = x % 10;
 x = x / 10;

 // output program
 printf("\nTerbilang : ");

 // syarat untuk nilai seribuan
 if(rb != 0 && rb != 1){
  printf("%s Ribu ", kata[rb]);
 }else if(rb == 1){printf("Seribu ");}

 // syarat untuk nilai Ratusan
 if(r != 0 && r != 1){
  printf("%s Ratus ", kata[r]);
 }else if(r == 1){printf("Seratus ");}

 // syarat untuk nilai belasan
 if(b != 0 && (b != 1 && p == 1)){
  printf("%s Belas ", kata[b]);
 }else if(b == 1 && p == 1){printf("Sebelas ");}

 // syarat untuk nilai puluhan
 if(p != 0 && p != 1){
  printf("%s Puluh ", kata[p]);
 }else if(s == 0 && p ==1){printf("Sepuluh ");}

 // syarat untuk nilai satuan
 if(p != 1){
  printf("%s", kata[s]);
 }

 if((s == 0 && (p == 0 && r == 0)) && rb == 0){
  printf("Nol");
 }

 printf("\n\n");
 system("PAUSE");
 return 0;
}

