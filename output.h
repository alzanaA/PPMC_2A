/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : output.h
* Deskripsi : Header dari fungsi untuk output data dari LUT yang ada
*/

#ifndef OUTPUT_H
#define OUTPUT_H

#include "tipedata.h"


void output(int n, int m, struct Queue * database);
int search(struct table * LUT, char * p);
char* getValue(struct table * LUT, int index, int m);
char* getKey(struct table * LUT, int index);
node * getValueRand(node * value, node * current, int word_index);

#endif