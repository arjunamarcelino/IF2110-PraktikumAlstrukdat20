/* File: driver_point.c */
/* Tanggal: 3 September 2020 */

#include <stdio.h>
#include "point.h"

int main ()
{
  POINT P1;
  POINT P2;
  printf("\n");
  printf("Masukkan Point pertama : ");
  BacaPOINT(&P1);
  printf("\nPoint yang dibaca adalah :");
  TulisPOINT(P1);
  printf("\n");
  printf("Masukkan Point kedua : ");
  BacaPOINT(&P2);
  printf("\nPoint yang dibaca adalah :");
  TulisPOINT(P2);
  if(EQ(P1, P2))
  {
    printf("Absis dan ordinat dari point pertama dan kedua sama\n");
  }
  if(NEQ(P1, P2))
  {
    printf("Absis dan ordinat dari point pertama dan kedua beda\n");
  }
  if(IsOrigin(P2))
  {
    printf("Point kedua adalah titik origin\n");
  }
  if(IsOnSbX(P2))
  {
    printf("Point kedua terletak pada sumbu X \n");
  }
  if(IsOnSbY(P2))
  {
    printf("Point kedua terletak pada sumbu Y \n");
  }
  printf("Point kedua berada pada kuadran %d\n", Kuadran(P2));

  printf("Apabila absis ditambah satu, point kedua koordinatnya menjadi: ");
  TulisPOINT(NextX(P2));
  printf("\n");
    
  printf("Apabila ordinat ditambah satu, point kedua koordinatnya menjadi: ");
  TulisPOINT(NextY(P2));
  printf("\n");
    
  printf("Apabila digeser satu ke kiri dan dua ke bawah, point kedua koordinatnya menjadi: ");
  TulisPOINT(PlusDelta(P2, -1, -2));
  printf("\n");
  
  printf("Apabila dicerminkan sumbu X, point kedua koordinatnya: ");
  TulisPOINT(MirrorOf(P2, true));
  printf("\n");
  
  printf("Apabila dicerminkan sumbu Y, point kedua koordinatnya: ");
  TulisPOINT(MirrorOf(P2, false));
  printf("\n");

  printf("Jarak point kedua dengan origin ialah %f", Jarak0(P2));
  printf("\n");
  
  printf("Panjang garis yang dibentuk point pertama dan point kedua ialah %f", Panjang (P1,P2));
  
  printf("Point kedua akan ditranslasi sebesar point yang diberikan\n");
  Geser(&P2, 10, 5);
  printf("\n");
  
   if(IsOnSbX(P2))
   {
      printf("Point kedua sudah di sumbu X\n");
   }
   else
   {
       printf("Point kedua akan digeser ke sumbu X\n");
       GeserKeSbX(&P2);
   }
  
   if(IsOnSbY(P2))
   {
        printf("Point kedua sudah di sumbu Y\n");
   }
   else
   {
        printf("Point kedua akan digeser ke sumbu Y\n");
        GeserKeSbY(&P2);
   }
    
   if(IsOrigin(P2))
   {
        printf("Point kedua ada di origin");
   }
  
  printf("Point kedua dicerminkan sumbu X \n");
  Mirror(&P2, true);
  printf("Point kedua dicerminkan sumbu Y \n");
  Mirror(&P2, false);
  printf("Point kedua diputar 100 derajat searah jarum jam \n");
  Putar(&P2, 100);
  
  return 0;
}
