/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Selasa, 7 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : testraafi.c
* Deskripsi : Tester untuk membuat array key dan array value dari file txt
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct arrayofstring {
    char kata [1000];
}string;

typedef struct node {
    char kata [1000];
    struct node* next;
}node;

// #include "parsing.h"
// #include "arraykeyvalue.h"
// #include "tipedata.h"

void append (node** head_ref, char kata_baru []) {
    node* new_node = (node*)malloc(sizeof(node));
    node* last = *head_ref;
    strcpy(new_node->kata,kata_baru);
    new_node->next = NULL;
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
};

int main () {
    //variabel
    node* list = (node*)malloc(sizeof(node));
    list = NULL;
    char input [1000];
    FILE* f;
    printf("Masukkan nama file txt : ");
    scanf("%s", &input);
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
    int lenList = countLen(list);
    int lenArr = sqrt(lenList)+1;
    string* word[lenArr];
    for (int i =0;i<lenArr;i++){
        word[i] = (string*)calloc(lenArr,sizeof(string));
    }
    for (int i=0;i<lenArr;i++){
        for (int j=0;j<lenArr;j++){
            strcpy(word[i][j].kata,"");
        }
    }
    moveArray(list,word,lenArr);
    free(list);
    string* key[lenArr];
    for (int i =0;i<lenArr;i++){
        key[i] = (string*)calloc(lenArr,sizeof(string));
    }
    string* value[lenArr];
    for (int i =0;i<lenArr;i++){
        value[i] = (string*)calloc(lenArr,sizeof(string));
    }
    int n =2;
    makeKey(word,key,lenArr,n);
    makeValue(word,value,lenArr,n);
    for (int i=0;i<lenArr;i++){
        for (int j=0;j<lenArr;j++){
            if (strcmp(key[i][j].kata,"")!=0){
                printf("%s ---> %s\n",key[i][j].kata,value[i][j].kata);
            }
        }
    }
    fclose(f);
    return 0;
}