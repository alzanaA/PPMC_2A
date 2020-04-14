/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Selasa, 14 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : testraafi.c
* Deskripsi : fungsi untuk membuat array key dan array value dari array per kata dengan metode n-gram
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tipedata.h"

void makeKey (string** word, string** key, int len, int n, int lenList){
    // membuat struct untuk data sementara
    string* temp[len];
    for (int i =0;i<len;i++){
        temp[i] = (string*)calloc(len,sizeof(string));
    }
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            strcpy(temp[i][j].kata,"");
        }
    }

    // tipe data
    char x[1000];
    char* y;
    char* z;
    int side = 0;
    int count1 = 0;
    int count2 = 0;

    // loop sebanyak n kali untuk jumlah kata per key
    for (int i=0;i<n;i++){
        // pengaturan indeks awal menyesuaikan nilai n
        if (count2<lenList){
            if (count1>=len){
            side++;
            count1=0;
            }
            if (side>=len){
                side = 0;
            }
        } else {
            count2 = 0;
            count1 = 0;
            side = 0;
        }
        int i1 = side;
        int j1=count2%len;
        int i2=0;
        int j2=0;

        // loop sebanyak jumlah array agar semua kata dimasukkan
        for (int j=0;j<(len*len);j++){
            // pengaturan indeks array per kata
            if (j1>=len){
                i1++;
                j1=0;
                if (i1>=len){
                    i1=0;
                }
            }
            // jika array tidak kosong atau ""
            if (strcmp(word[i1][j1].kata,"")!=0){
                // pengisisan key
                strcpy(x,word[i1][j1].kata);
                if (strcmp(temp[i2][j2].kata,"")==0){
                    y=strcat(temp[i2][j2].kata,"");
                } else {
                    y=strcat(temp[i2][j2].kata," ");
                }
                z=strcat(y,x);
                strcpy(key[i2][j2].kata,z);
                strcpy(temp[i2][j2].kata,key[i2][j2].kata);
                //pengaturan indeks array key
                if (j2<len-1){
                    j2++;
                } else {
                    i2++;
                    j2=0;
                }
            }
            j1++;
        }
        count1++;
        count2++;
    }
    return;
};

void makeValue (string** word, string** value, int len, int n, int lenList){
    // pengaturan indeks array per kata
    int i,i1,j1,i2,j2;
    int count1 = 0;
    int count2 = 0;
    int side = 0;
    for (int j=0;j<n;j++){
        if (count2<lenList){
            if (count1>=len-1){
                side++;
                count1=0;
            }
        } else {
            count2=0;
            count1=0;
            side=0;
        }
        count2++;
        count1++;
    }
    i1=side;
    j1=count2%len;
    i2=0;
    j2=0;

    // loop sebanyak jumlah array agar semua kata dimasukkan
    for (i=0;i<(len*len);i++){
        // pengaturan indeks array per kata
        if (j1>=len){
            i1++;
            j1=0;
            if (i1>=len){
                i1=0;
            }
        }
        // jika array tidak kosong atau ""
        if (strcmp(word[i1][j1].kata,"")!=0){
            // pengisisan array value
            strcpy(value[i2][j2].kata,word[i1][j1].kata);
            // pengaturan indeks array value
            if (j2<len-1){
                j2++;
            } else {
                i2++;
                j2=0;
            }
        }
        j1++;
    }
    return;
};
