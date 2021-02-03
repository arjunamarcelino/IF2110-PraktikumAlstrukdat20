/* NIM				: 13519021 */
/* Nama				: Arjuna Marcelino */
/* Tanggal			: 12 November 2020 */
/* Topik praktikum	: Praktikum 10 */
/* Nama file		: stacklist.c */
/* Deskripsi		: Implementasi stacklist.h */

#include "stacklist.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
	*P = (address) malloc (sizeof (ElmtStack));

	if(*P!=Nil)
	{
		Info(*P)=X;
		Next(*P)=Nil;
	}
}

void Dealokasi (address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */ 
{
	free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{
	return (Top(S)==Nil);
}

void CreateEmpty (Stack * S)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
{
	Top(*S)=Nil;
}

void Push (Stack * S, infotype X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{
	address P=Top(*S);
	Alokasi(&P,X);

	if(P!=Nil)
	{
		if(IsEmpty(*S))
		{
			Top(*S)=P;
		}
		else
		{
			Next(Top(*S))=Top(*S);
			Top(*S)=P;
		}
	}
}

void Pop (Stack * S, infotype * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{
	address P = Top(*S);

	if(Next(Top(*S))==Nil)
	{
		CreateEmpty(S);
	}
	else
	{
		Top(*S)=Next(Top(*S));
	}

	*X = Info(P);
	Dealokasi(P);
}