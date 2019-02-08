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
