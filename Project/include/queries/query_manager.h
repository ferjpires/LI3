#ifndef QUERY_MANAGER_H
#define QUERY_MANAGER_H

#include "catalogs/users_catalog.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/airports_catalog.h"
#include "catalogs/hotels_catalog.h"
#include "stats/metrics_catalog.h"

/**
 * @brief Processes a line from the input, executing relevant queries or operations.
 *
 * This function takes a line from the input and performs the corresponding actions,
 * such as executing queries on user, flight, and reservation catalogs. It interacts
 * with the provided catalogs and metrics to update and retrieve information.
 *
 * @param line The string read from the input of type 'char*'.
 * @param input_line The line number being processed from the input of type 'int'.
 * @param users_catalog The catalog containing user information of type 'USERS_CATALOG'.
 * @param flights_catalog The catalog containing flight information of type 'FLIGHTS_CATALOG'.
 * @param reservations_catalog The catalog containing reservation information of type 'RESERVATIONS_CATALOG'.
 * @param airports_catalog The array containing ordered airports by median of type 'GArray*'.
 * @param hotels_catalog The catalog containing hotel information of type 'HOTELS_CATALOG'.
 * @param metrics The catalog containing metrics information of type 'METRICS_CATALOG'.
 */
void process_line(char *line, int input_line, USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog,
                  RESERVATIONS_CATALOG reservations_catalog, AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog,
                  METRICS_CATALOG metrics);

/**
 * @brief Reads and processes each line from the queries file.
 *
 * This function reads each line from the provided queries file and invokes the query
 * manager to execute the corresponding actions. It utilizes the provided catalogs and metrics
 * to update and retrieve information as required by the queries.
 *
 * @param users_catalog The catalog containing user information of type 'USERS_CATALOG'.
 * @param flights_catalog The catalog containing flight information of type 'FLIGHTS_CATALOG'.
 * @param reservations_catalog The catalog containing reservation information of type 'RESERVATIONS_CATALOG'.
 * @param airports_catalog The array containing ordered airports by median of type 'GArray*'.
 * @param hotels_catalog The catalog containing hotel information of type 'HOTELS_CATALOG'.
 * @param queries_file The input file containing queries of type 'FILE'.
 * @param metrics The catalog containing metrics information of type 'METRICS_CATALOG'.
 */
void read_file(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
               AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, FILE *queries_file, METRICS_CATALOG metrics);

/**
 * @brief Manages the execution of queries given in the input file.
 *
 * This function reads and processes queries from the provided input file, invoking
 * the query manager to execute corresponding actions. It interacts with the provided catalogs
 * and metrics to update and retrieve information based on the queries.
 *
 * @param users_catalog The catalog containing user information of type 'USERS_CATALOG'.
 * @param flights_catalog The catalog containing flight information of type 'FLIGHTS_CATALOG'.
 * @param reservations_catalog The catalog containing reservation information of type 'RESERVATIONS_CATALOG'.
 * @param airports_catalog The catalog containing airport information of type 'AIRPORTS_CATALOG'.
 * @param hotels_catalog The catalog containing hotel information of type 'HOTELS_CATALOG'.
 * @param queries_file The input file containing queries of type 'FILE'.
 * @param metrics The catalog containing metrics information of type 'METRICS_CATALOG'.
 */
void query_manager(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                   AIRPORTS_CATALOG airports_catalog, HOTELS_CATALOG hotels_catalog, FILE *queries_file, METRICS_CATALOG metrics);

#endif