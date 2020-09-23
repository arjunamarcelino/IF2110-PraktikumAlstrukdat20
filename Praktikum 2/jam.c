/* File: jam.c */
/* Tanggal: 3 September 2020 */
/* Definisi ADT JAM */

#include <stdio.h>
#include "jam.h"
#include "boolean.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
  return (((H>=0)&&(H<24))&&((M>=0)&&(M<60))&&((S>=0)&&(S<60)));
}

//*Selektor*//
int GetHour(JAM J)
{
    return (J.HH);
}

int GetMinute(JAM J)
{
    return (J.MM);
}

int GetSecond(JAM J)
{
    return (J.SS);
}

//*perubahan nilai*//
void SetHH(JAM* J, int newHH)
{
    (*J).HH=newHH;
}

void SetMM(JAM* J, int newMM)
{
    (*J).MM=newMM;
}

void SetSS(JAM* J, int newSS)
{
    (*J).SS=newSS;
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
   JAM J;

   SetHH(&J, HH);
   SetMM(&J, MM);
   SetSS(&J, SS);

   return J;
}


/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
   int HH, MM, SS;
   boolean valid = false;

   while (!valid)
   {
     scanf("%d %d %d", &HH, &MM, &SS);

     if (IsJAMValid(HH, MM, SS))
        {
            *J=MakeJAM(HH, MM, SS);
            valid = true;
        }
   }
}


void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */
{
    printf("%d:%d:%d\n", J.HH, J.MM, J.SS);
}


/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return((J.HH*3600)+(J.MM*60)+(J.SS));
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
    JAM J;
    if (N>86400)
    {
        N=N%86400;
    }
    J = MakeJAM((N/3600), ((N%3600)/60), ((N%3600)%60)) ;
    return J;
}


/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
    return(JAMToDetik(J1)==JAMToDetik(J2));
}

boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return(JAMToDetik(J1)!=JAMToDetik(J2));
}

boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
    return(JAMToDetik(J1)<JAMToDetik(J2));
}

boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
    return(JAMToDetik(J1)>JAMToDetik(J2));
}

/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    J.SS++;
    if (J.SS==60) 
    {
     J.SS=0;
     J.MM+=1;
     if (J.MM==60)
     {
        J.MM=0;
        J.HH+=1;
        if (J.HH==24)
        {
            J.HH=0;
        }
     }
    }
    return J;
}


JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    int i;
    for(i=1;i<=N;i++)
    {
        J=NextDetik(J);
    }

    return J;
}

JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
    J.SS--;
    if (J.SS==(-1))
    {
        J.SS=59;
        J.MM--;
        if (J.MM==(-1))
        {
            J.MM=59;
            J.HH--;
            if (J.HH==(-1)) 
            {
                J.HH=23;
            }
        }
    }

    return J;
}

JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
{
     int i;
     for(i=1;i<=N;i++)
     {
        J=PrevDetik(J);
     }

    return J;
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    if (JAMToDetik(JAw) > JAMToDetik(JAkh)) 
    { //BedaHari
        return (24*3600-(JAMToDetik(JAw)-JAMToDetik(JAkh)));
    } 
    else 
    {
        return (JAMToDetik(JAkh)-JAMToDetik(JAw));
    }
}
