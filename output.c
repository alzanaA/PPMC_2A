#include <stdio.h>
#include <output.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

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

char* getValue(struct table * LUT, int index)
{
    if(index != 0){
        return getValue(LUT->next, index - 1);
    } else {
        node * buff_value = LUT->value;
        srand(time(0));

        int word_index = rand()*rand();

        buff_value = getValueRand(LUT->value, buff_value, word_index);

        return buff_value->kata;
    }
}

node * getValueRand(node * value, node * current, int word_index){
    if(word_index == 0){
        return current;
    } else {
        if((current==NULL)||(current->next==NULL)){
            return getValueRand(value, value, word_index-1);
        } else {
            return (getValueRand(value, current->next, word_index-1));
        }
    }
}

void output(int n, int m, struct table * LUT)
{
    int i;
    srand(time(0));
    
    // buffer n kata
    char buffer[1000];
    char value[1000];

    // ambil n kata random
    int word_index = rand()*rand() % n;
    strcpy(buffer, getKey(LUT, word_index));

    // cetak n kata
    printf(". . . %s",buffer);

    // loop
    char* token;
    char* bufferNew;
    char* rest;
    for(i = 0; i<m; i++){
        // cari key n
        word_index = search(LUT,buffer);

        // ambil value
        if(word_index < m){
            strcpy(value, getValue(LUT, word_index));
        } else {
            printf("I N V A L I D");
            break;
        }

        // cetak n
        printf(" %s",value);

        // update buffer
        rest = buffer;
        strcpy(bufferNew,"\0");

        token = strtok_r(rest," ",&rest);
        while(token = strtok_r(rest," ",&rest))
        {
            strcat(bufferNew,token);
            strcat(bufferNew," ");
        }
        strcat(bufferNew, value);
        strcpy(buffer,bufferNew);
    }
}

