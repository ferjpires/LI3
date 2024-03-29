#ifndef QUERY8_H
#define QUERY8_H

#include <stdio.h>
#include "catalogs/reservations_catalog.h"
#include "entities/reservation.h"
#include "catalogs/hotels_catalog.h"

/**
 * @brief Calculates the revenue of a reservation between two dates.
 *
 * This function calculates the revenue of a reservation between the provided begin date and end date. It utilizes the
 * reservation information, such as the reservation's check-in and check-out dates, to determine the duration of the stay
 * and calculates the corresponding revenue based on the reservation's pricing.
 *
 * @param reservation - The reservation for which revenue is calculated (type: RESERVATION).
 * @param begin_date - The begin date received as input (type: char*).
 * @param end_date - The end date received as input (type: char*).
 *
 * @return int - The calculated revenue of the reservation between the specified dates.
 */
int get_revenue(RESERVATION reservation, char *begin_date, char *end_date);

/**
 * @brief Transforms a date in the format 'year/month/day' to an integer representing the number of days.
 *
 * This function takes a date in the format 'year/month/day' and transforms it into an integer representing the number
 * of days. It is used for date calculations, such as determining the duration of a reservation stay.
 *
 * @param date - The date to be transformed (type: char*).
 *
 * @return int - The integer representation of the date in terms of days.
 */
int to_number(char *date);

/**
 * @brief Iterates through every reservation and sums the revenues of reservations with the given hotel ID.
 *
 * This function is used as a callback to iterate through every reservation in the system. It sums the revenues of
 * reservations that contain the specified hotel ID and updates an array with the total revenue for each hotel. It is
 * designed to be used with the g_hash_table_foreach function.
 *
 * @param reservation - The reservation being checked (type: RESERVATION).
 * @param user_data - The array with parameters to alter, including the hotel ID and total revenue (type: void*).
 */
void calculate_total_revenue(RESERVATION reservation, void *user_data);

/**
 * @brief Executes query 8 and writes the results to the output file.
 *
 * This function executes query 8 based on the provided arguments, utilizing the hotels catalog and reservations catalog
 * to retrieve relevant information. The results are then written to the output file. An additional flag is used for
 * query-specific formatting.
 *
 * @param hotels_catalog - The hotels catalog containing hotel information (type: HOTELS_CATALOG).
 * @param reservations_catalog - The reservations catalog containing reservation information (type: RESERVATIONS_CATALOG).
 * @param args - The arguments given to the function (type: char*).
 * @param output - The output file to write the result (type: FILE*).
 * @param flag - The flag used to distinguish the output result (type: int).
 */
void exec_query_eight(HOTELS_CATALOG hotels_catalog, RESERVATIONS_CATALOG reservations_catalog, char *args, FILE *output, int flag);

#endif