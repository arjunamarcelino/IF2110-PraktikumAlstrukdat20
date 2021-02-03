/* NIM				: 13519021 */
/* Nama				: Arjuna Marcelino */
/* Tanggal			: 26 November 2020 */
/* Topik praktikum	: Praktikum 12 */
/* Nama file		: invertBtree.c */
/* Deskripsi		: Realisasi dari gunsi InverBTree, yaitu menghasilkan Pohon P yang diflip secara vertikal */

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

void InvertBtree(BinTree *P)
/* I.S. Pohon P terdefinisi */
/* F.S. Pohon P diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
{
	if(IsBiner(*P))
	{
		BinTree Temp = Left(*P);
		Left(*P) = Right (*P);
		Right (*P) = Temp;

		InvertBtree(&Left(*P));
		InvertBtree(&Right(*P));
	}

	else if (IsUnerRight(*P))
	{
		Left(*P)=Right(*P);
		Right(*P)=Nil;
		InvertBtree(&Left(*P));
	}

	else if (IsUnerLeft(*P))
	{
		Right(*P)=Left(*P);
		Left(*P)=Nil;
		InvertBtree(&Right(*P));
	}

}