#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "songLib.h"

int main(){
    //test protocol will go here
    printf("%d", 'A' + 0);
    
    songNode * table[26] = { 0 };//array of 26 songNodes (linkedlists)

    srand(time(NULL));
    
    printf("\n\n");
    struct songNode *list = 0;
    list = insertOrder(list, "Jim", "Kirk");
    list = insertOrder(list, "Bones", "McCoy");
    list = insertOrder(list, "Spock", "Vulcan");
    list = insertOrder(list, "Spock", "Ears");
    list = insertOrder(list, "Spock", "Z");
    list = insertOrder(list, "Spock", "Y");
    list = insertOrder(list, "Spock", "Q");
    list = insertOrder(list, "Aaron", "A");
    list = insertOrder(list, "Aaron", "B");
    printList(list);
    
    printf("\n");
    printNode(findSong(list, "Kirk"));
    findSong(list, "Bob");
    printNode(findArtist(list, "Spock"));
    findArtist(list, "Bill");

    printf("\n");
    printNode(findRandom(list));
    printNode(findRandom(list));

    printf("\n");
    list = removeNode(list, 0);
    list = removeNode(list, 7);
    list = removeNode(list, 2);
    printList(list);

    printf("\n");
    list = removeAll(list);
    printList(list);

    printf("\nBeginning tests of songLib methods.\n");
    addSong(table, "The Beatles", "Yesterday");
    addSong(table, "The Beatles", "Hey Jude");
    addSong(table, "David Bowie", "Let's Dance");
    printLib(table);

    
    return 0;
}
