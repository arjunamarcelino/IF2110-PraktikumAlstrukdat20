/* NIM				: 13519021 */
/* Nama				: Arjuna Marcelino */
/* Tanggal			: 5 November 2020 */
/* Topik praktikum	: Praktikum 9 */
/* Nama file		: listlinier.c */
/* Deskripsi		: Implementasi listlinier.h */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return (First(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L)=Nil;	
}


/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P;

	P = malloc (1*sizeof(infotype));
	if(P!=Nil)
	{
		Info(P)=X;
		Next(P)=Nil;
	}
	return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	address P;

	P=First(L);
	if(P!=Nil)
	{
		while((Info(P)!=X) && (Next(P)!=Nil))
		{
            P=Next(P);
        }
        if (Info(P)!=X)
        {
            P=Nil;
        }
	}
	return P;
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	address A;
	boolean cek;

	A=First(L);
	cek = false;
	while ((A != Nil) && (!cek))
	{
		if(A==P)
		{
			cek = true;
		}
		else
		{
			A = Next(A);
		}
	}
	return cek;
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
    address Prec;
    address P;

    boolean found = false;

    Prec = Nil;
    
    P = First(L);
    while ((P != Nil) && (!found)) 
    {
        if (Info(P) == X) 
        {
            found = true;
        }
        else 
        {
            Prec = P;
            P = Next(P);
        }
    }

    if (!found) 
    {
        Prec = Nil;
    }
  
    return Prec;
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P;

    if (IsEmpty(*L))
    {
        First(*L)=Alokasi(X);
    }
    else
    {
        P=Alokasi(X);
        Next(P)=First(*L);
        First(*L)=P;
    }
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P, Padr;

    if (IsEmpty(*L))
    {
        First(*L)=Alokasi(X);
    }
    else
    {
        P=Alokasi(X);
        Padr=First(*L);
        while (Next(Padr)!=Nil)
        {
            Padr=Next(Padr);
        }
        Next(Padr)=P;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P;

    P=First(*L);
    (*X)=Info(P);
    First(*L)=Next(P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P, seclastP;

    P=First(*L);
    if (Next(P)==Nil)
    {
        DelVFirst(L, X);
    }
    else
    {
        while (Next(P)!=Nil)
        {
            seclastP=P;
            P=Next(P);
        }
        Next(seclastP)=Nil;
        *X=Info(P);
    } 
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P)=First(*L);
    First(*L)=P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P)=Next(Prec);
    Next(Prec)=P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address lastP=First(*L);

    if (!IsEmpty(*L))
    {
        while(Next(lastP)!=Nil)
        {
            lastP=Next(lastP);
        }
        Next(lastP)=P;
    }
    else
    {
        First(*L)=P;
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
    First(*L)=Next(*P);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address seclastP, P;

    P=First(*L);
    if (!IsEmpty(*L))
    {
        if (Info(P)==X)
        {
            First(*L)=Next(P);
            Dealokasi(&P);
        }
        else
        {
            while(Next(P)!=Nil && Info(P)!=X)
            {
                seclastP=P;
                P=Next(P);
            }
            if (Info(P)==X)
            {
                Next(seclastP)=Next(P);
                Dealokasi(&P);
            }
        }     
    }
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address lastP=First(*L);
    address seclastP;

    if(Next(lastP)==Nil)
    {
        *P=lastP;
        First(*L)=Nil;
    }
    else
    {
        while (Next(lastP)!=Nil)
        {
            seclastP=lastP;
            lastP=Next(lastP);
        }
        *P=lastP;
        Next(seclastP)=Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    address P;

    P=First(*L);
    while(P!=Prec)
    {
        P=Next(P);
    }
    if (Next(P)!=Nil)
    {
        *Pdel=Next(P);
        Next(P)=Next(*Pdel);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P=First(L);

    printf("[");
    while (P!=Nil)
    {
        if (P==First(L))
        {
            printf("%d", Info(P));
        }
        else
        {
            printf(",%d", Info(P));
        }
        P=Next(P);
    }
    printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    address P=First(L);
    int NBELMT=0;

    while (P!=Nil)
    {
        NBELMT++;
        P=Next(P);
    }

    return NBELMT;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
    address P=First(L);
    infotype MAX=Info(P);

    while (Next(P)!=Nil)
    {
        P=Next(P);
        if(Info(P)>MAX)
        {
            MAX=Info(P);
        }
    }

    return MAX;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{
    return (Search(L, Max(L)));
}

infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
    address P=First(L);
    infotype MIN=Info(P);

    while (Next(P)!=Nil)
    {
        P=Next(P);
        if(Info(P)<MIN)
        {
            MIN=Info(P);
        }
    }

    return MIN;
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{
    return (Search(L, Min(L)));
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{
    address P=First(L);
    int Sum;
    int count;

    Sum = 0;
    count =0;
    while (Next(P)!=Nil)
    {
        P=Next(P);
        Sum += Info(P);
        count +=1; 
    }
    return (Sum/count);
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{
    address P;

    while (IsEmpty(*L) == false) 
    {
        DelFirst(L, &P);
        Dealokasi(&P);
    }
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{
    address P = First(*L);
    address Prec = Nil;
    address Last;

    while (P != Nil) 
    {
        Last = P;
        P = Next(P);
        Next(Last) = Prec;
        Prec = Last;
    }
    
    First(*L) = Last;
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List L1;

    CpAlokList(L, &L1);
    InversList(&L1);

    return L1;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{
	First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{
    List L1;
    address P = First(L);
    address P1;
    boolean cek = false;

    CreateEmpty(&L1);

    while ((P != Nil) && (!cek)) 
    {
        P1 = Alokasi(Info(P));
        if (P1 != Nil) 
        {
            InsertLast(&L1, P1);
            P = Next(P);
        }
        else 
        {
            cek = true;
            DelAll(&L1);
        }
    }

    return L1;
}
void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{
	*Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{
    address P;

    if (First(L1) == Nil) 
    {
        CpAlokList(L2, L3);
    }
    else 
    {
        CpAlokList(L1, L3);
        P = First(*L3);
        while (Next(P) != Nil) 
        {       	
        	P= Next(P);
        }
        Next(P) = First(L2);
    }
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address lastP;

    CreateEmpty(L3);
    if (IsEmpty(*L1))
    {
        First(*L3)=First(*L2);
    }
    else
    {
        First(*L3)=First(*L1);
        if (!IsEmpty(*L2))
        {
            lastP=First(*L1);
            while (Next(lastP)!=Nil)
            {
                lastP=Next(lastP);
            }
            Next(lastP)=First(*L2);
        }
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{
    int i;
    address P;

    CpAlokList(L, L1);
    CpAlokList(L, L2);

    if ((NbElmt(L) % 2) == 1) 
    { 
        for (i=1; i<= ((NbElmt(L) + 1) /2); i++) 
        {
            DelLast(L1, &P);
        }
        for (i=1; i<= ((NbElmt(L) - 1) /2); i++) 
        {
            DelFirst(L2, &P);
        }
    }
    else 
    {
        for (i=1; i<= ((NbElmt(L)) /2); i++) 
        {
            DelLast(L1, &P);
            DelFirst(L2, &P);
        }
    }
}