/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : tipedata.h
* Deskripsi : deklarasi tipe data struct
*/

#ifndef TIPEDATA_H
#define TIPEDATA_H

// struct untuk array per kata, key, dan value
typedef struct arrayofstring {
    char kata [1000];
}string;

// struct untuk linked list per kata
typedef struct node {
    char kata [1000];
    struct node* next;
}node;

//struct untuk array elemen lookup table
typedef struct table {
    char key [1000];
    node* value;
    struct table* next;
}table;

//linked list lookup table
struct Queue { 
	struct table *front, *rear; 
}; 

#endif
