#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"
#include "songLib.h"

int main(){
    //test protocol will go here
    songNode * table[26] = { 0 };//array of 26 songNodes (linkedlists)

    srand(time(NULL));
    /*   
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
    */

    printf("\n");
    addSong(table, "Darth Vader", "Let's Dance");
    addSong(table, "David Bowie", "Let's Not Dance");
    addSong(table, "Darth Vader", "I Misplaced the Death Star");
    addSong(table, "The Beatles", "Tomorrow");
    addSong(table, "The Beatles", "Hey James");
    addSong(table, "The Beatles", "Run and Scream");
    addSong(table, "The Beatles", "Here Comes the Moon");
    addSong(table, "Jean-Luc Picard", "Shut up Wesley");
    addSong(table, "Jean-Luc Picard", "Make it Flow");
    addSong(table, "Jean-Luc Picard", "Data, Where is My Tea?");
    
    printf("\n");
    printLib(table);

    printf("\n");
    printf("Printing individual letters:\n");
    printLetter(table, 'T');
    printLetter(table, 'A');

    printf("\n");
    printf("Printing individual artists:\n");
    printArtist(table, "The Beatles");
    printArtist(table, "James T. Kirk");

    printf("\n");
    findSongLib(table, "The Beatles", "Hey James");
    findSongLib(table, "Darth Vader", "Imperial March");

    printf("\n");
    findArtistLib(table, "The Beatles");
    findArtistLib(table, "James T. Kirk");

    printf("\n");
    shuffle(table);

    printf("\n");
    deleteSong(table, "The Beatles", "Hey James");
    deleteSong(table, "The Beatles", "Tomorrow");
    deleteSong(table, "James T. Kirk", "I'm the Best Captain");
    printf("Jim, you are the best captain.\n");

    printf("\n");
    printLib(table);

    printf("\n");
    deleteLib(table);
    
    return 0;
}
