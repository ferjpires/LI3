#ifndef PARSER_UTILS_H
#define PARSER_UTILS_H

#include <glib.h>
#include <stdio.h>
#include "entities/flight.h"

/**
 * @brief Free the memory allocated for the info.
 *
 * This function frees the memory allocated for the `info` array, which contains strings. The `size` parameter specifies
 * the number of elements in the array.
 *
 * @param info - The info to be freed (type: char**).
 * @param size - The size of the info array (type: int).
 */
void free_info(char **info, int size);

/**
 * @brief Prints the passengers errors.
 *
 * This function prints the user IDs in the `list` GArray to the `errorsFilePassengers` file. It includes information about
 * errors related to the given `flight_id`.
 *
 * @param list - The list of user IDs to write on the error file (type: GArray*).
 * @param flight_id - The ID of the flight for which errors are reported (type: char*).
 * @param errorsFilePassengers - The file that contains the passengers errors (type: FILE*).
 */
void print_passenger_errors(GArray *list, char *flight_id, FILE *errorsFilePassengers);

/**
 * @brief Prints the flight errors.
 *
 * This function prints information about errors in the given `found_flight` to the `errorsFileFlights` file.
 *
 * @param found_flight - The flight that contains the reservations (type: FLIGHT).
 * @param errorsFileFlights - The file that contains the flights errors (type: FILE*).
 */
void print_flight_errors(FLIGHT found_flight, FILE *errorsFileFlights);

#endif