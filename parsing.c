/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Selasa, 14 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : parsing.c
* Deskripsi : fungsi untuk melakukan parsing dari file txt menjadi array per kata
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tipedata.h"

void append (node** head_ref, char kata_baru []) {
    // membuat linked list baru dengan memasukkan kata baru
    node* new_node = (node*)malloc(sizeof(node));
    node* last = *head_ref;
    strcpy(new_node->kata,kata_baru);
    new_node->next = NULL;

    // menambahkan linked list baru dari belakang linked list yang ada
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
        return;
    }
};

int countLen (node* head){
    int i = 0;
    while (head!=NULL){
        i++;
        head=head->next;
    }
    return i;
};

void moveArray (node* head_ref, string** array, int lenArr) {
    int i=0,j=0;
    // mengisi nilai array dari linked list per kata
    while (head_ref != NULL) {
        if (j<lenArr) {
            strcpy((*(array+i)+j)->kata,head_ref->kata);
            head_ref=head_ref->next;
        } else {
            i++;
            j=0;
            strcpy((*(array+i)+j)->kata,head_ref->kata);
            head_ref=head_ref->next;
        }
        j++;
    }
    return;
};