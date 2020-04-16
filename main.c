/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Rabu, 15 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : main.c
* Deskripsi : program utama yang akan dijalankan
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
		printf("Masukkan file (ketik quit untuk keluar): ");
		// input file
		gets(file);
		// terminate untuk input file
		if(strcmp(file, "quit")==0){
			printf("\nThanks for having us");
			break;
		} else {
			while(true) 
			{
				int n;
				int m;
				// linked list per kata
				node* list = (node*)malloc(sizeof(node));
				list = NULL;
				FILE* f;
				// input n
				printf("\nMasukkan nilai n untuk n gram (input negatif untuk berganti file/quit): ");
				scanf("%d", &n);
				if(n<0){
					break;
				}

				// input m
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
				
				// menghitung jumlah kata
				int lenList = countLen(list);
				int lenArr = sqrt(lenList)+1;

				// membuat array per kata
				string* word[lenArr];
				for (int i =0;i<lenArr;i++){
					word[i] = (string*)calloc(lenArr,sizeof(string));
				}
				for (int i=0;i<lenArr;i++){
					for (int j=0;j<lenArr;j++){
						strcpy(word[i][j].kata,"");
					}
				}
				
				// memindahkan kata dari linked list ke arrya
				moveArray(list,word,lenArr);
				free(list);

				// membuat array key
				string* key[lenArr];
				for (int i =0;i<lenArr;i++){
					key[i] = (string*)calloc(lenArr,sizeof(string));
				}

				// membuat array value
				string* value[lenArr];
				for (int i =0;i<lenArr;i++){
					value[i] = (string*)calloc(lenArr,sizeof(string));
					if(i % n == 0){
						printf(" . ");
					}
				}
				
				// mengisi array key dan value
				makeKey(word,key,lenArr,n,lenList);
				makeValue(word,value,lenArr,n,lenList);

				// menyempurnakan key dan value pada lookup table
				struct Queue* LUT= new_queue();
				makeTable(LUT, key, value, lenArr);
			
			    // menampilkan output
                printf("\n");
				output(n,m,LUT);
                printf("\n");
				
				fclose(f);

				for (int i=0;i<lenArr;i++){
					free(key[i]);
					free(value[i]);
					free(word[i]);
				}
			}
		}
	}
	
    return 0;
}
