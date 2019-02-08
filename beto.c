// A01336656 | José Alberto Jurado Hernández

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "beto.h"



void append(int age, char *name, node_t **theList) {
  node_t *newS = (node_t *) malloc(sizeof(node_t));
  newS ->age = age;
  newS -> name = name;
  newS->next = NULL;
  if(*theList == NULL){
    *theList = newS;
  }else{
    node_t * temp = *theList;
    while(  temp-> next != NULL ){
      temp = temp->next;
    }
    temp->next = newS;
  }
}

void print(  node_t * pointerToList ) {
node_t * temp = pointerToList;
  printf("[");
    while(  temp != NULL ){
      printf("%d   %s ", temp->age, temp->name);
      temp = temp->next;
    }
    printf("]");
}

void iterate(node_t *pointerToList) {
  node_t * temp = pointerToList;
  printf("[");
  while(  temp != NULL ){
    printf("%d %s, ", temp->age, temp->name);
    temp = temp->next;
  }
  printf("]\n");
}

void pushFirst(int age, char * name, node_t ** theList) {
  node_t * newS = (node_t *) malloc(sizeof(node_t));
  newS -> age = age;
  newS -> name = name;
  newS -> next = *theList;
  *theList = newS;
}

void popFirst(node_t ** theList){
  node_t * first = *theList;
  *theList = first -> next;
  free(first);
}

void removeElement(int age, char * name, node_t ** theList){
  node_t * temp1 = NULL;
  node_t * temp2 = *theList;
  while(temp2 != NULL){
    if(temp2->age == age && temp2->name == name){
      if(temp1 != NULL){
        temp1->next = temp2->next;
      } else {
        *theList = temp2->next;
      }
      free(temp2);
      break;
    }
    temp1 = temp2;
    temp2 = temp2->next;
  }
}

int sizeOfList(node_t ** theList){
  int size = 0;
  node_t * i = *theList;
  while(i != NULL){
    size++;
    i = i->next;
  }
  return size;
}

node_t * getElement(int index, node_t ** theList){
  int i = 0;
  node_t * nd = *theList;
  while(nd != NULL){
    if(i == index){
      return nd;
    } else {
      nd = nd->next;
      i++;
    }
  }
  return NULL;
}

void clearList(node_t ** theList){
  node_t * temp = *theList;
  while(*theList != NULL){
    *theList = temp->next;
    free(temp);
    temp = *theList;
  }
}

int test(void) {
  node_t * list = NULL;
  iterate(list);
  append(50, "Bono", &list);
  append(67, "Bono 1", &list);
  append(89, "Bono 2", &list);
  pushFirst(23, "Bono 3", &list);
  iterate(list);
  printf("Size of list: %d\n", sizeOfList(&list));
  removeElement(23, "Bono 3", &list);
  iterate(list);
  printf("Size of list: %d\n", sizeOfList(&list));
  int a;
  /*
  printf("Enter index of element: ");
  scanf("%d", &a);
  node_t * n = getElement(a, &list);
  if(n != NULL){
    printf("%d %s\n", n->age, n->name);
  } else {
    printf("List is not that long.\n");
  }
  */
  clearList(&list);
  iterate(list);
  printf("Hello World\n");
  return 0;
}
