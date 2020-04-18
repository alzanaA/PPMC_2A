/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 2
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Hamdani Fadhli (13217058)
* Nama File : testalzana.c
* Deskripsi : Tester untuk membuat lookup table dari array key dan value
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int temp_count;		//variabel untuk menyimpan nilai variabel count

typedef struct arrayofstring {
    char kata [1000];
}string;

typedef struct node {
    char kata [1000];
    struct node* next;
}node;

typedef struct table {
    char key [1000];
    node* value;
    struct table* next;
}table;

struct Queue { 
	struct table *front, *rear; 
}; 

void append (node** head_ref, char kata_baru []) {
    // membuat linked list baru dengan memasukkan kata baru
    node* new_node = (node*)malloc(sizeof(node));
    node* last = *head_ref;
    strcpy(new_node->kata,kata_baru);
    new_node->next = NULL;

    // menambahkan linked list baru dari belakang linked list yang ada
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
    // mengisi nilai array dari linked list per kata
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

void printList(struct node *node) 
{ 
while (node != NULL) 
{ 
	printf("%s ", node->kata); 
	node = node->next; 
} 
printf("\n");
} 

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
    temp_count= count;
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

void printQueue(struct Queue *q){
	struct table* temp = q->front;
	while(temp != NULL) {
		printf("%s ---> ",temp->key);
        printList(temp->value);
		temp = temp->next;
	}
	printf("\n");
}

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
    }
    // proses pengisian array key dan value dengan metode n-gram
    makeKey(word,key,lenArr,n,lenList);
    makeValue(word,value,lenArr,n,lenList);
    // inisialisasi Queue dan pemindahan key dan value ke Queue LUT
    struct Queue* LUT= new_queue();
    makeTable(LUT, key, value, lenArr);
    for (int i=0;i<lenArr;i++){
		free(key[i]);
		free(value[i]);
    }
    printf("\n");
    printf("\n");
    //print key dan value pada queue LUT
    printQueue(LUT);
    //print nilai variabel count
    printf("Jumlah elemen pada LUT (count): %d", temp_count);
    fclose(f);
    return 0;
}
