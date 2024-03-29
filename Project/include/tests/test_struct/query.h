#ifndef QUERY_H
#define QUERY_H

#include <glib.h>

typedef struct query *QUERY;

/**
 * @brief Creates a new query.
 *
 * This function creates and returns a new query structure with default values.
 *
 * @return A new query structure (type: QUERY).
 */
QUERY create_query(void);

/**
 * @brief Gets the time taken to execute a query.
 *
 * This function retrieves the time taken to execute the given query.
 *
 * @param query - The query to get the time from (type: QUERY).
 * @return The time taken to execute the query (type: double).
 */
double get_query_time(QUERY query);

/**
 * @brief Sets the time taken to execute a query.
 *
 * This function sets the time taken to execute the given query.
 *
 * @param query - The query to set the time for (type: QUERY).
 * @param time - The time taken to execute the query (type: double).
 */
void set_query_time(QUERY query, double time);

/**
 * @brief Gets the number of queries in a query structure.
 *
 * This function retrieves the total number of queries stored in the given query structure.
 *
 * @param query - The query structure to get the number of queries from (type: QUERY).
 * @return The total number of queries in the query structure (type: int).
 */
int get_query_number_of_queries(QUERY query);

/**
 * @brief Sets the number of queries in a query structure.
 *
 * This function sets the total number of queries in the given query structure.
 *
 * @param query - The query structure to set the number of queries for (type: QUERY).
 * @param number_of_queries - The total number of queries to set (type: int).
 */
void set_query_number_of_queries(QUERY query, int number_of_queries);

/**
 * @brief Gets the total number of correct queries in a query structure.
 *
 * This function retrieves the total number of correct queries stored in the given query structure.
 *
 * @param query - The query structure to get the total number of correct queries from (type: QUERY).
 * @return The total number of correct queries in the query structure (type: int).
 */
int get_query_total_correct_queries(QUERY query);

/**
 * @brief Sets the total number of correct queries in a query structure.
 *
 * This function sets the total number of correct queries in the given query structure.
 *
 * @param query - The query structure to set the total number of correct queries for (type: QUERY).
 * @param total_correct_queries - The total number of correct queries to set (type: int).
 */
void set_query_total_correct_queries(QUERY query, int total_correct_queries);

/**
 * @brief Gets the array of failed queries in a query structure.
 *
 * This function retrieves the array of failed queries (line numbers) stored in the given query structure.
 *
 * @param query - The query structure to get the failed queries from (type: QUERY).
 * @return The array of failed queries (line numbers) in the query structure (type: GArray*).
 */
GArray *get_query_failed_queries(QUERY query);

/**
 * @brief Sets the failed queries in a query structure.
 *
 * This function sets the failed query information (line number) in the given query structure.
 *
 * @param query - The query structure to set the failed queries for (type: QUERY).
 * @param failed_query - The line number of the failed query (type: int).
 * @param line_failed - The specific line where the query failed (type: int).
 */
void set_query_failed_queries(QUERY query, int failed_query, int line_failed);

/**
 * @brief Destroys a query structure.
 *
 * This function is a callback function used to destroy a query structure. It is intended to be used with functions like
 * `g_list_free_full()` when freeing a list of queries.
 *
 * @param data - The query structure to be destroyed (type: gpointer).
 */
void query_destroy_function(gpointer data);

#endif