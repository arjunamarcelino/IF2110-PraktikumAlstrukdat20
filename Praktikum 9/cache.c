/* NIM				: 13519021 */
/* Nama				: Arjuna Marcelino */
/* Tanggal			: 5 November 2020 */
/* Topik praktikum	: Praktikum 9 */
/* Nama file		: cache.c */
/* Deskripsi		: Skema LRU, yakni Least Recently Used. Pada skema ini, apabila nilai x tidak ada di cache, */ 
/* cache akan menghapus nilai di cache yang paling lama sudah tidak digunakan. Jadi, cache menyimpan daftar nilai, */
/* terurut dari yang paling baru digunakan, sampai yang paling lama digunakan.*/

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int N, Q ,x;
	address P;

	scanf("%d", &N);

	List L;
	CreateEmpty(&L);

	for (int i = 0; i < N; ++i)
	{
		P = Alokasi(N - i);
		InsertFirst(&L, P);
	}

	scanf("%d", &Q);

	for (int i = 0; i < Q; ++i)
	{
		scanf("%d", &x);
		P = Search(L, x);
		if (P != Nil)
		{
			DelP(&L, x);
			P = Alokasi(x);
			InsertFirst(&L, P);
			printf("hit ");
			PrintInfo(L);
			printf("\n");
		}
		else
		{
			DelLast(&L, &P);
			P = Alokasi(x);
			InsertFirst(&L, P);
			printf("miss ");
			PrintInfo(L);
			printf("\n");
		}
	}

	return 0;
}