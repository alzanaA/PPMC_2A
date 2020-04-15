/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : output.c
* Deskripsi : Fungsi utama
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#include "parsing.h"
#include "arraykeyvalue.h"
#include "tipedata.h"
#include "output.h"
#include "lookuptable.h"

int main ()
{
    while(true)
	{
		printf("********************  N-GRAM PROGRAM  ********************");
        printf("\n");
		printf("Selamat datang pada N-GRAM PROGRAM!!\n");
		printf("Program ini akan memberikan string acak berdasarkan\nreferensi sebuah textfile dengan menggunakan konsep n-gram\n");
        printf("\n");
		printf("Tekan ENTER untuk memulai");
        printf("\n");
		getchar();
		
		char file [20];
		int n;
		int m;
		node* list = (node*)malloc(sizeof(node));
		list = NULL;
		FILE* f;
		printf("Masukkan file (ketik quit untuk keluar): ");
		gets(file);
		
		if(strcmp(file, "quit")==0){
			printf("\nThanks for having us");
			break;
		} else {
			while(true) 
			{
				printf("\nMasukkan nilai n untuk n gram (input negatif untuk berganti file/quit): ");
				scanf("%d", &n);
				if(n<0){
					break;
				}

				printf("Masukkan jumlah kata yang ingin dicetak: ");
				scanf("%d", &m);
				f=fopen(file, "r");
				char data [1000];
			 
				while(fgets(data,1000,f)!=NULL)
				{
					char* x =strtok(data," \t\n");
					while(x!=NULL)
					{
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
					if(i % (200*n) == 0){
						printf(" . ");
					}
				}
				
				makeKey(word,key,lenArr,n,lenList);
				makeValue(word,value,lenArr,n,lenList);
			 
				struct Queue* LUT= new_queue();
				makeTable(LUT, key, value, lenArr);
			
                printf("\n");
				output(n,m,LUT);
                printf("\n");
				
				fclose(f);
			}
		}
	}
	
    return 0;
}
