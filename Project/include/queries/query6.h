#ifndef QUERY6_H
#define QUERY6_H

#include <glib.h>
#include <stdio.h>

#include "entities/airport.h"
#include "catalogs/airports_catalog.h"

/**
 * @brief Executes query 6 and writes the results to the output file.
 *
 * This function executes query 6 based on the provided arguments, utilizing the airports catalog to retrieve
 * relevant information. The results are then written to the output file. An additional flag is used for query-specific
 * formatting.
 *
 * @param airports_catalog - The airports catalog containing airport information (type: AIRPORTS_CATALOG).
 * @param arguments - The arguments given to the function (type: char*).
 * @param output - The output file to write the result (type: FILE*).
 * @param flag - The flag used to distinguish the output result (type: int).
 */
void exec_query_six(AIRPORTS_CATALOG airports_catalog, char *arguments, FILE *output, int flag);

/**
 * @brief Adds an airport to the list user_data.
 *
 * This function is used as a callback to add an airport to a list. It is designed to be used with the g_slist_foreach
 * function, where it is applied to each element in a singly-linked list.
 *
 * @param airport - The airport to be added to the list (type: AIRPORT).
 * @param user_data - The list to which the airport will be added (type: void*).
 */
void add_airport_to_list3(AIRPORT airport, void *user_data);

/**
 * @brief Sorts the list of airports by passengers.
 *
 * This function is used as a comparison function to sort a list of airports by the number of passengers. It is designed
 * to be used with the g_slist_sort function.
 *
 * @param a - The first airport (type: gconstpointer).
 * @param b - The second airport (type: gconstpointer).
 * @param user_data - Additional data (not used in this case) (type: gpointer).
 *
 * @return gint - The result of the comparison, indicating the order of the two airports.
 */
gint sort_airport_list_by_passengers(gconstpointer a, gconstpointer b, gpointer user_data);

#endif
