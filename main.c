#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
 {
    char file [20];
    int n;
    node* list = (node*)malloc(sizeof(node));
    list = NULL;
    FILE* f;
    printf("Masukkan file : ");
    gets(file);
    printf("Masukkan nilai n: ");
    scanf("%d", &n); 
    f=fopen(file, "r");
    char data [1000];
 
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
    makeKey(word,key,lenArr,n);
    makeValue(word,value,lenArr,n);
 
    table* LUT[lenArr];
    for (int i =0;i<lenArr;i++){
        LUT[i] = (table*)calloc(lenArr,sizeof(table));
    }
 
    output(n,m,lut)
     
    fclose(f);
    return 0;
}
