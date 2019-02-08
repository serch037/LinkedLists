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
    node_t * list = NULL;
    iterate(list);
    
    node_t *head = parse_csv();
    do {
        printf("1. Adding an item to the end of the list.\n");
        printf("2. Iterating over a list.\n");
        printf("3. Adding an item to the beginning of the list (pushing to the list).\n");
        printf("4. Removing the first item (popping from the list).\n");
        printf("5. Removing the last item of the list.\n");
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
                printf("Give me a Name");
                scanf("%s", name);
                printf("Give me an Age");
                scanf("%s", age);
                append(age, name, &list);
                break;
            case 2:
                iterate(list);
                break;
            case 3:
                printf("Give me a Name");
                scanf("%s", name);
                printf("Give me an Age");
                scanf("%s", age);
                pushFirst(age, name, &list);
                iterate(list);
                break;
            case 4:
                popFirst(** theList)
                break;
            case 5:
                printf("%s\n",);
                break;
            case 6:
                printf("%s\n",);
                break;
            case 7:
                printf("Size of list: %d\n", sizeOfList(&list));
                break;
            case 8:
                printf("%s\n",);
                break;
            case 9:
                clearList(&list);
                iterate(list);
                break;
            case 10:
                print(list);
                break;
            case 11:
                printOldest(*theList);
                printf("%s The oldest person is: \n",);
                break;
            case 12:
                printYoungest(*theList);
                printf("%s The youngest person is\n",);
                break;
            case 13:
                average(*head);
                //No estoy segura de como ponerlo para que imprima el promedio :(
                printf("The average of the ages is: \n",);
                break;
            case 14:
                printf("\n %p Enter a character:",);
                char a_char;
                scanf("%c", &a_char);
                print_filtered(head, a_char);
                break;
        }
    } while (input != 0);

    return 0;
}
