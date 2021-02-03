/* NIM			: 13519021 */
/* Nama		: Arjuna Marcelino */
/* Tanggal		: 19 November 2020 */
/* Topik praktikum	: Praktikum 11 */
/* Nama file		: delNFromEnd.c */
/* Deskripsi		: Implementasi fungsi delNFromEnd */

#include "listrek.h"
#include <stdlib.h>

List delNFromEnd(List L, int n)
/* L terdefinisi, tidak mungkin kosong. */
/* Elemen ke-n L dari belakang akan dihapus dan didealokasi,
   lalu mengembalikan head dari list
   misal L = [1, 2, 3, 4, 5] dan n = 2
         L akan menjadi [1, 2, 3, 5] */
{
	int num,loc;
	address A[100];
	address P;
	
	num = 0;
	P = L;
	
	while (P!=Nil)
	{
		A[num] = P;
		num++;
		P = Next(P);
	}
	
	A[num] = Nil;
	loc = num-n;
	
	if(A[loc]==L)
	{
		Dealokasi(L);
		return A[loc+1];
	}
	else
	{
		SetNext(A[loc-1],A[loc+1]);
	}
	
	Dealokasi(A[loc]);
	
	return L;
	
}
