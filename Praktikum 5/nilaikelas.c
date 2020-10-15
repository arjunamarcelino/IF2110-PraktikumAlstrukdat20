/*    NIM		: 13519021 */
/*    Nama		: Arjuna Marcelino */
/*    Tanggal		: 24 September 2020 */
/*    Topik praktikum	: Praktikum 5 */
/*    Deskripsi	: Program menampilkan statisik nilai */		
/*    Nama file	: nilaikelas.c */

#include "stdio.h"
#include "matriks.h"
#include "stdlib.h"
#include "math.h"

void TulisNilaiX (MATRIKS M, indeks j, ElType X)
/* Menuliskan nomor urut mahasiswa yang mendapatkan nilai X pada mata kuliah dengan nomor urut j. */
/* Pada dasarnya: Menuliskan semua indeks baris pada kolom j dengan nilai elemen = X. */
/* Nomor urut mahasiswa dituliskan dalam 1 baris, masing-masing dipisahkan koma, diawali [, diakhiri ], tanpa tambahan karakter apa pun (termasuk spasi dan enter) di awal maupun akhir */
/* I.S. M terdefinisi, j adalah indeks kolom efektif M, X terdefinisi */
/* F.S. Menuliskan semua indeks baris pada kolom j dengan nilai = X. */
/* Jika tidak ada elemen dengan nilai = X, menuliskan [] */
/* Contoh: Jika M adalah matriks 3x3 dan isinya adalah: */
/* 1 3 3 */
/* 2 5 6 */
/* 7 3 9 */
/* maka jika j = 1 dan X = 3, akan tercetak: [0,2] */
{
	int n;
	int count = 0;
	n = CountXKol (M,j,X);
	indeks i;
	if (n=0)
	{
		printf("[]");
	}
	else
	{
		printf("[");
		for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++)
		{
			if(X==Elmt(M,i,j))
			{
				printf("%d",i);
				if(count < n)
				{
					printf(",");
				}
				count = count + 1;
			}
			
		}
		printf("]");
	}
}

void TulisStatistikMhs (MATRIKS M, indeks i)
/* Menuliskan statistik untuk mahasiswa dengan nomor urut i. */
/* Statistik yang dituliskan adalah: nilai rata-rata, nilai mata kuliah tertinggi, nilai mata kuliah terendah. */
/* Pada dasarnya: menuliskan statistik untuk data pada baris ke-i */
/* I.S. M terdefinisi, i adalah indeks baris efektif M */
/* F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4 */
/* [i] <rata-rata> <nilai max> <nilai min> */
/* Contoh: Jika M adalah matriks 3x3 dan isinya adalah: */
/* 100 83 83 */
/* 72 55 60 */
/* 77 93 90 */
/* maka jika i = 1 akan tercetak: */
/* [1] 62.33 72 55 */
{
	ElType max, min;
	MaxMinBrs (M,i,&max,&min);
	printf("[");
	printf("%d",i);
	printf("] ");
	printf("%.2f", RataBrs (M, i));
	printf(" %d", max);
	printf(" %d", min);
}

void TulisStatistikMK (MATRIKS M, indeks j)
/* Menuliskan statistik untuk mata kuliah dengan nomor urut j. */
/* Statistik yang dituliskan adalah: nilai rata-rata, nilai tertinggi (berikut berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya), nilai mata kuliah terendah (berikut //berapa banyak yang memperoleh nilai tersebut dan siapa saja yang memperolehnya) */
/* Pada dasarnya: menuliskan statistik untuk data pada kolom ke-j } */
/* I.S. M terdefinisi, j adalah indeks kolom efektif M } */
/* F.S. Statistik data M pada baris i tercetak di layar dengan format sbb:4 */
/* [j] <rata-rata> [max <nilai max> <#max> [<daftar max>]] [min <nilai min> <#min> [<daftar min>]] */
/* Contoh: Jika M adalah matriks 3x3 dan isinya adalah: */
/* 100 83 83 */
/* 72 55 60 */
/* 77 93 90 */
/* maka jika j = 1 akan tercetak: */
/* [1] 77.00 [93 1 [2]] [55 1 [1]] */
{
	ElType max, min;
	MaxMinKol (M,j,&max,&min);
	printf("[");
	printf("%d",j);
	printf("] ");
	printf("%.2f", RataKol(M,j));
	printf(" [");
	printf("%d",max);
	printf(" %d ",CountXKol (M,j,max));
	TulisNilaiX (M,j,max);
	printf("]");
	printf(" [");
	printf("%d",min);
	printf(" %d ",CountXKol (M,j,min));
	TulisNilaiX (M,j,min);
	printf("] ");
}

int main ()
{
	int siswa, pelajaran;
	MATRIKS M;
	indeks i,j;
	
	scanf("%d",&siswa);
	scanf("%d",&pelajaran);
	BacaMATRIKS (&M,siswa,pelajaran);
	
	printf("STATISTIK PER MAHASISWA\n");
	for (i=0;i<siswa;i++)
	{
		TulisStatistikMhs (M,i);
		printf("\n");
	}
	printf("STATISTIK PER MATA KULIAH\n");
	for (j=0;j<pelajaran;j++)
	{
		TulisStatistikMK (M,j);
		printf("\n");
	}
	return 0;
}

