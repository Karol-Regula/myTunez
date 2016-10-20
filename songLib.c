#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//contains songLib methods
void addSong(songNode * table[], char artist[256], char name[256]){
    //printf("First letter: %c, number: %d\n", artist[0], artist[0]);
    int index = artist[0] - 65;//'A' == 65, this determines the linkedlist the song will be in
    table[index] = insertOrder(table[index], artist, name);
    printf("Added song under the letter %c (%d)\n", artist[0], index);
}

void printLib(songNode * table[]){
    int i = 0;
    while (i < 26){
	printf("Printing letter %c: %d\n", i + 65, i);
	printList(table[i]);
	i++;
    }
}
