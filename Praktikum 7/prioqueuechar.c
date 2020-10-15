/* Nama : Arjuna Marcelino */
/* NIM : 13519021 */
/* Tanggal : 8 Oktober 2020 */
/* Topik Praktikum : Praktikum 7 */
/* File: prioqueuechar.c */
/* Deskripsi :	Implementasi prioqueuechar.h */
/* 		Model Implementasi Versi III dengan circular buffer */
/* 		Elemen queue terurut tidak mengecil berdasarkan elemen prio */

#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return ((Head(Q)==Nil) && (Tail(Q)==Nil));
}

boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	return((Head(Q)==0) && (Tail(Q)==MaxEl(Q)-1));
}

int NBElmt (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if (IsEmpty(Q))
	{
		return 0;
	}
	else
	{
		if(Tail(Q)>=Head(Q))
		{
			return(Tail(Q)-Head(Q)+1);
		}
		else
		{
			return(MaxEl(Q)-Head(Q)+Tail(Q)+1);
		}
	}
	
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	(*Q).T = (infotype *) malloc (Max * sizeof(infotype));
	if ((*Q).T != NULL)
	{
		MaxEl (*Q) = Max;
		Head (*Q) = Nil;
		Tail (*Q) = Nil;
	}
	else
	{
		MaxEl (*Q) = 0;
	}
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	MaxEl(*Q) = 0;
	free((*Q).T);
}


/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
	if (IsEmpty (*Q))
	{
		Head(*Q)=0;
		Tail(*Q)=0;
	}
	else
	{
		if (Tail (*Q)==MaxEl (*Q)-1)
		{
			if(!IsFull(*Q))
			{
				Tail(*Q)=0;
			}
		}
	}
	
	Tail(*Q) ++;
	InfoTail(*Q)=X;
	
	address i;
	infotype Temp;
	if (!IsEmpty(*Q))
	{
		for (i=0;i<NBElmt(*Q);i++)
		{
			if (Prio(Elmt(*Q,i))>Prio(Elmt(*Q,i+1)))
			{
				Temp = Elmt (*Q,i+1);
				Elmt (*Q,i+1) = Elmt (*Q,i);
				Elmt (*Q,i) = Temp;
			}
		}
}	}
        
        
        
void Dequeue (PrioQueueChar * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
	*X = InfoHead (*Q);
	if (Head(*Q)==Tail(*Q))
	{
		Head(*Q)=Nil;
		Tail(*Q)=Nil;
	}
	else
	{
		if (Head(*Q)==MaxEl(*Q)-1)
			{
				if(!IsFull(*Q))
				{
					Head(*Q)=0;
				}
			}
		Head(*Q)++;
	}
}


/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{
	address k=Head(Q);
	if (IsEmpty (Q))
	{
		printf("#\n");
	}
	else
	{
		if(Tail(Q)<Head(Q))
		{
			while(k!=Tail(Q))
			{
				printf("%d %c\n",Prio(Elmt(Q,k)),Info(Elmt(Q,k)));
				k++;
				if(k=MaxEl(Q))
				{
					k=0;
				}
			}
			printf("#\n");
		}
		else
		{
			for (int i = Head(Q); i<=Tail(Q); i++)
			{
				printf("%d %c\n",Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
			}
			printf("#\n");
		}	
	}
}
