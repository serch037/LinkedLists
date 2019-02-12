//
// Created by sergio on 2/8/19.
//

#ifndef LINKEDLISTS_BETO_H
#define LINKEDLISTS_BETO_H
struct node {
    int age;
    char * name;
    struct node *next;
};
typedef struct node node_t;
void append(int age, char * name, node_t **theList );
void iterate(  node_t * pointerToList );
void append(int age, char *name, node_t **theList);
void print(  node_t * pointerToList );
void iterate(node_t *pointerToList);
void pushFirst(int age, char * name, node_t ** theList);
void popFirst(node_t ** theList);
void removeElement(int age, char * name, node_t ** theList);
int sizeOfList(node_t ** theList);
node_t * getElement(int index, node_t ** theList);
void clearList(node_t ** theList);
#endif //LINKEDLISTS_BETO_H
