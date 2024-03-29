#ifndef RESULTS_H
#define RESULTS_H

#include <stdio.h>
#include "tests/test_struct/tests.h"
#include "tests/test_struct/query.h"

/**
 * @brief Writes the results of test cases to an output destination.
 *
 * This function takes a TEST structure containing information about multiple test cases,
 * including parsing time, query execution time, and overall test duration. It writes
 * these results to the specified output destination, which can be a file, console, or any
 * other suitable destination for test results.
 *
 * @param tests The TEST structure containing information about multiple test cases.
 */
void write_results(TEST tests);

#endif