typedef struct songNode{
    char name[256];
    char artist[256];
    struct songNode *next;
}songNode;

void printList(struct songNode *);
struct songNode * insertFront(struct songNode *, char[256], char[256]);
