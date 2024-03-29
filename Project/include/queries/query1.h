#ifndef QUERY1_H
#define QUERY1_H

#include <stdio.h>
#include "entities/flight.h"
#include "entities/reservation.h"
#include "entities/user.h"
#include "catalogs/flights_catalog.h"
#include "catalogs/reservations_catalog.h"
#include "catalogs/users_catalog.h"

/**
 * @brief Writes the user resume to the output file.
 *
 * This function writes user-related information to the output file, including user details
 * and additional flags if specified. It is used to generate user resumes either for queries
 * or regular output.
 *
 * @param user_id User id of the respective user.
 * @param user User details.
 * @param output Output file to write the user resume.
 * @param flag If == 1, it's a query flag; else, it's a normal query.
 */
void _write_user_resume(char *user_id, USER user, FILE *output, int flag);

/**
 * @brief Writes the reservation resume to the output file.
 *
 * This function writes reservation-related information to the output file, including reservation details
 * and additional flags if specified. It is used to generate reservation resumes either for queries
 * or regular output.
 *
 * @param reservation_id Reservation id of the respective reservation.
 * @param reservation Reservation details.
 * @param output Output file to write the reservation resume.
 * @param flag If == 1, it's a query flag; else, it's a normal query.
 */
void _write_reservation_resume(char *reservation_id, RESERVATION reservation, FILE *output, int flag);

/**
 * @brief Writes the flight resume to the output file.
 *
 * This function writes flight-related information to the output file, including flight details
 * and additional flags if specified. It is used to generate flight resumes either for queries
 * or regular output.
 *
 * @param flight_id Flight id of the respective flight.
 * @param flight Flight details.
 * @param output Output file to write the flight resume.
 * @param flag If == 1, it's a query flag; else, it's a normal query.
 */
void _write_flight_resume(char *flight_id, FLIGHT flight, FILE *output, int flag);

/**
 * @brief Executes query 1 and writes the results to the output file.
 *
 * This function executes query 1, retrieving relevant information from the users, flights,
 * and reservations catalogs based on the provided arguments. The results are written to the
 * output file, and additional flags are used for query-specific formatting.
 *
 * @param users_catalog Catalog containing user information.
 * @param flights_catalog Catalog containing flight information.
 * @param reservations_catalog Catalog containing reservation information.
 * @param args Arguments (user, reservation, or flight id).
 * @param output Output file to write the query results.
 * @param flag If == 1, it's a query flag; else, it's a normal query.
 */
void exec_query_one(USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog,
                    char *args, FILE *output, int flag);

#endif
