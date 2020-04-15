/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : lookuptable.c
* Deskripsi : fungsi untuk membuat lookup table, merge key yang sama, dan memasukkan ke queue agar tidak ada elemen kosong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tipedata.h"
#include "lookuptable.h"
#include "parsing.h"

//Fungsi untuk menambah node pada queue
table* new_node(char k [], node *v){
	table* temp = (table*)malloc(sizeof(struct table)); 
	strcpy(temp->key, k);
    	temp->value = v; 
	temp->next = NULL; 
	return temp; 
} 
//Fungsi untuk membuat queue
struct Queue* new_queue() { 
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
	q->front = q->rear = NULL; 
	return q; 
} 
//Fungsi untuk mengatur node baru pada urutan queue
void enqueue(struct Queue* q, char k [], node* v) {  
	table* temp = new_node(k, v); 
	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		return; 
	} 
	q->rear->next = temp; 
	q->rear = temp; 
} 
//Fungsi untuk mencari apakah string k terdapat pada linked list dengan head head_list
bool isSame(node* head_list, char k[]) 
{ 
    node* temp = head_list; 
    while (temp != NULL) 
    { 
        if (strcmp(temp->kata, k)==0) 
            return true; 
        temp = temp->next; 
    } 
    return false; 
} 
//Fungsi untuk merge key yang sama pada array temp (array sementara untuk menyimpan key & value)
int removeDuplicate(table** temp, string** key, string **value, int len){
    //Inisialisasi var count untuk menghitung jumlah key setelah dimerge
    int count=0;
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            for (int m=0;m<i+1;m++){
		/*Membandingkan key[i][j].kata dengan temp[m][n].key, 
		untuk m<i n yang ditelusuri adalah sebanyak jumlah baris (len)*/
                if(m<i){
                    for (int n=0;n<len;n++){
                        if (strcmp(key[i][j].kata,"")!=0){
                            if (strcmp(key[i][j].kata,key[m][n].kata)!=0)
                                continue;
                            else{
				/*Jika 2 key yang ditelusuri sama, akan ditambahkan value ke linked list value pada array temp,
				jika belum ditemukan value serupa*/
				if(isSame(temp[m][n].value, value[i][j].kata)==false)
                                	append(&(temp[m][n].value), value[i][j].kata);
				//Menggeser key pada array temp pada indeks i yang sama
                                if (j<len-1){
                                    for(int x=j; x<len-1; x++){
                                        strcpy(key[i][x].kata, key[i][x+1].kata);
                                        strcpy(value[i][x].kata, value[i][x+1].kata); 
                                }
                                    strcpy(key[i][len-1].kata, key[i+1][0].kata);
                                    strcpy(value[i][len-1].kata, value[i+1][0].kata);                           
                                }
                                else {
                                    strcpy(key[i][j].kata, key[i+1][0].kata);
                                    strcpy(value[i][j].kata, value[i+1][0].kata);
                                }
				//Menggeser key pada array temp pada indeks x>i sampai x=len-1
                                for(int x=i+1; x<len; x++){
                                    for(int y=0; y<len-1; y++){
                                        strcpy(key[x][y].kata, key[x][y+1].kata);
                                        strcpy(value[x][y].kata, value[x][y+1].kata);
                                    }
                                    if (x<len-1){
                                        strcpy(key[x][len-1].kata, key[x+1][0].kata);
                                        strcpy(value[x][len-1].kata, value[x+1][0].kata);
                                    }
                                }
                            }
                        }
                    }
                }
		//Untuk m=i n yang ditelusuri adalah n=0 sampai n=j-1
                else{
                    for (int n=0;n<j;n++){
                        if (strcmp(key[i][j].kata,"")!=0){
                            if (strcmp(key[i][j].kata,key[m][n].kata)!=0)
                                continue;
                            else{
                                if(isSame(temp[m][n].value, value[i][j].kata)==false)
                                    append(&(temp[m][n].value), value[i][j].kata);
                                if (j<len-1){
                                    for(int x=j; x<len-1; x++){
                                        strcpy(key[i][x].kata, key[i][x+1].kata);
                                        strcpy(value[i][x].kata, value[i][x+1].kata); 
                                    }   
                                    strcpy(key[i][len-1].kata, key[i+1][0].kata);
                                    strcpy(value[i][len-1].kata, value[i+1][0].kata);                        
                                }
                                else {
                                    strcpy(key[i][j].kata, key[i+1][0].kata);
                                    strcpy(value[i][j].kata, value[i+1][0].kata);
                                }
                                for(int x=i+1; x<len; x++){
                                    for(int y=0; y<len-1; y++){
                                        strcpy(key[x][y].kata, key[x][y+1].kata);
                                        strcpy(value[x][y].kata, value[x][y+1].kata);
                                    }
                                    if (x<len-1){
                                        strcpy(key[x][len-1].kata, key[x+1][0].kata);
                                        strcpy(value[x][len-1].kata, value[x+1][0].kata);
                                    }
                                }
                            }
                        }
                    }
                }
            }
	    /*Jika key tidak kosong, menambahkan key dan value ke current index [i][j] dari array temp,
	    dan melakukan inkremen nilai var count untuk tiap key baru*/
            if (strcmp(key[i][j].kata,"")!=0){
                    strcpy(temp[i][j].key, key[i][j].kata);
                    if(isSame(temp[i][j].value, value[i][j].kata)==false)
                        append(&(temp[i][j].value), value[i][j].kata);
                    count=count+1;
            }
        }
    }
    return count;
}
//Fungsi untuk membuat lookup table LUT dengan struktur tipe data queue of table
void makeTable(struct Queue* LUT, string** key, string **value, int len){
    //Inisialisasi array temp 2d & mengalokasi memorinya untuk menyimpan key & value sementara
    table* temp[len];
    for (int i=0;i<len;i++){
        temp[i] = (table*)calloc(len,sizeof(table));
    }
    int count= removeDuplicate(temp, key, value, len);
    //Memasukkan floor(count/len)*len indeks pertama key dan value array temp ke queue LUT 
    for (int i=0;i<(count/len);i++){
        for (int j=0;j<len;j++){
            if(temp[i][j].key != "");
                enqueue(LUT, temp[i][j].key, temp[i][j].value);
        }
    }
    //Memasukkan (count mod len) indeks sisa dari array temp ke LUT
    for(int i=0; i<(count%len); i++){
        if(temp[count/len][i].key != "");
            enqueue(LUT, temp[count/len][i].key, temp[count/len][i].value);
    }
    for (int i=0;i<len;i++){
        free(temp[i]);
    }
}
