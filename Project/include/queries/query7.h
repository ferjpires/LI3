#ifndef QUERY7_H
#define QUERY7_H

#include <glib.h>
#include <stdio.h>

#include "catalogs/flights_catalog.h"
#include "catalogs/airports_catalog.h"
#include "entities/airport.h"

/**
 * @brief Executes query 7 and writes the results to the output file.
 *
 * This function executes query 7 based on the provided arguments, utilizing the flights catalog and airports catalog
 * to retrieve relevant information. The results are then written to the output file. An additional flag is used for
 * query-specific formatting.
 *
 * @param flights_catalog - The flight catalog containing flight information (type: FLIGHTS_CATALOG).
 * @param airports_catalog - The airports catalog containing airport information (type: AIRPORTS_CATALOG).
 * @param arguments - The arguments given to the function (type: char*).
 * @param output - The output file to write the result (type: FILE*).
 * @param flag - The flag used to distinguish the output result (type: int).
 */
void exec_query_seven(FLIGHTS_CATALOG flights_catalog, AIRPORTS_CATALOG airports_catalog,
                      char *args, FILE *output, int flag);

/**
 * @brief Adds an airport to the list user_data if it has any entry on the delay list.
 *
 * This function is used as a callback to add an airport to a list if it has any entry on the delay list. It is designed
 * to be used with the g_slist_foreach function, where it is applied to each element in a singly-linked list.
 *
 * @param airport - The airport to be added to the list (type: AIRPORT).
 * @param user_data - The list to which the airport will be added if it has any entry on the delay list (type: void*).
 */
void add_airport_to_list2(AIRPORT airport, void *user_data);

/**
 * @brief Sorts the list of airports by median.
 *
 * This function is used as a comparison function to sort a list of airports by their median. It is designed to be used
 * with the g_slist_sort function.
 *
 * @param a - The first airport (type: gconstpointer).
 * @param b - The second airport (type: gconstpointer).
 *
 * @return gint - The result of the comparison, indicating the order of the two airports.
 */
gint sort_airport_list_by_median(gconstpointer a, gconstpointer b);

#endif