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
    while(true) // looping selama belum di quit
	{
		printf("********************  N-GRAM PROGRAM  ********************");
        printf("\n");
		printf("Selamat datang pada N-GRAM PROGRAM!!\n");
		printf("Program ini akan memberikan string acak berdasarkan\nreferensi sebuah textfile dengan menggunakan konsep n-gram\n");
        printf("\n");
		printf("Tekan ENTER untuk memulai");
        printf("\n");
		getchar();
		
		char file [20];			//inisiasi
		int n;
		int m;
		node* list = (node*)malloc(sizeof(node));
		list = NULL;
		FILE* f;
		printf("Masukkan file (ketik quit untuk keluar): "); // Meminta input user untuk file txt
		gets(file);
		
		if(strcmp(file, "quit")==0){	// program akan keluar jika user menginput 'quit'
			printf("\nThanks for having us");
			break;
		} else {
			while(true) //looping pada input n dan m
			{
				printf("\nMasukkan nilai n untuk n gram (input negatif untuk berganti file/quit): ");
				scanf("%d", &n);	// meminta input user untuk jumlah n pada n-gram
				if(n<0){
					break; // akan keluar dari loop (kembali ke input file ext) jika memasukkan n < 0
				}

				printf("Masukkan jumlah kata yang ingin dicetak: "); 
				scanf("%d", &m);	 // meminta input user untuk jumlah kata yang ingin ditampilkan pada output
				f=fopen(file, "r");
				char data [1000];
			 
				while(fgets(data,1000,f)!=NULL)
				{						// parsing file
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
				
				moveArray(list,word,lenArr);	// memanggil fungsi movearray
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
				
				makeKey(word,key,lenArr,n,lenList);	// memanggil fungsi makeKey
				makeValue(word,value,lenArr,n,lenList);	// memanggil fungsi makeValue
			 
				struct Queue* LUT= new_queue();
				makeTable(LUT, key, value, lenArr);	// memanggil fungsi makeTable (meletakkan key dan value pada table)
			
                printf("\n");
				output(n,m,LUT);	// memanggil fungsi output
                printf("\n");
				
				fclose(f);
			}
		}
	}
	
    return 0;
}
