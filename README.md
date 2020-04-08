# PPMC_2A
Pengerjaan Tugas Besar PPMC oleh Kelompok 2A

Tipe data:

typedef struct arrayofstring {
    char kata [1000];
}string;

typedef struct node {
    char kata [1000];
    struct node* next;
}node;

typedef struct table{
    char key [1000];
    node *value;
}table;
