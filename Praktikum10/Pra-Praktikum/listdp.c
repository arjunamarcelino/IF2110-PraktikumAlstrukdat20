/* Nama 			: Arjuna Marcelino */
/* NIM 				: 13519021 */
/* Tanggal 			: 10 November 2020 */
/* Topik Praktikum 	: Pra-Praktikum 10 */
/* File				: listdp.c */
/* Deskripsi 		: Implementasi listdp.h */

#include <stdio.h>
#include <stdlib.h>	
#include "listdp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return ((First(L)==Nil) && (Last(L)==Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L)=Nil;
	Last(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address P = (address) malloc(sizeof (ElmtList));
	
	if (P!=Nil)
	{
		Info(P)=X;
		Next(P)=Nil;
		Prev(P)=Nil;
	} 
	return P;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P;
	boolean found;

	P=First(L);
	found=false;
	while ((P!=Nil) && (!found))
	{
		if (Info(P)==X)
		{
			found=true;
		} 
		else
		{
			P=Next(P);
		}
	}
	return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P;

	P=Alokasi(X);
	if (P!=Nil)
	{
		InsertFirst(L,P);
	}
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P;

	P=Alokasi(X);
	if (P!=Nil) 
	{
		InsertLast(L,P);
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P = First(*L);
	
	*X=Info(First(*L));
	First(*L)=Next(P);
	if (First(*L)!=Nil)
	{
		Prev(First(*L))=Nil;
	} 
	else
	{
		Last(*L) = Nil;
	}
	Dealokasi(P);

}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P = Last(*L);
	
	*X = Info(Last(*L));
	Last(*L)=Prev(P);
	if (Last(*L)!=Nil)
	{
		Next(Last(*L))=Nil;
	} 
	else
	{
		First(*L)=Nil;
	}	
	Dealokasi(P);

}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if (!IsEmpty(*L))
	{
		Next(P)=First(*L);
		Prev(First(*L))=P;
	} 
	else
	{
		Last(*L)=P;
	}
	First(*L)=P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (!IsEmpty(*L))
	{
		Prev(P)=Last(*L);
		Next(Last(*L))=P;
	}
	else
	{
		First(*L)=P;
	}
	Last(*L)=P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Prev(P)=Prec;
	Next(P)=Next(Prec);
	Next(Prec)=P;

	if(Next(P)!=Nil)
	{
		Prev(Next(P))=P;
	}
	else
	{
		Last(*L)=P;
		Next(Last(*L))=Nil;
	}
}

void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	Next(P)=Succ;
	Prev(P)=Prev(Succ);
	Prev(Succ)=P;
	
	if (Prev(P)!=Nil)
	{
		Next(Prev(P))=P;
	}
	else 
	{
		First(*L)=P;
		Prev(First(*L))=Nil;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P=First(*L);
	First(*L)=Next(First(*L));

	if(First(*L)==Nil)
	{
		Last(*L)=Nil;
	}
	else
	{
		Prev(First(*L))=Nil;
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P=Last(*L);
	Last(*L)=Prev(Last(*L));

	if(Last(*L)==Nil)
	{
		First(*L)=Nil;
	}
	else
	{
		Next(Last(*L))=Nil;
	}
}


void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P = Search(*L,X);
    if(P!=Nil)
    {
        if (P==First(*L))
        {
            First(*L)=Next(P);
            if (P==Last(*L))
            {
                Last(*L)=Nil;
            } 
            else 
            {
                Next(P)=Nil;
                Prev(First(*L))=Nil;
            }
        } 
        else
        {
            if (Last(*L)==P)
            {
                Last(*L)=Prev(P);
                Next(Last(*L))=Nil;
                Prev(P)=Nil;
            } 
            else
            {
                Next(Prev(P))=Next(P);
                Prev(Next(P))=Prev(P);
                Prev(P)=Nil;
                Next(P)=Nil;
            } 
        }
        Dealokasi(P);  
    } 
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	address P = Next(Prec);
	
	*Pdel=Next(Prec);
	if (P!=Nil)
	{
		if (Next(P)!=Nil)
		{
			Prev(Next(P))=Prec;
		} 
		else
		{
			Last(*L)=Prec;
			Next(Last(*L))=Nil;
		}
		Next(Prec)=Next(P);
	}
}

void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	address P = Prev(Succ);
	
	*Pdel=Prev(Succ);
	if (P!=Nil)
	{
		if (Prev(P)!=Nil)
		{
			Next(Prev(P))=Succ;
		} 
		else
		{
			First(*L)=Succ;
			Prev(First(*L))=Nil;
		}
		Prev(Succ)=Prev(P);
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	address P = First(L);
	boolean first = true;
	
	printf("[");
	while (P!=Nil)
	{
		if (!first)
		{
			printf(",");
		}
		printf("%d",Info(P));
		first=false;
		P=Next(P);
	}
	printf("]");
}

void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	address P = Last(L);
	boolean first = true;

	printf("[");
	while (P!=Nil)
	{
		if (!first)
		{
			printf(",");
		}
		printf("%d",Info(P));
		first=false;
		P=Prev(P);
	}
	printf("]");
}
