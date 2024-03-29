#ifndef QUERY3_H
#define QUERY3_H

#include <stdio.h>
#include "catalogs/hotels_catalog.h"

/**
 * @brief Writes the average rating of a hotel to the output file.
 *
 * This function writes the average rating of a hotel to the output file. The rating is provided as a double,
 * and an additional flag is used to distinguish the output result. It is used to generate output results for
 * query 3, and the flag helps determine specific formatting for the result.
 *
 * @param rating The average rating to print (type: double).
 * @param output The output file to write the result (type: FILE*).
 * @param flag The flag used to distinguish the output result (type: int).
 */
void _write_hotel_rating_(double rating, FILE *output, int flag);

/**
 * @brief Executes query 3 and writes the results to the output file.
 *
 * This function executes query 3, retrieving relevant information from the hotels catalog based on the provided
 * arguments. The results, such as the average rating, are written to the output file, and an additional flag is used
 * for query-specific formatting.
 *
 * @param hotels_catalog The hotels catalog containing hotel information (type: HOTELS_CATALOG).
 * @param arguments The arguments given to the function (type: char*).
 * @param output The output file to write the result (type: FILE*).
 * @param flag The flag used to distinguish the output result (type: int).
 */
void exec_query_three(HOTELS_CATALOG hotels_catalog, char *arguments, FILE *output, int flag);

#endif