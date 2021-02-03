/* Nama 		: Arjuna Marcelino */
/* NIM 		: 13519021 */
/* Tanggal 		: 22 Oktober 2020 */
/* Topik Praktikum 	: Praktikum 8*/
/* File		: ekspresi.c */
/* Deskripsi 		: Membaca sebuah pita karakter yang hanya berisi bilangan positif dan 0 serta operator ’+’, ’-’, ’*’, ’/’, dan ’^’ yang membentuk sebuah ekspresi aritmatika dalam notasi postfix dan mengevaluasi ekspresi yang terdapat pada pita karakter tersebut. */

#include "mesintoken.h"
#include "stackt.h"
#include <math.h>
#include <stdio.h>

#define MARK '.'


boolean IsOperator (Token CToken) 
{
	return ((CToken.tkn=='+')||(CToken.tkn=='-')||(CToken.tkn=='*')||(CToken.tkn=='/')||(CToken.tkn=='^'));
}

int Hitung (Token OP1, Token OP2, Token Operator)
{
	int hasil;
	int num1,num2;
	num1 = OP1.val;
	num2 = OP2.val;
	if ((Operator.tkn)=='+')
	{
		hasil = num1 + num2;
	}
	else if ((Operator.tkn)=='-')
	{
		hasil = num1 - num2;
	}
	else if ((Operator.tkn)=='*')
	{
		hasil = num1 * num2;
	}
	else if ((Operator.tkn)=='/')
	{
		hasil = num1/num2;
	}
	else if ((Operator.tkn)=='^')
	{
		hasil = pow(num1,num2);
	}
	
	return hasil;
}

int main()
{
	Stack S;
	CreateEmpty (&S);
	Token CToken,OP1,OP2;
	
	STARTTOKEN();
	if(EndToken)
	{
		printf("Ekspresi kosong\n");
	}
	else
	{
		while(!EndToken)
		{
			if (IsOperator(CToken))
			{
				Pop(&S,&OP2.val);
				Pop(&S,&OP1.val);
				Push(&S,Hitung(OP1,OP2,CToken));
				printf("%d %c %d \n",OP1.val,OP2.val,CToken.tkn);
			}
			else
			{
				Push(&S,CToken.val);
				printf("%d \n",CToken.val);
			}
			IgnoreBlank();
			ADVTOKEN();
		}
		printf("Hasil=%d \n",InfoTop(S));
	}
	return 0;
}
