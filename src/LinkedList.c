//
// Created by Sergio Ugalde on 2/5/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void print(node *list) {
    node *tmpNode = list;
    while (tmpNode) {
        printf("(%d, %s), ", tmpNode->age, tmpNode->name);
        tmpNode = tmpNode->next;
    }
    printf("\n");
}


char *single_string_repr(node *list) {
    char *result = NULL;
    size_t resultSize = 0;
    FILE *stream = open_memstream(&result, &resultSize);
    fprintf(stream, "(%d, %s), ", list->age, list->name);
    fclose(stream);
    return result;
}


char *fast_string_repr(node *list) {
    char *result = NULL;
    size_t resultSize = 0;
    FILE *stream = open_memstream(&result, &resultSize);
    node *tmpNode = list;
    while (tmpNode) {
        fprintf(stream, "(%d, %s), ", tmpNode->age, tmpNode->name);
        tmpNode = tmpNode->next;
    }
    fclose(stream);
    return result;
}


node *newNode(int age, char *name) {
    node *toAdd = (node *) calloc(1, sizeof(node));
    toAdd->age = age;
    toAdd->name = name;
    return toAdd;
}


void addLast(node **list, int age, char *name) {
    node *toAdd = newNode(age, name);

    if (*list == NULL) {
        *list = toAdd;
        return;
    }

    node *tmpNode = *list;
    while (tmpNode->next) {
        tmpNode = tmpNode->next;
    }
    tmpNode->next = toAdd;
}

void addFirst(node **list, int age, char *name) {
    node *toAdd = newNode(age, name);

    if (*list == NULL) {
        *list = toAdd;
        return;
    }

    node *tmpNode = *list;
    toAdd->next = tmpNode;
    *list = toAdd;

}

node *removeFirst(node **list) {
    node *tmpNode = *list;
    *list = tmpNode->next;
    return tmpNode;
}


node *removeLast(node **list) {
    node *pointer_to_last = *list;
    node *tmpnode = *list;
    if (tmpnode == NULL) return NULL;
    // Move pointer to end
    while (tmpnode->next) {
        pointer_to_last = tmpnode;
        tmpnode = tmpnode->next;
    };
    free(pointer_to_last->next);
    pointer_to_last->next = NULL;
    return tmpnode;
}


int list_size(node **list) {
    node *tmpnode = *list;
    int ans = 0;
    while (tmpnode) {
        ++ans;
        tmpnode = tmpnode->next;
    }
    return ans;
}


void clear(node **theList) {
    node *temp = *theList;
    while (*theList != NULL) {
        *theList = temp->next;
        free(temp);
        temp = *theList;
    }

}


// Uses 0 based indexing
node *get_at(node *list, int pos) {
    if (pos < 0) exit(-1);
    int count = 0;
    node *tmp = list;
    while (tmp && count < pos) {
        tmp = tmp->next;
        ++count;
    }
    if (pos != count) exit(-1);
    return tmp;
}

node *remove_at(node **list, int pos) {
    return NULL;
}

/*


*/
void run() {
    node *null = NULL;
    print(null);
    addLast(&null, 1, "José");
    print(null);
    addLast(&null, 2, "Josefa");
    print(null);
    addFirst(&null, 3, "Carlos");
    print(null);
    removeFirst(&null);
    print(null);
    printf("%s", fast_string_repr(null));
    /*
    node *head = (node *) calloc(1, sizeof(node));
    head->age = 1;
    head->name = "José";

    addLast(head, 3, "Daniel");
    print(head);
     */
}


