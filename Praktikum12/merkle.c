/* NIM				: 13519021 */
/* Nama				: Arjuna Marcelino */
/* Tanggal			: 26 November 2020 */
/* Topik praktikum	: Praktikum 12 */
/* Nama file		: merkle.c */
/* Deskripsi		: sebuah program yang mampu membuat sebuah pohon merkle yang sudah disederhanakan */
/* dengan ADT Bintree yang sudah diimplementasi sebelumnya. */

#include "bintree.h"
#include "listrek.h"
#include <stdio.h>
#include <stdlib.h>

BinTree MerkleTree (int i)
{
		if(i == 0)
		{
			int x;
			scanf("%d",&x);
			BinTree hasil = AlokNode(x);
			return hasil;
		}
		else
		{
			BinTree current = AlokNode(0);
			Left(current) = MerkleTree(i-1);
			Right(current) = MerkleTree(i-1);
			Akar(current) = Akar(Left(current)) + Akar(Right(current));
			return current;
		}
}

int main ()
{
	int N;
	scanf("%d",&N);


	int count = 0;
	long cek = 1;

	while (cek < N)
	{
		cek *= 2;
		count++;
	}

	if (cek != N)
	{
		printf("Jumlah masukan tidak sesuai\n");
	}
	else
	{
		BinTree T = MerkleTree(count);
		PrintTree(T,2);
	}

	return 0;
}

