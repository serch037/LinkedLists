//
// Created by Sergio Ugalde on 2/5/19.
//

#ifndef LINKEDLISTS_MINUNIT_H
#define LINKEDLISTS_MINUNIT_H
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

int run_tests();
extern int tests_run;
#endif //LINKEDLISTS_MINUNIT_H
