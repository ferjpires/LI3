#ifndef QUERY5_H
#define QUERY5_H

#include <stdio.h>
#include "catalogs/flights_catalog.h"
#include "catalogs/airports_catalog.h"

/**
 * @brief Executes query 5 and writes the results to the output file.
 *
 * This function executes query 5 based on the provided arguments, utilizing the flight and airport catalogs to retrieve
 * relevant information. The results are then written to the output file. An additional flag is used for query-specific
 * formatting.
 *
 * @param airports_catalog The airport catalog containing airport information (type: AIRPORTS_CATALOG).
 * @param flights_catalog The flight catalog containing flight information (type: FLIGHTS_CATALOG).
 * @param arguments The arguments given to the function (type: char*).
 * @param output The output file to write the result (type: FILE*).
 * @param flag The flag used to distinguish the output result (type: int).
 */
void exec_query_five(AIRPORTS_CATALOG airports_catalog, FLIGHTS_CATALOG flights_catalog, char *arguments, FILE *output, int flag);

#endif