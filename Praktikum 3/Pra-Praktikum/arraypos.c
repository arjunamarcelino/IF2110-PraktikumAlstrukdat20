/*    NIM		: 13519021 */
/*    Nama		: Arjuna Marcelino */	
/*    Tanggal		: 09 September 2020 */
/*    Topik praktikum	: Pra-Praktikum 2 */
/*    Deskripsi	: arraypos.c */

#include <stdio.h>
#include "arraypos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	IdxType i;
	for (i=IdxMin;i<=IdxMax; i++)
	{
		Elmt(*T,i)=ValUndef;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	int a=0;
	IdxType i;
	for (i=IdxMin; i<=IdxMax; i++)
	{
		if (Elmt(T,i)!=ValUndef)
		{
			a++;
		}
	}
	return a;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return (IdxMax-IdxMin+1);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return (IdxMin);
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	return (IdxMin+NbElmt(T)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return ((i>=IdxMin) && (i<=IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return ((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
	return(NbElmt(T)==0);
}


boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return(NbElmt(T)==100);
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{
	int N;
    	IdxType i;

    	scanf("%d", &N);
    	while (N<0 || N>MaxNbEl(*T))
    	{
        	scanf("%d", &N);
    	}
    	if (N!=0)
    	{
        	for (i=IdxMin;i<=IdxMin+N-1;i++)
        	{
            		scanf("%d", &(Elmt(*T,i)));
        	}
    	}

}


void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
    IdxType i;

    if (IsEmpty(T))
    {
        printf("[]");
    }
    else 
    {
        printf("[");
        for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++)
        	{
            		if (i==GetFirstIdx(T))
            		{
                		printf("%d", Elmt(T,i));
            		}
            		else 
            		{
                		printf(",%d", Elmt(T,i));    
            		}
            
        	}
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

{
	TabInt T3;
    	IdxType FirstIdx=GetFirstIdx(T1);
    	IdxType LastIdx=GetLastIdx(T1);
    	IdxType i;
	
	if (!plus)
	{
		for (i=FirstIdx;i<=LastIdx;i++)
		{
        		Elmt(T3,i)=Elmt(T1,i)-Elmt(T2,i);
    		}
	}
	else if (plus)
	{
    		for (i=FirstIdx;i<=LastIdx;i++)
    		{
        		Elmt(T3,i)=Elmt(T1,i)+Elmt(T2,i);
    		}
    	}
    	return (T3);
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	IdxType FirstIdx=GetFirstIdx(T1);
    	IdxType LastIdx=GetLastIdx(T1);
    	IdxType i;

    	if ((NbElmt(T1)==NbElmt(T2)) && (NbElmt(T1)==0))
    	{
        	return true;
    	}
    	else if (NbElmt(T1)==NbElmt(T2))
    	{
        	for(i=FirstIdx;i<=LastIdx;i++)
        	{
            		if (Elmt(T1,i)!=Elmt(T2,i))
            		{
                		return false;
                		break;
            		}
            		else if (i==LastIdx)
            		{
                		return true;
            		}
        	}
    	}
    	else
    	{
        	return false;
    	}
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */

{
    	IdxType IdxF, i;

    	if (IsEmpty(T)) /*Tabel kosong*/
    	{                                             
        	IdxF=IdxUndef;
    	}
    	else /*Tabel tidak kosong*/
    	{                                                       
        	for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++) 
        	{             
            		if (Elmt(T,i)==X) /*Jika X ketemu*/
            		{                                   
                		IdxF=i;
                		break;
            		}
            		else if (i==GetLastIdx(T)) /*Jika X tidak ketemu*/
            		{                         
                		IdxF=IdxUndef;
            		}
        	}
    	}
    	return IdxF;
}

boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

{
	boolean Found=false;
    	IdxType i;


    	for(i=GetFirstIdx(T);i<=GetLastIdx(T);i++)
    	{
        	if (Elmt(T,i)==X)
        	{
            		Found=true;
            		break;
        	}
    	}
    	return Found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{
	IdxType i;
    	(*Max)=Elmt(T,GetFirstIdx(T));
    	(*Min)=Elmt(T,GetFirstIdx(T)); 

    	if (NbElmt(T)>1)
    	{
        	for (i=GetFirstIdx(T)+1;i<=GetLastIdx(T);i++)
        	{
            		if (Elmt(T,i)>*Max)
            		{
                		*Max=Elmt(T,i);
            		}
            		if (Elmt(T,i)<*Min)
            		{
                		*Min=Elmt(T,i);
            		}
        	}	
    	}
}


/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
	ElType Sum=0;
	IdxType i;
	
	if (!IsEmpty(T))
	{
		for (i=IdxMin;i<=GetLastIdx(T);i++)
		{
			Sum+=Elmt(T,i);
		}
	}
	return Sum;
}


int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	int Count=0;
	IdxType i;
	
	if (!IsEmpty(T))
	{
		for (i=IdxMin;i<=GetLastIdx(T);i++)
		{
			if (Elmt(T,i)==X)
			{
				Count++;
			}
		}
	}
	return Count;
}

boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{
	IdxType i;
	boolean Genap=true;
	
	if (!IsEmpty(T))
	{
		for (i=IdxMin;i<=GetLastIdx(T);i++)
		{
			if (Elmt(T,i)%2!=0)
			{
				Genap=false;
			}
		}
	}
	return Genap;
}

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
	IdxType Pass, i, IMax;
    	ElType Temp;
    	IdxType FirstIdx=GetFirstIdx(*T);
    	IdxType LastIdx=GetLastIdx(*T);
	
	
	if (asc)
	{
		if (NbElmt(*T)>1)
		{
			for (Pass=FirstIdx+1;Pass<=LastIdx;Pass++)
			{
				for (i=FirstIdx;i<Pass;i++)
				{
					if (Elmt(*T,i)>Elmt(*T,Pass))
					{
						Temp=Elmt(*T,Pass);
						Elmt(*T,Pass)=Elmt(*T,i);
						Elmt(*T,i)=Temp;
					}
				}
			}
		}
	}
	else
	{
		if (NbElmt(*T)>1)
		{
			for (Pass=FirstIdx;Pass<LastIdx;Pass++)
			{
				IMax=Pass;
				for(i=Pass+1;i<=LastIdx;i++)
				{
					if (Elmt(*T,IMax)<Elmt(*T,i))
					{
						IMax=i;
					}
				}

				Temp=Elmt(*T,Pass);
				Elmt(*T,Pass)=Elmt(*T,IMax);
				Elmt(*T,IMax)=Temp;
			}
		}
	}

}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

{
	if (IsEmpty(*T))
	{
        	Elmt(*T,GetFirstIdx(*T))=X;
    	}
    	else 
    	{
        	Elmt(*T,GetLastIdx(*T)+1)=X;
    	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	(*X)=Elmt(*T,GetLastIdx(*T));
	Elmt(*T,GetLastIdx(*T))=ValUndef;
}
