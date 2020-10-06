/* NIM			: 13519021 */
/* Nama		: Arjuna Marcelino */
/* Tanggal		: 17 September 2020 */
/* Topik praktikum	: Praktikum 4 */
/* Nama file		: marraydin.c */
/* Deskripsi		: sebuah program yang digunakan untuk membaca sebuah TabInt, misalnya T, */
/* dengan kapasitas awal MaxEl, lalu membaca elemen-elemen T dari keyboard sebanyak N. N harus */
/* bernilai 0 <= N <= MaxNbEl(T). Program akan membaca sebuah bilangan Q. Lalu, program akan */
/* membaca Q buah bilangan op. */

#include "arraydin.c"
#include "stdio.h"
#include "stdlib.h"

int main ()
{
	TabInt T;
	int Q, i, op, maxel;
	ElType num;
	
	scanf("%d",&maxel);
	MakeEmpty(&T,maxel);
	
	BacaIsi(&T);
	scanf("%d",&Q);
	i=1;
	for (i;i<=Q;i++)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d",&num);
			if(Neff(T)==maxel)
			{
				printf("array sudah penuh");
			}
			else
			{
				AddAsLastEl(&T, num);
				printf("%d",MaxEl(T));
				TulisIsiTab(T);
			}
			printf("\n");
		}
		else if (op==2)
		{
			scanf("%d",&num);
			GrowTab(&T, num);
			printf("%d",MaxEl(T));
			TulisIsiTab(T);
			printf("\n");
			
		}
		else if (op==3)
		{
			scanf("%d",&num);
			if(maxel<num)
			{
				printf("array terlalu kecil");
			}
			else
			{
				ShrinkTab(&T, num);
				printf("%d",MaxEl(T));
				TulisIsiTab(T);
			}
			printf("\n");
		}
		else if(op==4)
		{
			CompactTab(&T);
			printf("%d",MaxEl(T));
			TulisIsiTab(T);
			printf("\n");
		}
	}
	

	return 0;
}
