/* File: driver_jam.c */
/* Tanggal: 3 September 2020 */

#include <stdio.h>
#include "jam.h"

int main ()
{
  JAM J1, J2;
  J1 = MakeJAM (1,40,30);
  printf("Diberikan jam pertama: ");
  TulisJAM(J1);
  printf("\n");
  printf("Masukkan jam kedua : ");
  BacaJAM(&J2);
  
 
  printf("Konversi jam kedua ke dalam detik menjadi : ");
  printf(JAMToDetik (J2));
  printf("\n");
  
  printf("Konversi 71200 detik ke dalam satuan jam menjadi : "); 
  printf(DetikToJAM (71200));
  printf("\n");
  
  if(JEQ(J2, J1))
  {
    printf("Jam 2 sama dengan Jam 1\n");
  }
  
  if(JNEQ(J2, J1))
  {
    printf("Jam 2 tidak sama dengan Jam 1\n");
  }
  
  if(JLT(J2, J1))
  {
    printf("Jam 2 kurang dari Jam 1\n");
  }
  
  if(JGT(J2, J1))
  {
    printf("Jam 2 lebih dari Jam 1\n");
  }
  
  printf("Satu detik setelah Jam 2 adalah ");
  TulisJAM(NextDetik(J2));
  printf("\n");
  
  printf("Sepuluh detik setelah Jam 2 adalah ");
  TulisJAM(NextNDetik(J2,10));
  printf("\n");
  
  printf("Satu detik sebelum Jam 2 adalah ");
  TulisJAM(PrevDetik(J2));
  printf("\n");
  
  printf("Sepuluh detik sebelum Jam 2 adalah ");
  TulisJAM(PrevNDetik(J2,10));
  printf("\n");
  
  printf("Durasi jarak antara Jam 2 dengan Jam 1 adalah ", Durasi(J1, J2));
  printf("\n");
  
  return 0;
}
