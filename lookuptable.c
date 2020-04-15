/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : lookuptable.c
* Deskripsi : fungsi untuk membuat lookup table, merge key yang sama, dan menyatukan value untuk key yang sama
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tipedata.h"
#include "parsing.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lookuptable.h"
#include "parsing.h"

table* new_node(char k [], node *v){
	table* temp = (table*)malloc(sizeof(struct table)); 
	strcpy(temp->key, k);
    temp->value = v; 
	temp->next = NULL; 
	return temp; 
} 

struct Queue* new_queue() { 
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
	q->front = q->rear = NULL; 
	return q; 
} 

void enqueue(struct Queue* q, char k [], node* v) {  
	table* temp = new_node(k, v); 
	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		return; 
	} 
	q->rear->next = temp; 
	q->rear = temp; 
} 

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

int removeDuplicate(table** temp, string** key, string **value, int len){
    int count=0;
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            for (int m=0;m<i+1;m++){
                if(m<i){
                    for (int n=0;n<len;n++){
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

void makeTable(struct Queue* LUT, string** key, string **value, int len){
    table* temp[len];
    for (int i=0;i<len;i++){
        temp[i] = (table*)calloc(len,sizeof(table));
    }
    int count= removeDuplicate(temp, key, value, len);
    for (int i=0;i<(count/len);i++){
        for (int j=0;j<len;j++){
            if(temp[i][j].key != "");
                enqueue(LUT, temp[i][j].key, temp[i][j].value);
        }
    }
    for(int i=0; i<(count%len); i++){
        if(temp[count/len][i].key != "");
            enqueue(LUT, temp[count/len][i].key, temp[count/len][i].value);
    }
}
