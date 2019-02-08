//
// Created by sergio on 2/8/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   int input, data;
   
   for (;;) {
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
      printf("13. print the average of ages.\n");
      printf("14. print all names that start with a given letter.\n");
      printf("0. Exit\n");
     
      scanf("%d", &input);
     
      if (input == 1) {
      }
      else if (input == 2) {
      }
      else if (input == 3){
      }
      else if (input == 4){
      } 
      else if (input == 5){
      }
      else if (input == 6){
      }
      else if (input == 7){
      }
      else if (input == 8){
      }
      else if (input == 9){
      }
      else if (input == 10){
      }
      else if (input == 11){
      }
      else if (input == 12){
      }
      else if (input == 13){
      }
      else if (input == 14){
      }
      else if (input == 0){
         break;
      }
      else
         printf("Please enter valid input.\n");      
   }
   
   return 0;
}
