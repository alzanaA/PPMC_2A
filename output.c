#include <stdio.h>
#include <output.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int search(struct Queue * LUT, char * p)
{
    // is found
    if(){
        return 0;
    } else if() {// is last
        return 0;
    } else {
        return 1 + search();
    }
}

char* getKey(struct Queue * LUT, int index)
{
    return void;
}

char* getValue(struct Queue * LUT, int index)
{
    return void;
}

void output(int n, int m, struct Queue * LUT)
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
    for(i = 0; i<m; i++){
        // cari key n
        word_index = search(LUT,buffer);

        // ambil value
        strcpy(value, getValue(LUT, word_index));

        // cetak n
        printf(" %s",value);

        // update buffer
        strcpy(buffer, value);
        strcpy(value, getKey(LUT, word_index));
        strcat(value, " ");
        strcat(value, buffer);
        strcpy(buffer, value);
    }
}

