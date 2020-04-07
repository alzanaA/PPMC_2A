/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Selasa, 7 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : testraafi.c
* Deskripsi : fungsi untuk membuat array key dan array value dari array per kata dengan metode n-gram
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "arraykeyvalue.h"

void makeKey (string** word, string** key, int len, int n){
    string* temp[len];
    for (int i =0;i<len;i++){
        temp[i] = (string*)calloc(len,sizeof(string));
    }
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            strcpy(temp[i][j].kata,"");
        }
    }
    char x[1000];
    char* y;
    char* z;
    for (int i=0;i<n;i++){
        int i1=0;
        int j1=i;
        int i2=0;
        int j2=0;
        for (int j=0;j<(len*len);j++){
            if (j1>=len){
                i1++;
                j1=0;
                if (i1>=len){
                    i1=0;
                }
            }
            if (strcmp(word[i1][j1].kata,"")!=0){
                strcpy(x,word[i1][j1].kata);
                if (strcmp(temp[i2][j2].kata,"")==0){
                    y=strcat(temp[i2][j2].kata,"");
                } else {
                    y=strcat(temp[i2][j2].kata," ");
                }
                z=strcat(y,x);
                strcpy(key[i2][j2].kata,z);
                strcpy(temp[i2][j2].kata,key[i2][j2].kata);
                if (j2<len-1){
                    j2++;
                } else {
                    i2++;
                    j2=0;
                }
            }
            j1++;
        }
    }
    return;
};

void makeValue (string** word, string** value, int len, int n){
    int i,i1,j1,i2,j2;
    i1=0;
    j1=n;
    i2=0;
    j2=0;
    for (i=0;i<(len*len);i++){
        if (j1>=len){
            i1++;
            j1=0;
            if (i1>=len){
                i1=0;
            }
        }
        if (strcmp(word[i1][j1].kata,"")!=0){
            strcpy(value[i2][j2].kata,word[i1][j1].kata);
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
}

// int main(){
//     return 0;
// }