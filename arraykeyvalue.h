/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Selasa, 14 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : arraykeyvalue.h
* Deskripsi : header untuk arraykeyvalue.c
*/

#ifndef ARRAYKEYVALUE_H
#define ARRAYKEYVALUE_H
#include "tipedata.h"

void makeKey (string** word, string** key, int len, int n, int lenList);
/* prosedur ini akan membuat array key yang dimensi nya sama dengan array per kata 
   sesuai metode n-gram namun masih ada nilai pada array key yang kosong 
   karena jumlah kata tidak selalu hasil dari pangkat nilai integer 
   dan key yang sama masih terpisah
*/

void makeValue (string** word, string** value, int len, int n, int lenList);
/* prosedur ini akan membuat array value yang dimensi nya sama dengan array per kata 
   sesuai metode n-gram namun masih ada nilai pada array key yang kosong 
   karena jumlah kata tidak selalu hasil dari pangkat nilai integer
   dan value yang sama masih terpisah
*/

#endif