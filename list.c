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
    list = insertFront(list, "Jim", "Kirk");
    list = insertFront(list, "Bones", "McCoy");
    list = insertOrder(list, "Spock", "Vulcan"); //NOT YET WORKING
    printList(list);
    printf("\n");
    return 0;
}

void printList(struct songNode *node){
    while (node->next){
	printf("Artist: %s\n", node->artist);
	printf("Name: %s\n", node->name);
	node = node->next;
    }
    printf("Artist: %s\n", node->artist);
    printf("Name: %s\n", node->name);   
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
    while(node->next && strcmp(artist, node->artist) < 0){
	node = node->next;
    }
    struct songNode *temp = node->next;
    node->next = new;
    new->next = temp; 
    return first;
}
