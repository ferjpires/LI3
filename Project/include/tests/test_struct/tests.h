#ifndef TESTS_H
#define TESTS_H

#include <glib.h>
#include "tests/test_struct/query.h"

typedef struct test *TEST;

/**
 * @brief Creates a new TEST instance.
 *
 * This function allocates memory for a new TEST structure and initializes its internal data.
 *
 * @return A pointer to the newly created TEST structure.
 */
TEST create_test();

/**
 * @brief Retrieves the parsing time from a TEST instance.
 *
 * This function returns the parsing time recorded in the provided TEST structure.
 *
 * @param test The TEST instance.
 *
 * @return A double representing the parsing time.
 */
double get_parser_time(TEST test);

/**
 * @brief Sets the parsing time in a TEST instance.
 *
 * This function sets the parsing time in the provided TEST structure.
 *
 * @param test The TEST instance.
 * @param time A double representing the parsing time to be set.
 */
void set_parser_time(TEST test, double time);

/**
 * @brief Retrieves the queries execution time from a TEST instance.
 *
 * This function returns the queries execution time recorded in the provided TEST structure.
 *
 * @param test The TEST instance.
 *
 * @return A double representing the queries execution time.
 */
double get_queries_time(TEST test);

/**
 * @brief Sets the queries execution time in a TEST instance.
 *
 * This function sets the queries execution time in the provided TEST structure.
 *
 * @param test The TEST instance.
 * @param time A double representing the queries execution time to be set.
 */
void set_queries_time(TEST test, double time);

/**
 * @brief Retrieves the total execution time from a TEST instance.
 *
 * This function returns the total execution time recorded in the provided TEST structure.
 *
 * @param test The TEST instance.
 *
 * @return A double representing the total execution time.
 */
double get_total_time(TEST test);

/**
 * @brief Sets the total execution time in a TEST instance.
 *
 * This function sets the total execution time in the provided TEST structure.
 *
 * @param test The TEST instance.
 * @param time A double representing the total execution time to be set.
 */
void set_total_time(TEST test, double time);

/**
 * @brief Looks up a QUERY in a TEST instance based on the query number.
 *
 * This function retrieves the QUERY associated with a specific query number from
 * the provided TEST structure.
 *
 * @param test The TEST instance.
 * @param query_number The number of the query to be looked up.
 *
 * @return The QUERY associated with the specified query number, or NULL if not found.
 */
QUERY lookup_query(TEST test, int query_number);

/**
 * @brief Frees the memory allocated for a TEST instance and its contents.
 *
 * This function releases all the memory allocated for the TEST instance and its associated
 * QUERYs. It should be called when the TEST instance is no longer needed to avoid memory leaks.
 *
 * @param test The TEST instance to be freed.
 */
void free_tests(TEST test);

#endif