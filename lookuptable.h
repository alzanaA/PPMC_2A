void printList(struct node *node);
void printQueue(struct Queue *q);
table* new_node(char k [], node *v);
struct Queue* new_queue();
void enqueue(struct Queue* q, char k [], node* v);
int removeDuplicate(table** temp, string** key, string **value, int len);
void makeTable(struct Queue* LUT, string** key, string **value, int len);
