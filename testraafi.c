/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : testraafi.c
* Deskripsi : Tester untuk membuat array key dan array value dari file txt
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "parsing.h"
#include "arraykeyvalue.h"
#include "tipedata.h"

int main () {
    //variabel
    
    // linkedlist untuk menyimpan parsing per kata
    node* list = (node*)malloc(sizeof(node)); 
    list = NULL;

    // input dari user
    char input [1000];
    int n;
    FILE* f;
    // input nama file txt
    printf("Masukkan nama file txt : ");
    scanf("%s", &input);
    // input nilai n untuk n-gram
    printf("Masukkan jumlah n untuk n-gram : ");
    scanf("%d",&n);

    // membaca file
    f=fopen(input, "r");
    char data [1000];
    //program
    while(fgets(data,1000,f)!=NULL){
        char* x =strtok(data," \t\n");
        while(x!=NULL){
            append(&list,x);
            x=strtok(NULL," \t\n");
        }
    }

    // menghitung jumlah kata
    int lenList = countLen(list);
    int lenArr = sqrt(lenList)+1;

    // membuat array per kata
    string* word[lenArr];
    for (int i =0;i<lenArr;i++){
        word[i] = (string*)calloc(lenArr,sizeof(string));
    }
    // inisialisasi isi array dengan ""
    for (int i=0;i<lenArr;i++){
        for (int j=0;j<lenArr;j++){
            strcpy(word[i][j].kata,"");
        }
    }

    // memindahkan kata dari linked list ke array
    moveArray(list,word,lenArr);
    
    // print linked list
    // printf("\nMencetak linked list per kata :\n");
    // while (list!=NULL){
    //     printf("%s\n",list->kata);
    //     list=list->next;
    // }
    free(list);

    // menghitung jumlah kata
    // printf("\nJumlah kata pada text : %d\n", lenList);
    // print array per kata
    // printf("\nMencetak array per kata :\n");
    // for (int i=0;i<lenArr;i++){
    //     for (int j=0;j<lenArr;j++){
    //         if (strcmp(word[i][j].kata,"")!=0){
    //             printf("%s\n",word[i][j].kata);
    //         }
    //     }
    // }
    // printf("\nJumlah kata pada text : %d\n", lenList);

    // membuat array key
    string* key[lenArr];
    for (int i =0;i<lenArr;i++){
        key[i] = (string*)calloc(lenArr,sizeof(string));
    }
    // membuat array value
    string* value[lenArr];
    for (int i =0;i<lenArr;i++){
        value[i] = (string*)calloc(lenArr,sizeof(string));
    }
    // proses pengisian array key dan value dengan metode n-gram
    makeKey(word,key,lenArr,n,lenList);
    makeValue(word,value,lenArr,n,lenList);

    // print key dan value
    for (int i=0;i<lenArr;i++){
        for (int j=0;j<lenArr;j++){
            if (strcmp(key[i][j].kata,"")!=0){
                printf("%s ---> %s\n",key[i][j].kata,value[i][j].kata);
            }
        }
    }
    printf("\nJumlah kata pada text : %d\n", lenList);
    fclose(f);
    return 0;
}