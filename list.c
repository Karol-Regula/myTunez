#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h" //list header file

//this file contains all the linked list methods

void printList(struct songNode *node){
    if (node == 0){
	return;
    }
    while (node->next){
  	printf("%s - %s\n", node->artist, node->name);
  	node = node->next;
    }
    printf("%s - %s\n", node->artist, node->name);
}

void printNode(struct songNode *node){
    printf("%s - %s\n", node->artist, node->name);
}

struct songNode * insertFront(struct songNode * node, char artist[256], char name[256]){
    struct songNode *new = (struct songNode *) calloc(sizeof(*new), 1);
    strcpy(new->name, name);
    strcpy(new->artist, artist);
    new->next = node;
    return new;
}

struct songNode * insertOrder(struct songNode * node, char artist[256], char name[256]){
    struct songNode *first = node;
    struct songNode *new = (struct songNode *) calloc(sizeof(*new), 1);
    strcpy(new->name, name);
    strcpy(new->artist, artist);
    if (node == 0){
	return new; //if creating the first node in a list
    }
    if (strcmp(artist, node->artist) < 0){
	new->next = node;
	return new; //if adding to the front of the list (no duplicate artist)
    }
    if (!(node->next) && strcmp(artist, node->artist) == 0){//only one song and duplicate artist
	if (strcmp(name, node->name) < 0){
	    new->next = node;
	    return new;//if added to front
	}else{
	    node->next = new;
	    return node;//if added to end
	}
	return first;//returns here if a duplicate artist was found at the first node
    }
    if (node->next && strcmp(artist, node->artist) == 0){//if at beginning but more exist
	if (strcmp(name, node->name) < 0){
	    new->next = node;
	    return new;//if added to front
	}
    }
    while(node->next && strcmp(artist, node->next->artist) >= 0){
	if (node->next && strcmp(artist, node->next->artist) == 0){
	    if (strcmp(node->next->name, name) < 0){
		printf("new case");
		new->next = node->next;
		node->next = new;
		return first;//if artist duplicate found but song needs to go in front
		
	    }
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
    if (node == 0){
	return 0;
    }
    while (node->next){
	if (strcmp(node->name, name) == 0){
	    return node;
	}
	node = node->next;
    }
    if (strcmp(node->name, name) == 0){
	return node;//takes care of case at end dictionary
    }
    return 0;
}

struct songNode * findArtist(struct songNode * node, char artist[256]){
    if (node == 0){
	return 0;
    }
    while (node->next){
	if (strcmp(node->artist, artist) == 0){
	    return node;
	}
	node = node->next;
    }
    if (strcmp(node->artist, artist) == 0){
	return node;//takes care of case at end dictionary
    }
    return 0;
}

struct songNode * findRandom(struct songNode * node){
    int len = 0;
    struct songNode *first = node;
    while (node->next){//finding length of linkedlist
	len++;
	node = node->next;
    }
    int randInt = (rand()%(len + 1));
    //printf("randInt: %d\n", randInt);
    node = first;//resetting the first node
    while (randInt){//getting to required node
	node = node->next;
	randInt--;
    }
    return node;
}

struct songNode * removeNode(struct songNode * node, int which){
    //assumes that the node that is called to be removed exists in the list
    //printf("Removing node %d\n", which);
    struct songNode *first = node;
    if (which == 0){
	first = node->next;
	printf("Freeing node: %s - %s\n", node->artist, node->name);
	free(node);
	return first;
    }
    printf("Freeing node: %s - %s\n", node->next->artist, node->next->name);
    while(which - 1){
	node = node->next;
	which--;
    }
    struct songNode *hold = node->next;//a pointer to the node that will be removed(for freeing)
    node->next = node->next->next;
    free(hold);
    return first;
}


struct songNode * removeAll(struct songNode * node){
    if (node == 0){
	return 0;
    }
    while (node->next){
	node = removeNode(node, 0);
	if (node->next == 0){
	    return removeNode(node, 0);
	}
    }
    return removeNode(node, 0);
}

int findLength(struct songNode * node){
    int i = 0;
    if (node == 0){
	return i;
    }
    while (node->next){
	node = node->next;
	i++;
    }
    return i + 1;
}
