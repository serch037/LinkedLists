//
// Created by Sergio Ugalde on 2/5/19.
//

#ifndef LINKEDLISTS_LINKEDLIST_H
#define LINKEDLISTS_LINKEDLIST_H

void run();

typedef struct node node;
struct node {
    int age;
    char *name;
    node *next;
};

void addLast(node **list, int age, char *name);

char *fast_string_repr(node *list);
node *removeLast(node **list);
int list_size(node **list);
void clear(node **head);
node *get_at(node *list, int pos);
char *single_string_repr(node *list);
node *remove_at(node **list, int pos);

#endif //LINKEDLISTS_LINKEDLIST_H
