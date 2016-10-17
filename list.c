#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" //list header file

//this file contains all the linked list methods


int main(){
    //will need later
    //songNode *table[26];
    printf("\n");
    struct songNode *list = (struct songNode *) malloc(sizeof(*list));
    list->artist[0] = 'b';
    list->name[0] = 'a';
    list = insertFront(list, "Jim", "Kirk");
    printList(list);
    printf("\n");
    return 0;
}

void printList(struct songNode *node){
    while (node->next){
	printf("Name: %s\n", node->name);
	printf("Artist: %s\n", node->artist);
	node = node->next;
    }
    printf("Name: %s\n", node->name);
    printf("Artist: %s\n", node->artist);   
}

struct songNode * insertFront(struct songNode * node, char name[256], char artist[256]){
    struct songNode *new = (struct songNode *) malloc(sizeof(*new));
    strcpy(new->name, name);
    strcpy(new->artist, artist);
    new->next = node;
    return new;
}
