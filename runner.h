//
// Created by sergio on 2/8/19.
//

#ifndef LINKEDLISTS_RUNNER_H
#define LINKEDLISTS_RUNNER_H
#include "beto.h"
node_t *parse_csv();
double average(node_t *head);
void print_filtered(node_t *head, char a_char);
void printYoungest(node_t *theList);
void printOldest(node_t *theList);

#endif //LINKEDLISTS_RUNNER_H
