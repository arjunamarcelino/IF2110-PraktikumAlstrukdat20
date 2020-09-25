/*    NIM		: 13519021 */
/*    Nama		: Arjuna Marcelino */
/*    Tanggal		: 17 September 2020 */
/*    Topik praktikum	: Pra-Praktikum 4 */
/*    Deskripsi	: Berisi definisi dan semua primitif pemrosesan tabel integer */
/* 			  Penempatan elemen selalu rapat kiri */
/* 			  Versi II : dengan banyaknya elemen didefinisikan secara eksplisit, */
/*			  memori tabel dinamik */		
/*    Nama file	: arraydin.c */

#include "stdio.h"
#include "arraydin.h"
#include "stdlib.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel){
	MaxEl(*T)=maxel;
	TI(*T) = (int *) malloc ((maxel)*sizeof(int));
	Neff(*T)=0;
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */

void Dealokasi(TabInt *T){
	free(TI(*T));
	MaxEl(*T)=0;
	Neff(*T)=0;
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T){
	return(Neff(T));
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T){
	return(MaxEl(T));
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T){
	return(IdxMin);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T){
	return(IdxMin+Neff(T)-1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i){
	return((i>=IdxMin) && (i<=MaxEl(T)));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i){
	return((i>=GetFirstIdx(T)) && (i<=GetLastIdx(T)));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T){
	return(Neff(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T){
	return(Neff(T)==MaxEl(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T){
	int N;
	IdxType i;
	
	scanf("%d", &N);
	while (N<0 || N> MaxElement(*T)){
		scanf("%d", &N);
	} 
	if (N!=0){
		for (i=IdxMin;i<=IdxMin+N-1;i++){
			scanf("%d", &(Elmt(*T,i)));
		}
	}
	Neff(*T)=N;
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T){
	IdxType i;
	
	if (IsEmpty(T)){
		printf("[]");
	} else{
		printf("[");
		for (i=IdxMin;i<=GetLastIdx(T);i++){
			if (i==IdxMin){
				printf("%d", Elmt(T,i));
			} else{
				printf(",%d", Elmt(T,i));
			}
		}
		printf("]");
	}
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus){
	TabInt T3;
	MaxEl(T3)=MaxEl(T1);
	MakeEmpty(&T3,MaxEl(T3));
	IdxType i;
	
	if (plus){
		for (i=IdxMin;i<=GetLastIdx(T1);i++){
			Elmt(T3,i)=Elmt(T1,i)+Elmt(T2,i);
			Neff(T3)++;
		}
	}else {
		for (i=IdxMin;i<=GetLastIdx(T1);i++){
			Elmt(T3,i)=Elmt(T1,i)-Elmt(T2,i);
			Neff(T3)++;
		}	
	}
	return(T3);
	Dealokasi(&T3);
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2){
	IdxType i;
	boolean equal;
	
	if ((Neff(T1)==Neff(T2)) && (Neff(T1)==0)){
        equal = true;
    }else if (Neff(T1)==Neff(T2)){
        for(i=IdxMin;i<=GetLastIdx(T1);i++){
            if (Elmt(T1,i)!=Elmt(T2,i)){
                equal = false;
                break;
            }else if (i==GetLastIdx(T1)){
                equal = true;
            }
        }
    }else{
        equal = false;
    }
    return equal;
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X){
	IdxType i,IdxFound;
	
	if (IsEmpty(T)){
		IdxFound=IdxUndef;
	} else{
		for (i=IdxMin;i<=GetLastIdx(T);i++){
			if (Elmt(T,i)==X){
				IdxFound = i;
				break;
			} else if (i==GetLastIdx(T)){
				IdxFound = IdxUndef;
			}
		}
	}
	return IdxFound;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabInt T, ElType X){
	IdxType i;
	boolean found=false;
	
	if (!IsEmpty(T)){
		for (i=IdxMin;i<=GetLastIdx(T);i++){
			if (Elmt(T,i)==X){
				found=true;
				break;
			}
		}
	}
	return found;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min){
	IdxType i;
	*Max=Elmt(T,IdxMin);
	*Min=Elmt(T,IdxMin);
	
	for (i=IdxMin;i<=GetLastIdx(T);i++){
		if (Elmt(T,i)>*Max){
			*Max=Elmt(T,i);
		} if (Elmt(T,i)<*Min){
			*Min=Elmt(T,i);
		}
	}
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout){
	IdxType i;
	MaxEl(*Tout)=MaxEl(Tin);
	MakeEmpty(Tout, MaxEl(*Tout));
	
	if (!IsEmpty(Tin)){
		for (i=IdxMin;i<=GetLastIdx(Tin);i++){
			Elmt(*Tout,i)=Elmt(Tin,i);
		}
	}
	Neff(*Tout)=Neff(Tin);
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
ElType SumTab(TabInt T){
	IdxType i;
	ElType sum=0;
	
	if (!IsEmpty(T)){
		for (i=IdxMin;i<=GetLastIdx(T);i++){
			sum+=Elmt(T,i);
		}
	}
	return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX(TabInt T, ElType X){
	IdxType i;
	int count=0;
	
	if(!IsEmpty(T)){
		for (i=IdxMin;i<=GetLastIdx(T);i++){
			if (Elmt(T,i)==X){
				count++;
			}
		}
	}
	return count;
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap(TabInt T){
	IdxType i;
	boolean genap=true;
	
	if(!IsEmpty(T)){
		for (i=IdxMin;i<=GetLastIdx(T);i++){
			if (Elmt(T,i)%2!=0){
				genap=false;
				break;
			}
		}
	}
	return genap;
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc){
	IdxType Pass,i,IMax;
	ElType Temp;
	IdxType FirstIdx=GetFirstIdx(*T);
	IdxType LastIdx=GetLastIdx(*T);
	
	if (asc){
		if (Neff(*T)>1){
			for (Pass=FirstIdx+1;Pass<=LastIdx;Pass++){
				for (i=FirstIdx;i<Pass;i++){
					if (Elmt(*T,i)>Elmt(*T,Pass)){
						Temp=Elmt(*T,Pass);
						Elmt(*T,Pass)=Elmt(*T,i);
						Elmt(*T,i)=Temp;
					}
				}
			}
		}
	}else{
		if (Neff(*T)>1){
			for (Pass=FirstIdx;Pass<LastIdx;Pass++){
				IMax=Pass;
				for(i=Pass+1;i<=LastIdx;i++){
					if (Elmt(*T,IMax)<Elmt(*T,i)){
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
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X){
	if (IsEmpty(*T)){
		Elmt(*T,IdxMin)=X;
	} else{
		Elmt(*T,GetLastIdx(*T)+1)=X;
	}
	Neff(*T)++;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X){
	(*X)=Elmt(*T, GetLastIdx(*T));
	Neff(*T)--;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num){
	if (IsEmpty(*T)){
		int maxel = MaxEl(*T);
		Dealokasi(T);
		MakeEmpty(T,maxel+num);
	} else {
		TabInt T1;
		MakeEmpty(&T1,MaxEl(*T) + num);
		int i;
		for (i=IdxMin;i<=GetLastIdx(*T);i++){
			Elmt(T1,i)=Elmt(*T,i);
			Neff(T1)++;
		}
		Dealokasi(T);
		MakeEmpty(T,MaxEl(T1));
		for (i=IdxMin;i<=GetLastIdx(T1);i++){
			Elmt(*T,i) = Elmt(T1,i);
			Neff(*T)++;
		}
		Dealokasi(&T1);
	}
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num){
	TabInt T1;
	MakeEmpty(&T1,MaxEl(*T)-num);
	IdxType i;
	for (i=IdxMin;i<=GetLastIdx(*T);i++){
		Elmt(T1,i) = Elmt(*T,i);
		Neff(T1)++;
	}
	Dealokasi(T);
	MakeEmpty(T,MaxEl(T1));
	for (i=IdxMin;i<=GetLastIdx(T1);i++){
		Elmt(*T,i)=Elmt(T1,i);
		Neff(*T)++;
	}
	Dealokasi(&T1);
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T){
	TabInt T1;
	IdxType i;
	
	MaxEl(T1)=Neff(*T);
	MakeEmpty(&T1,MaxEl(T1));
	
	for (i=IdxMin;i<=GetLastIdx(*T);i++){
		Elmt(T1,i)=Elmt(*T,i);
		Neff(T1)++;
	}
	Dealokasi(T);
	MakeEmpty(T,MaxEl(T1));
	for (i=IdxMin;i<=GetLastIdx(T1);i++){
		Elmt(*T,i)=Elmt(T1,i);
		Neff(*T)++;
	}
	Dealokasi(&T1);
}
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
