//
// Created by sergio on 2/8/19.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "beto.h"


node_t *parse_csv() {
    FILE *stream = fopen("dataC.csv", "r");
    node_t *head = NULL;
    char buffer[255];
    while (fgets(buffer, 255, stream)) {
        char *name = (char *) calloc(8, sizeof(char));
        strcpy(name, strtok(buffer, ","));
        int age = atoi(strtok(NULL, ","));
        append(age, name, &head);
        free(name);
    }
    free(stream);
    return head;
}

double average(node_t *head) {
    node_t *currNode = head;
    double sum = 0;
    double count = 0;
    while (currNode) {
        sum += currNode->age;
        ++count;
        currNode = currNode->next;
    }
    return sum / count;
}



void print_filtered(node_t *head, char a_char) {
    node_t *currNode = head;
    while (currNode) {
        if (currNode->name[0] == a_char) {
            printf("\n%s\n", currNode->name);
        }
        currNode = currNode->next;
    }
}


void printYoungest(node_t *theList) {
    node_t *youngest = theList;
    node_t *i = theList->next;
    while (i != NULL) {
        if (i->age < youngest->age) {
            youngest = i;
        }
        i = i->next;
    }
    if (youngest != NULL) {
        printf("%s %d", youngest->name, youngest->age);
    } else {
        printf("List is empty");
    }
}

void printOldest(node_t *theList) {
    node_t *oldest = theList;
    node_t *i = theList->next;
    while (i != NULL) {
        if (i->age > oldest->age) {
            oldest = i;
        }
        i = i->next;
    }
    if (oldest != NULL) {
        printf("%s %d", oldest->name, oldest->age);
    } else {
        printf("List is empty");
    }
}


