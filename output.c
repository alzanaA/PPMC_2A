/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : output.c
* Deskripsi : Fungsi untuk output data dari LUT yang ada
* Untuk menggunakan program cukup panggil output(n pada n-gram, banyaknya kata, queue database)

note : bagian bawah ada fungsi main untuk test, tapi perlu copy definisi struct
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "output.h"
#include "tipedata.h"


int search(struct table * LUT, char * p)
// mencari indeks key yang sesuai
{
    // is found
    if(strcmp(p,LUT->key)==0){
        return 0;
    } else if((LUT==NULL)||(LUT->next==NULL)) {// is last
        return 0;
    } else { // Next element
        return 1 + search(LUT->next,p);
    }
}

char* getKey(struct table * LUT, int index)
// mengekstrak key dari lut berdasar indeks
{
    if(index != 0){
        return getKey(LUT->next, index - 1);
    } else {
        return LUT->key;
    }
}

struct node * getValueRand(node * value, node * current, int word_index)
// membantu mengekstrak satu value acak dari list yang diberikan
{
    if(word_index == 0){    // kondisi ditemukan
        return current;
    } else {                // belum ditemukan
        if(current->next == NULL){      // kembali ke depan list
            return getValueRand(value, value, word_index-1);
        } else {                        // begeser list
            return getValueRand(value, current->next, word_index-1);
        }
    }
}

char* getValue(struct table * LUT, int index, int m)
// mengekstrak value dari key yang ada
{
    int word_index;
    if(index != 0){
        return getValue(LUT->next, index - 1, m);
    } else {
        node * buff_value;
        word_index = rand() % m;
        // cari angka acak
        buff_value = getValueRand(LUT->value, LUT->value, word_index);
        return buff_value->kata;
    }
}


void output(int n, int m, struct Queue * database)
// fungsi yang akan mencetak hasil n-gram, hanya fungsi ini yang perlu
// dipanggil dari luar
{
    table * LUT = database->front;
    int i;
    srand(time(0));
    
    // buffer n kata
    char buffer[1000];
    char value[1000];

    // ambil n kata random
    int word_index = rand() % n;
    strcpy(buffer, getKey(LUT, word_index));

    // cetak n kata
    printf(". . . %s",buffer);

    // loop
    char* token;
    char* bufferNew = (char*)calloc(1000,sizeof(char));;
    char* rest;

    for(i = 0; i<m-n; i++){
        // cari key n
        word_index = search(LUT, buffer);

        // ambil value
        strcpy(value, getValue(LUT, word_index, m));

        // cetak n
        printf(" %s",value);

        // update buffer
        rest = buffer;

        free(bufferNew);
        bufferNew = (char*)calloc(1000,sizeof(char));

        token = strtok_r(rest," ",&rest);
        while(token = strtok_r(rest," ",&rest))
        {
            strcat(bufferNew,token);
            strcat(bufferNew," ");
        }

        strcat(bufferNew, value);
        strcpy(buffer,bufferNew);
    }

    // penutup
    printf(" . . .",buffer);
}

/*

////    TEST UNIT     //////////

int main(void){
    // buat database
    struct Queue * database = (struct Queue *)malloc(sizeof(struct Queue));

    // 5 x
    table * a = (table*) malloc(sizeof(struct table));
    table * b = (table*) malloc(sizeof(struct table));
    table * c = (table*) malloc(sizeof(struct table));
    table * d = (table*) malloc(sizeof(struct table));
    table * e = (table*) malloc(sizeof(struct table));
    table * f = (table*) malloc(sizeof(struct table));
    table * g = (table*) malloc(sizeof(struct table));

    // printf("====================== %d",a);

        // value
        strcpy(a->key,"tidak seperti");
        node * valuea = (node*)malloc(sizeof(node));
            strcpy(valuea->kata, "anggapan");
            valuea->next = NULL;
        a->value = valuea;
    // printf("\n====================== tag 1 %d",valuea);
        a->next = b;
        // value
        strcpy(b->key,"seperti anggapan");
        node * valueb = (node*)malloc(sizeof(node));
            strcpy(valueb->kata, "banyak");
            valueb->next = NULL;
        b->value = valueb;
        b->next = c;
        // value
        strcpy(c->key,"anggapan banyak");
        node * valuec = (node*)malloc(sizeof(node));
        node * valuecc = (node*)malloc(sizeof(node));
            strcpy(valuec->kata, "orang");
                valuec->next = valuecc;
            strcpy(valuecc->kata, "manusia");
                valuecc->next = NULL;
        c->value = valuec;
        c->next = d;
        // value
        strcpy(d->key,"banyak orang");
        node * valued = (node*)malloc(sizeof(node));
            strcpy(valued->kata, "tidak");
            valued->next = NULL;
        d->value = valued;
        d->next = e;
        // value
        strcpy(e->key,"banyak manusia");
        node * valuee = (node*)malloc(sizeof(node));
            strcpy(valuee->kata, "tidak");
            valuee->next = NULL;
        e->value = valuee;
        e->next = f;
        // value
        strcpy(f->key,"orang tidak");
        node * valuef = (node*)malloc(sizeof(node));
            strcpy(valuef->kata, "seperti");
            valuef->next = NULL;
        f->value = valuef;
        f->next = g;
        // value
        strcpy(g->key,"manusia tidak");
        node * valueg = (node*)malloc(sizeof(node));
            strcpy(valueg->kata, "seperti");
            valueg->next = NULL;
        g->value = valueg;
        g->next = NULL;
    // printf("\n====================== tag 2 %d",f->value);
        
    
    
    database->front = a;
    database->rear = g;

    
    // printf("\n====================== tag 3 %d",database->front);

    // run
    output(2,20, database);

    // printf("\n====================== tag 4 %d",valuea);

    return 0;
} */