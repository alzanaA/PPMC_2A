/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : README.md
* Deskripsi : tipe data yang digunakan
/*
# PPMC_2A
Pengerjaan Tugas Besar PPMC oleh Kelompok 2A

Tipe data:

typedef struct arrayofstring {
    char kata [1000];
}string;

typedef struct node {
    char kata [1000];
    struct node* next;
}node;

typedef struct table{
    char key [1000];
    node* value;
    table* next;
}table;

struct Queue{
    table *front, *rear;
};
