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
#endif //LINKEDLISTS_BETO_H