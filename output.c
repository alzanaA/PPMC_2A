#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "output.h"


typedef struct node {
    char kata [1000];
    struct node* next;
}node;

typedef struct table{
    char key [1000];
    node* value;
    struct table* next;
} table;

struct Queue{
    struct table *front;
    struct table *rear;
};


int search(struct table * LUT, char * p, int m)
{
    // is found
    if(strcmp(p,LUT->key)==0){
        return 0;
    } else if((LUT==NULL)||(LUT->next==NULL)) {// is last
        return m;
    } else { // Next element
        return 1 + search(LUT->next,p,m);
    }
}

char* getKey(struct table * LUT, int index)
{
    if(index != 0){
        return getKey(LUT->next, index - 1);
    } else {
        return LUT->key;
    }
}

struct node * getValueRand(node * value, node * current, int word_index)
{
    if(word_index == 0){
        //printf("-{%d}-",word_index);
        return current;
    } else {
        //printf("={%d}=",word_index);
        if(current->next == NULL){
            return getValueRand(value, value, word_index-1);
        } else {
            return getValueRand(value, current->next, word_index-1);
        }
    }
}

char* getValue(struct table * LUT, int index, int m)
{
    // printf("\n================================= tag 9 %d",index);
    int word_index;
    if(index != 0){
    // printf("\n================================= tag 9a %d",index);
        return getValue(LUT->next, index - 1, m);
    } else {
    // printf("\n================================= tag 9b %d", LUT);
        node * buff_value = (node*)malloc(sizeof(struct node));
        word_index = rand() % m;
        //printf("{%d}",word_index);

    // printf("\n================================= tag 9ba %d %d %s", word_index, LUT->value, LUT->value->kata);

        buff_value = getValueRand(LUT->value, LUT->value, word_index);

    // printf("\n================================= tag 9bb %d %s", buff_value, buff_value->kata);

        return buff_value->kata;
    }
}


void output(int n, int m, struct Queue * database)
{
    table * LUT = database->front;
    int i;
    srand(time(0));
    
    // buffer n kata
    char buffer[1000];
    char value[1000];

    // ambil n kata random
    int word_index = rand() % n;
    strcpy(buffer, getKey(LUT, word_index));

    // cetak n kata
    printf(". . . %s",buffer);

    // loop
    char* token;
    char bufferNew[1000];
    char* rest;
    
    // printf("\n====================== tag 5 %d",word_index);

    for(i = 0; i<m-2; i++){
    // printf("\n====================== tag 6 %d", i);
        // cari key n
        word_index = search(LUT, buffer, m);

        // ambil value
        if(word_index < m){
            strcpy(value, getValue(LUT, word_index, m));
        } else {
            printf("I N V A L I D");
            break;
        }

    // printf("\n================================= tag 7 %d",word_index);

        // cetak n
        printf(" %s",value);

        // update buffer
        rest = buffer;
        strcpy(bufferNew,"\0");
    
    // printf("---%s---", buffer);

        token = strtok_r(rest," ",&rest);
        while(token = strtok_r(rest," ",&rest))
        {
            //printf("---%s---",token);
            strcat(bufferNew,token);
            strcat(bufferNew," ");
        }

    // printf("\n================================= tag 8 %d",word_index);
        strcat(bufferNew, value);
        strcpy(buffer,bufferNew);
    }

    // penutup
    printf(" . . .",buffer);
}

/*

////    TEST UNIT     //////////

int main(void){
    // buat database
    struct Queue * database = (struct Queue *)malloc(sizeof(struct Queue));

    // 5 x
    table * a = (table*) malloc(sizeof(struct table));
    table * b = (table*) malloc(sizeof(struct table));
    table * c = (table*) malloc(sizeof(struct table));
    table * d = (table*) malloc(sizeof(struct table));
    table * e = (table*) malloc(sizeof(struct table));
    table * f = (table*) malloc(sizeof(struct table));
    table * g = (table*) malloc(sizeof(struct table));

    // printf("====================== %d",a);

        // value
        strcpy(a->key,"tidak seperti");
        node * valuea = (node*)malloc(sizeof(node));
            strcpy(valuea->kata, "anggapan");
            valuea->next = NULL;
        a->value = valuea;
    // printf("\n====================== tag 1 %d",valuea);
        a->next = b;
        // value
        strcpy(b->key,"seperti anggapan");
        node * valueb = (node*)malloc(sizeof(node));
            strcpy(valueb->kata, "banyak");
            valueb->next = NULL;
        b->value = valueb;
        b->next = c;
        // value
        strcpy(c->key,"anggapan banyak");
        node * valuec = (node*)malloc(sizeof(node));
        node * valuecc = (node*)malloc(sizeof(node));
            strcpy(valuec->kata, "orang");
                valuec->next = valuecc;
            strcpy(valuecc->kata, "manusia");
                valuecc->next = NULL;
        c->value = valuec;
        c->next = d;
        // value
        strcpy(d->key,"banyak orang");
        node * valued = (node*)malloc(sizeof(node));
            strcpy(valued->kata, "tidak");
            valued->next = NULL;
        d->value = valued;
        d->next = e;
        // value
        strcpy(e->key,"banyak manusia");
        node * valuee = (node*)malloc(sizeof(node));
            strcpy(valuee->kata, "tidak");
            valuee->next = NULL;
        e->value = valuee;
        e->next = f;
        // value
        strcpy(f->key,"orang tidak");
        node * valuef = (node*)malloc(sizeof(node));
            strcpy(valuef->kata, "seperti");
            valuef->next = NULL;
        f->value = valuef;
        f->next = g;
        // value
        strcpy(g->key,"manusia tidak");
        node * valueg = (node*)malloc(sizeof(node));
            strcpy(valueg->kata, "seperti");
            valueg->next = NULL;
        g->value = valueg;
        g->next = NULL;
    // printf("\n====================== tag 2 %d",f->value);
        
    
    
    database->front = a;
    database->rear = g;

    
    // printf("\n====================== tag 3 %d",database->front);

    // run
    output(2,20, database);

    // printf("\n====================== tag 4 %d",valuea);

    return 0;
}*/