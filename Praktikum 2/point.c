/* File: point.c */
/* Tanggal: 3 September 2020 */

#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"

const float PI =3.14;

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/**** Konstruktor membuat POINT ****/
POINT MakePOINT (float X, float Y)
/* Membentuk sebuah point dari x dan y dengan x sebagai absis dan y sebagai ordinat */
{ /* KAMUS */
  POINT P;
  /* ALGORITMA */
  Absis(P) = X;
  Ordinat(P) = Y;
  return P;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT * P)
/* Membentuk P dari x dan y yang dibaca dari keyboard */
{ /* KAMUS */
  float X, Y;
  /* ALGORITMA */
  scanf("%f", &X);
  scanf("%f", &Y);
  *P = MakePOINT(X,Y);
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dg format "(X,Y)" */
{ /* ALGORITMA */
  printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
} 

float GetAbsis (POINT P)
{
    return (Absis(P));
}
float GetOrdinat (POINT P)
{
    return (Ordinat(P));
}

void SetAbsis (POINT *P, float NewX)
{
    (*P).X=NewX;
}
void SetOrdinat (POINT *P, float NewY)
{
    (*P).Y=NewY;
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{ /* ALGORITMA */
  return ((P1.X==P2.X) && (P1.Y==P2.Y));
} 
boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{ /* ALGORITMA */
  return ((P1.X!=P2.X) || (P1.Y!=P2.Y));
} 

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{ /* ALGORITMA */
  return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{ /* ALGORITMA */
  return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{ /* ALGORITMA */
  return (Absis(P) == 0);
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{ /* ALGORITMA */
  int K;
  if (P.X>0 && P.Y>0)
  {
      K=1;
  }
  else if (P.X<0 && P.Y>0)
  {
      K=2;
  }
  else if (P.X<0 && P.Y<0)
  {
      K=3;
  }
  else //P.X>0 P.Y<0
  {  
      K=4;
  }
  return K;
}
	

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
  SetAbsis(&P, P.X+1);
  return P;
}

POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
  SetOrdinat(&P, P.Y+1);
  return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
  SetAbsis(&P, P.X+deltaX);
  SetOrdinat(&P, P.Y+deltaY);
  return P;
}

POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
   if (SbX) 
   {
      SetOrdinat(&P, (-P.Y));
      if (Ordinat(P)==-0)
      {
         Ordinat(P)=Ordinat(P)*(-1);
      }
   }   
   else  //sumbu y 
   {
      SetAbsis(&P, (-P.X));
      if (Absis(P)==-0)
      {
         Absis(P)=Absis(P)*(-1);
      }
   }
   return P;
}

float Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
    return(sqrt((P.X*P.X)+(P.Y*P.Y)));
}

float Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{
    float PanjangX=P2.X-P1.X;
    float PanjangY=P2.Y-P1.Y;
    float Sum=sqrt((PanjangX*PanjangX)+(PanjangY*PanjangY));

    return (Sum);
}

void Geser (POINT *P, float deltaX, float deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
    (*P)=PlusDelta(*P, deltaX, deltaY);
}

void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
    SetAbsis(P, 0);
}

void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
    SetOrdinat(P, 0);
}

void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
    *P=MirrorOf(*P,SbX);
}

void Putar (POINT *P, float Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) searah jarum jam*/
{
    float newX, newY;
    Sudut=Sudut*PI/180;

    newX=(*P).X*cos(Sudut)-(*P).Y*sin(Sudut);
    newY=(*P).Y*cos(Sudut)+(*P).X*sin(Sudut);

    (*P).X=newX;
    (*P).Y=newY;

}
