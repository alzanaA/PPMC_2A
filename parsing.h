/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Selasa, 14 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : parsing.h
* Deskripsi : header untuk parsing.c
*/

#ifndef PARSING_H
#define PARSING_H
#include "tipedata.h"

void append (node** head_ref, char kata_baru []);
/* prosedur ini akan membuat linked list baru yang berisi kata baru
   dan menambahkan nya pada linked list yang dituju dari belakang
*/

int countLen (node* head);
/* fungsi ini akan menghitung jumlah kata yang ada dari text
   dan akan mengeluarkan nilai jumlah kata tersebut 
   untuk dipakai sebagai jumlah array yang akan dibuat selanjutnya
*/

void moveArray (node* head_ref, string** array, int lenArr);
/* prosedur ini akan memindahkan kata yang sudah di parsing dengan spasi
   dan sudah dimasukkan ke dalam linked list ke dalam array per kata 
   2 dimensi yang menyesuaikan jumlah kata yang ada
*/

#endif