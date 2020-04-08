void append (node** head_ref, char kata_baru []) {
    node* new_node = (node*)malloc(sizeof(node));
    node* last = *head_ref;
    strcpy(new_node->kata,kata_baru);
    new_node->next = NULL;
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

void printList(struct node *node) 
{ 
while (node != NULL) 
{ 
	printf("%s, ", node->kata); 
	node = node->next; 
} 
} 

void makeTable(table** LUT, string** key, string **value, int len){
    int count=0;
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            LUT[i][j].value= (node*)malloc(sizeof(node));
        }
    }
    printf("test");
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            for (int m=0;m<len;m++){
                for (int n=0;n<len;n++){
                    if(i==m && j==n)
                        continue;
                    if (strcmp(key[i][j].kata,"")!=0){
                        printf("test");
                        if (strcmp(key[i][j].kata,key[i][j].kata)!=0){
                            strcpy(LUT[i][j].key, key[i][j].kata);
                            printf("test");
                            append(&(LUT[i][j].value), value[i][j].kata);
                        }
                        else{
                            if (n<len-1){
                                printf("test");
                                for(int x=n; x<len-1; x++)
                                    strcpy(key[m][x].kata, key[m][x+1].kata);                            
                            }
                            else {
                                strcpy(key[m][n].kata, key[m+1][0].kata);
                            }
                            for(int x=m+1; x<len; x++){
                                    for(int y=0; y<len-1; y++)
                                        strcpy(key[x][y].kata, key[x][y+1].kata);
                                    strcpy(key[x][len-1].kata, key[x+1][0].kata);
                                }
                            append(&(LUT[i][j].value), value[m][n].kata);
                        }
                    }
                }
            } 
        }
    } 
}
