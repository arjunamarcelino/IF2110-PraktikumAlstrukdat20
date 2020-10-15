/* Nama : Arjuna Marcelino */
/* NIM : 13519021 */
/* Tanggal : 8 Oktober 2020 */
/* Topik Praktikum : Praktikum 7 */
/* File: packet.c */
/* Deskripsi :	Program Anda akan menuliskan packet yang diterima sesegera mungkin, beserta dengan detik ia ditulis. Namun apabila packet ke-i belum diterima, tentu packet ke-(i+1) dan seterusnya tidak akan bisa ditulis.*/

#include <stdio.h>
#include "prioqueuechar.h"

int main()
{
	PrioQueueChar Q;
	infotype X;
	int N, detik, num;
	
	scanf("%d", &N);
	MakeEmpty (&Q, N);
	
	detik = 1;
	num = 1;
	
	for (int i = 0; i<N; i++)
	{
		scanf("%d %c",&Prio(X), &Info(X));
		Enqueue(&Q,X);
		
		if (Prio(X) == detik)
		{
			for (int j = Head(Q); Prio(Elmt(Q,j)) == num; j = (j%MaxEl(Q)+1))
			{
				printf("%d %c\n", (i+1), Info(Elmt(Q,j)));
				Dequeue(&Q,&X);
				num = num + 1;
			}
			detik = num;
		}
	}
	return 0;	
}
