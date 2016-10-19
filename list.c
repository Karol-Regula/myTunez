#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" //list header file

//this file contains all the linked list methods


int main(){
    //will need later
    //songNode *table[26];
    printf("\n");
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
    return 0;
}

void printList(struct songNode *node){
    while (node->next){
  	printf("Artist: %s\n", node->artist);
  	printf("Name: %s\n", node->name);
  	node = node->next;
    }
    printf("Artist: %s\n", node->artist);
    printf("Name: %s\n\n", node->name);
}

void printNode(struct songNode *node){
    printf("%s - %s\n", node->artist, node->name);
}

struct songNode * insertFront(struct songNode * node, char artist[256], char name[256]){
    struct songNode *new = (struct songNode *) malloc(sizeof(*new));
    strcpy(new->name, name);
    strcpy(new->artist, artist);
    new->next = node;
    return new;
}

struct songNode * insertOrder(struct songNode * node, char artist[256], char name[256]){
    struct songNode *first = node;
    struct songNode *new = (struct songNode *) malloc(sizeof(*new));
    strcpy(new->name, name);
    strcpy(new->artist, artist);
    if (node == 0){
	return new; //if creating the first node in a list
    } 
    if (strcmp(artist, node->artist) < 0){
	new->next = node;
	return new; //if adding to the front of the list
    }
    while(node->next && strcmp(artist, node->next->artist) >= 0){
	if (node->next && strcmp(artist, node->next->artist) == 0){
	    while(node->next && strcmp(name, node->next->name) > 0){
		node = node->next;
	    }
	    struct songNode *temp = node->next;
	    node->next = new;
	    new->next = temp;
	    return first;//returns here if a duplicate artist was found
	}
	node = node->next;
    }
    struct songNode *temp = node->next;
    node->next = new;
    new->next = temp;
    return first;//returns here if no duplicate artist was found
}

struct songNode * findSong(struct songNode * node, char name[256]){
    while (node->next){
	if (strcmp(node->name, name) == 0){
	    return node;
	}
	node = node->next;
    }
    if (strcmp(node->name, name) == 0){
	return node;//takes care of case at end dictionary
    }
    printf("song not found\n");
    return 0;
}

struct songNode * findArtist(struct songNode * node, char artist[256]){
    while (node->next){
	if (strcmp(node->artist, artist) == 0){
	    return node;
	}
	node = node->next;
    }
    if (strcmp(node->artist, artist) == 0){
	return node;//takes care of case at end dictionary
    }
    printf("artist not found\n");
    return 0;
}
