/* Nama : Arjuna Marcelino */
/* NIM : 13519021 */
/* Tanggal : 1 Oktober 2020 */
/* Topik Praktikum : Praktikum 6*/
/* File: telegram.c */
/* Deskripsi : Membaca sebuah pita karakter yang dianggap sebagai sebuah Telegram dan kemudian menghitung besar biaya yang harus dibayar oleh pengirim telegram */

#include "mesinkata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

boolean IsKataSama (Kata K1, Kata K2)
/* { Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama dan urutan karakter yang menyusun kata juga sama. Dua kata kosong adalah kata yang sama. } */
{
	boolean sama = false;
	int length = K1.Length;
	int i;
	if (K1.Length == K2.Length)
	{
		for (i = 0; i < length; i++)
		{
			if (K1.TabKata[i]==K2.TabKata[i])
			{
				sama = true;
			}
		}
	}
	else if (K1.Length == K2.Length == 0)
	{
		sama = true;
	}
	else
	{
		sama =  false;
	}
	return sama; 
}

int main()
{
	Kata tanda1, tanda2;
	tanda1.Length = 5;
	tanda1.TabKata[0] = 'T';
	tanda1.TabKata[1] = 'I';
	tanda1.TabKata[2] = 'T';
	tanda1.TabKata[3] = 'I';
	tanda1.TabKata[4] = 'K';
	tanda2.Length = 4;
	tanda2.TabKata[0] = 'K';
	tanda2.TabKata[1] = 'O';
	tanda2.TabKata[2] = 'M';
	tanda2.TabKata[3] = 'A';
	
	int reg =0;
	int panjang =0;
	int tarif =0;
	
	STARTKATA();
	int i=0;
	if(EndKata)
	{
		printf("Ekspresi kosong\n");
	}
	else
	{
		while(!EndKata)
		{
			if(!IsKataSama(tanda1,CKata) && (!IsKataSama(tanda2,CKata)))
			{	
				if(CKata.Length<10)
				{	
					reg+=1;
				}
				else
				{
					panjang +=1;
				}
				for (i=0; i<CKata.Length-1; i++)
				{
					printf("%c",CKata.TabKata[i]);
				}
				printf("%c ",CKata.TabKata[CKata.Length-1]);
			}
			else if (IsKataSama(tanda1,CKata))
			{
				printf(". ");
			}
			else if (IsKataSama(tanda2,CKata))
			{
				printf(", ");
			}
			IgnoreBlank();
			ADVKATA(); 
		}
		printf("\n");
		printf("%d",reg);
		printf("\n");
		printf("%d",panjang);
		printf("\n");
		if((reg+panjang)>10)
		{
			tarif = (reg*1000)+(panjang*1500)-(((reg*1000)+(panjang*1500))/0.1);
		}
		else
		{
			tarif = (reg*1000)+(panjang*1500);
		}
		printf("%d",tarif);
		printf("\n");
	}
	return 0;
}
