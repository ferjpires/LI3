#ifndef QUERY2_H
#define QUERY2_H

#include <glib.h>

#include <stdio.h>
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/users_catalog.h"

/**
 * @brief Writes a list of flights for a user to the output file.
 *
 * This function writes a list of flights for a user to the output file, including flight details
 * such as flight_id, schedule_departure_date, and additional flight information. It is used to generate
 * a list of flights either for queries or regular output.
 *
 * @param in_order_flight_list GArray containing a list of flight ids for a user.
 * @param flights_catalog The flights catalog with all information in HashTables.
 * @param output File to write the flight list.
 * @param flag If == 1, it's a query flag; else, it's a normal query.
 */
void _write_user_flights_(GArray *in_order_flight_list, FLIGHTS_CATALOG flights_catalog, FILE *output, int flag);

/**
 * @brief Writes a list of reservations for a user to the output file.
 *
 * This function writes a list of reservations for a user to the output file, including reservation details
 * such as reservation_id, begin_date, end_date, and additional reservation information. It is used to generate
 * a list of reservations either for queries or regular output.
 *
 * @param in_order_reservation_list GArray containing a list of reservation ids for a user.
 * @param reservations_catalog Catalog containing the reservations.
 * @param output File to write the reservation list.
 * @param flag If == 1, it's a query flag; else, it's a normal query.
 */
void _write_user_reservations_(GArray *in_order_reservation_list, RESERVATIONS_CATALOG reservations, FILE *output, int flag);

/**
 * @brief Writes a combined list of flights and reservations for a user to the output file.
 *
 * This function writes a combined list of flights and reservations for a user to the output file, including
 * flight and reservation details. It is used to generate a combined list of flights and reservations either
 * for queries or regular output.
 *
 * @param in_order_flight_list GArray containing a list of flight ids for a user.
 * @param in_order_reservation_list GArray containing a list of reservation ids for a user.
 * @param flights_catalog Catalog containing the flights.
 * @param reservations_catalog Catalog containing the reservations.
 * @param output File to write the combined list.
 * @param flag If == 1, it's a query flag; else, it's a normal query.
 */
void _write_user_flights_reservations_(GArray *in_order_reservation_list, GArray *in_order_flight_list,
                                       FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                                       FILE *output, int flag);

/**
 * @brief Executes query 2 and writes the results to the output file.
 *
 * This function executes query 2, retrieving relevant information from the users, flights,
 * and reservations catalogs based on the provided arguments. The results are written to the
 * output file, and additional flags are used for query-specific formatting.
 *
 * @param users_catalog Catalog containing user information.
 * @param flights_catalog Catalog containing flight information.
 * @param reservations_catalog Catalog containing reservation information.
 * @param arguments Arguments (name and type - reservation or flight).
 * @param output Output file to write the query results.
 * @param flag If == 1, it's a query flag; else, it's a normal query.
 */
void exec_query_two(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                    char *arguments, FILE *output, int flag);

#endif