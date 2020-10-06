/*    NIM		: 13519021 */
/*    Nama		: Arjuna Marcelino */	
/*    Tanggal		: 10 September 2020 */
/*    Topik praktikum	: Praktikum 2 */
/*    Nama file	: array_mono.c */
/*    Deskripsi	: memeriksa apakah array tersebut merupakan Array Monotonik atau bukan */

#include <stdio.h>
#include "arraypos.h"

int main ()
{
	int N;
	TabInt T,T1,T2;
	boolean asc1 = true;
	boolean asc2 = false;
	ElType X;
	ElType Sum;
	MakeEmpty (&T);
	BacaIsi (&T);
	
	/* Mengecek apakah monotonik statik atau bukan dan jenisnya */
	X = Elmt (T,0);		
	N = NbElmt (T);
	Sort (&T1, asc1);
	Sort (&T2, asc2);
	if (CountX (T,X) == N)
	{
		printf("Array monotonik statik\n");
	}
	
	else if(IsEQ (T,T1))
	{
		printf("Array monotonik tidak mengecil\n");
	}
	
	else if(IsEQ (T,T2))
	{
		printf("Array monotonik tidak membesar\n");
	}
	
	else 
	{
		printf("Array tidak monotonik\n");
	}
	return 0;
}
