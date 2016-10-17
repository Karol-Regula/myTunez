typedef struct songNode{
    char artist[256];
    char name[256];
    struct songNode *next;
}songNode;

void printList(struct songNode *);
struct songNode * insertFront(struct songNode *, char[256], char[256]);
struct songNode * insertOrder(struct songNode *, char[256], char[256]);
