typedef struct songNode{
    char artist[256];
    char name[256];
    struct songNode *next;
}songNode;

void printList(struct songNode *);
void printNode(struct songNode *);
struct songNode * insertFront(struct songNode *, char[256], char[256]);
struct songNode * insertOrder(struct songNode *, char[256], char[256]);
struct songNode * findSong(struct songNode *, char[256]);
struct songNode * findArtist(struct songNode *, char[256]);
struct songNode * findRandom(struct songNode *);
