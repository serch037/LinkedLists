// Alberto
// Sergio
// Alexa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "beto.h"
#include "runner.h"

int main() {
    int input, data;
    node_t *list = NULL;
    char name[10];
    int age;
    int index;
    node_t *n = NULL;
    char a_char;

    list = parse_csv();
    do {
        printf("\n");
        printf("1. Adding an item to the end of the list.\n");
        printf("2. Iterating over a list.\n");
        printf("3. Adding an item to the beginning of the list (pushing to the list).\n");
        printf("4. Removing the first item (popping from the list).\n");
        printf("5. Removing the first item of the list.\n");
        printf("6. Removing a specific item. \n");
        printf("7. Size of the linked List. \n");
        printf("8. Get element of the linked list. \n");
        printf("9. Clear the linked list. \n");
        printf("10. Print the linked list.\n");
        printf("11. Print the oldest person.\n");
        printf("12. Print the youngest person.\n");
        printf("13. Print the average of ages.\n");
        printf("14. Print all names that start with a given letter.\n");
        printf("0. Exit\n");

        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("\nGive me a Name: ");
                scanf("%s", name);
                printf("\nGive me an Age: ");
                scanf("%d", &age);
                append(age, name, &list);
                break;
            case 2:
                iterate(list);
                break;
            case 3:
                printf("\nGive me a Name: ");
                scanf("%s", name);
                printf("\nGive me an Age: ");
                scanf("%d", &age);
                pushFirst(age, name, &list);
                iterate(list);
                break;
            case 4:
                popFirst(&list);
                break;
            case 5:
                //FALTA
                break;
            case 6:
                printf("\nGive me a Name: ");
                scanf("%s", name);
                printf("\nGive me an Age: ");
                scanf("%d", &age);
                removeElement(age, name, &list);
                break;
            case 7:
                printf("\nSize of list: %d", sizeOfList(&list));
                break;
            case 8:
                printf("\nGive me an index: ");
                scanf("%d", &index);
                n = getElement(index, &list);
                printf("\nName: %s\nAge: %d", n->name, n->age);
                break;
            case 9:
                clearList(&list);
                break;
            case 10:
                print(list);
                break;
            case 11:
                printOldest(list);
                break;
            case 12:
                printYoungest(list);
                break;
            case 13:
                printf("\nThe average of the ages is: %f\n",average(list));
                break;
            case 14:
                printf("\nEnter a character: ");
                scanf(" %c", &a_char);
                print_filtered(list, a_char);
                break;
            default:
                break;
        }
    } while (input != 0);

    return 0;
}
