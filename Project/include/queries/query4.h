#ifndef QUERY4_H
#define QUERY4_H

#include <stdio.h>
#include <glib.h>

#include "catalogs/reservations_catalog.h"
#include "catalogs/hotels_catalog.h"

/**
 * @brief Writes a list of hotel reservations ordered by begin date to the output file.
 *
 * This function writes a list of hotel reservations ordered by begin date to the output file. The reservation IDs
 * are stored in a GArray, and the reservations catalog is used to retrieve additional information. An additional flag
 * is used to distinguish the output result, providing flexibility for query-specific formatting.
 *
 * @param reservation_list GArray containing a list of reservation IDs (type: GArray*).
 * @param reservations_catalog The reservations catalog containing reservation information (type: RESERVATIONS_CATALOG).
 * @param output The output file to write the result (type: FILE*).
 * @param flag The flag used to distinguish the output result (type: int).
 */
void _write_hotel_reservations_(GArray *reservation_list, RESERVATIONS_CATALOG reservations_catalog, FILE *output, int flag);

/**
 * @brief Executes query 4 and writes the results to the output file.
 *
 * This function executes query 4, retrieving relevant information from the reservations catalog based on the provided
 * arguments. The results, such as a list of hotel reservations ordered by begin date, are written to the output file.
 * An additional flag is used for query-specific formatting.
 *
 * @param hotels_catalog The hotels catalog containing hotel information (type: HOTELS_CATALOG).
 * @param reservations_catalog The reservations catalog containing reservation information (type: RESERVATIONS_CATALOG).
 * @param arguments The arguments given to the function (type: char*).
 * @param output The output file to write the result (type: FILE*).
 * @param flag The flag used to distinguish the output result (type: int).
 */
void exec_query_four(HOTELS_CATALOG hotels_catalog, RESERVATIONS_CATALOG reservations_catalog, char *arguments, FILE *output, int flag);


#endif