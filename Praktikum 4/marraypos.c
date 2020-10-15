/*    NIM		: 13519021 */
/*    Nama		: Arjuna Marcelino */	
/*    Tanggal		: 10 September 2020 */
/*    Topik praktikum	: Praktikum 2 */
/*    Nama file	: marraypos.c */
/*    Deskripsi	: menampilkan array, banyaknya X muncul dan golongan X (median, maks, atau min) */

#include <stdio.h>
#include "arraypos.h"

int main ()
{
	/* KAMUS */
	int X,N;
	ElType Max, Min, Med;
	IdxType Idx;
	TabInt T;
	boolean asc=true;
	
	/* ALGORITMA */
	MakeEmpty (&T); 			/* Inisiasi array */
	BacaIsi (&T);				/* Baca array */
	scanf("%d",&X); 			/* Baca nilai X*/ 
	TulisIsiTab (T); 			/* Menampilkan array*/
	printf("\n");
	N = NbElmt (T);
	if (!SearchB(T,X))			/* Mencari nilai X di array */
	{
		printf("%d tidak ada",X);
		printf("\n");
	}
	else 
	{
		printf("%d",Search1 (T,X));
		printf("\n");
	}
	MaxMin (T,&Max,&Min);
	Sort (&T,asc);
	if(N%2==1)				/* Mencari nilai medium */
	{
		Idx = (N+1)/2;
	}
	else
	{
		Idx = N/2;
	}
	
	Med = Elmt(T,Idx);
	
	if(X==Max)				/* Mengecek nilai X apakah termasuk maksimum, minimum atau median*/
	{
		printf("maksimum");
		printf("\n");
	}
	
	if(X==Min)
	{
		printf("minimum");
		printf("\n");
	}
	if(X==Med)
	{
		printf("median");
		printf("\n");
	}
	
	return 0;
}
