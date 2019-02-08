//
// Created by Sergio Ugalde on 2/5/19.
//
#include <stdio.h>
#include "minunit.h"
#include <stdlib.h>
#include <string.h>
#include "../src/LinkedList.h"

int tests_run = 0;

int foo = 7;
int bar = 4;

// (1, ALEJANDRO)->(2, BEATRIZ)->(3, CARLOS)
node *basic_list() {
    node *head = (node *) calloc(1, sizeof(node));
    head->age = 1;
    head->name = "A";

    node *middle = (node *) calloc(1, sizeof(node));
    middle->age = 2;
    middle->name = "B";

    node *tail = (node *) calloc(1, sizeof(node));
    tail->age = 3;
    tail->name = "C";

    head->next = middle;
    middle->next = tail;
    return head;
}

node *null_list() {
    node *head = NULL;
    return head;
}

static char *test_add_last() {
    node *node = null_list();
    addLast(&node, 1, "A");

    char *repr = fast_string_repr(node);
    int ans = strcmp(repr, "(1, A), ");
    mu_assert("Error null", ans == 0);
    free(repr);
    free(node);

    node = basic_list();
    addLast(&node, 4, "D");
    repr = fast_string_repr(node);
    ans = strcmp(repr, "(1, A), (2, B), (3, C), (4, D), ");

    mu_assert("Error basic", ans == 0);
    free(repr);
    clear(&node);
    return 0;
}

static char *test_remove_last() {
    node *head = NULL;
    node *removed = removeLast(&head);
    char *repr = fast_string_repr(head);
    int ans = strcmp(repr, "");
    mu_assert("Error null", ans == 0);

    free(repr);
    free(head);

    head = basic_list();
    removeLast(&head);
    repr = fast_string_repr(head);
    ans = strcmp(repr, "(1, A), (2, B), ");
    mu_assert("Error basic", ans == 0);
    clear(&head);
    free(head);
    free(repr);
    return 0;
}

static char *test_size() {
    node *head = NULL;
    int size = list_size(&head);
    mu_assert("Error null", size == 0);
    free(head);

    head = basic_list();
    size = list_size(&head);
    mu_assert("Error basic", size == 3);
    clear(&head);
    return 0;
}

static char *test_clear() {
    node *head = NULL;
    clear(&head);
    int size = list_size(&head);
    mu_assert("Error null", size == 0);
    free(head);

    head = basic_list();
    clear(&head);
    size = list_size(&head);
    mu_assert("Error basic", size == 0);
    return 0;
}

static char *test_get_at() {
    // Get node 0 when size is 0
    node *head = NULL;
    node *node = get_at(head, 0);
    char *repr = fast_string_repr(head);
    int ans = strcmp(repr, "");
    mu_assert("Error null", ans == 0);
    free(repr);

    // Get node -1 when size is 0
    // Get node 1 when size is 0

    // Get node 1 when size is 3
    // Get node 3 when size is 3

    // Get node 0 when size is 3
    head = basic_list();
    node = get_at(head, 0);
    repr = single_string_repr(node);
    ans = strcmp(repr, "(1, A), ");
    mu_assert("Error basic", ans == 0);
    free(repr);

    // Get node 2 when size is 3
    node = get_at(head, 2);
    repr = single_string_repr(node);
    ans = strcmp(repr, "(3, C), ");
    mu_assert("Error basic", ans == 0);
    free(repr);


    node = get_at(head, 1);
    repr = single_string_repr(node);
    ans = strcmp(repr, "(2, B), ");
    mu_assert("Error basic", ans == 0);
    free(repr);

    clear(&head);
    return 0;
}

static char *test_remove_at() {
    // Get node 0 when size is 0
    node *head = NULL;
    node *node = remove_at(&head, 0);
    char *repr = fast_string_repr(node);
    int ans = strcmp(repr, "");
    mu_assert("Error null", ans == 0);
    free(repr);

    // Get node -1 when size is 0
    // Get node 1 when size is 0

    // Get node 1 when size is 3
    // Get node 3 when size is 3

    // Get node 0 when size is 3
    head = basic_list();
    node = remove_at(&head, 0);
    repr = single_string_repr(node);
    ans = strcmp(repr, "(1, A), ");
    mu_assert("Error basic", ans == 0);
    free(repr);

    // Get node 2 when size is 3
    node = remove_at(&head, 2);
    repr = single_string_repr(node);
    ans = strcmp(repr, "(3, C), ");
    mu_assert("Error basic", ans == 0);
    free(repr);


    node = remove_at(&head, 1);
    repr = single_string_repr(node);
    ans = strcmp(repr, "(2, B), ");
    mu_assert("Error basic", ans == 0);
    free(repr);

    clear(&head);
    return 0;
}

static char *all_tests() {
    mu_run_test(test_add_last);
    mu_run_test(test_remove_last);
    mu_run_test(test_size);
    mu_run_test(test_clear);
    mu_run_test(test_get_at);
    mu_run_test(test_remove_at);
    return 0;
}


int run_tests() {
    char *result = all_tests();
    if (result != 0) {
        printf("\n%s\n", result);
    } else {
        printf("\nALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
