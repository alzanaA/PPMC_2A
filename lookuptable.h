/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : lookuptable.h
* Deskripsi : header untuk lookuptable.c
*/

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include "tipedata.h"

void printList(struct node *node);
void printQueue(struct Queue *q);
table* new_node(char k [], node *v);
struct Queue* new_queue();
void enqueue(struct Queue* q, char k [], node* v);
bool isSame(node* head_list, char k[]);
int removeDuplicate(table** temp, string** key, string **value, int len);
void makeTable(struct Queue* LUT, string** key, string **value, int len);

#endif