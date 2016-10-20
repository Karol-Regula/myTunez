#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//contains songLib methods
void addSong(songNode * table[], char artist[256], char name[256]){
    //printf("First letter: %c, number: %d\n", artist[0], artist[0]);
    int index = artist[0] - 65;//'A' == 65, this determines the linkedlist the song will be in
    table[index] = insertOrder(table[index], artist, name);
    printf("Added song under the letter: %c (%d)\n", artist[0], index);
}

void printLib(songNode * table[]){
    int i = 0;
    while (i < 26){
	if (table[i] != 0){
	    printf("Printing letter: %c: %d\n", i + 65, i);
	    printList(table[i]);
	}
	i++;
    }
}

void printLetter(songNode * table[], char letter){
    int index = letter - 65;
    printf("Printing letter: %c: %d\n", letter, index);
    printList(table[index]);
}

void printArtist(songNode * table[], char artist[256]){
    printf("Printing artist: %s\n", artist);
    int i = 0;
    while (i < 26){
	struct songNode *found = findArtist(table[i], artist);
	if (found != 0){
	    while(found->artist && strcmp(found->artist, artist) == 0){
		printNode(found);
		found = found->next;
	    }
	    return;
	}
	i++;
    }
    printf("Artist not found.\n");
}

//NOTE: this function assumes that there are no duplicate songnames
void findSongLib(songNode * table[], char artist[256], char name[256]){
    int i = 0;
    printf("Looking for song: %s - %s\n", artist, name);
    while (i < 26){
	struct songNode *found = findSong(table[i], name);
	if (found != 0){
	    printNode(found);
	    return;
	}
	i++;
    }
    printf("Song not found.\n");
    return;
}

void findArtistLib(songNode * table[], char artist[256]){
    int i = 0;
    printf("Looking for arist: %s\n", artist);
    while (i < 26){
	struct songNode *found = findArtist(table[i], artist);
	if (found != 0){
	    printNode(found);
	    return;
	}
	i++;
    }
    printf("Artist not found.\n");
    return;
}
