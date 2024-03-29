#ifndef RESERVATIONS_CATALOG_H
#define RESERVATIONS_CATALOG_H

#include <glib.h>

#include "entities/reservation.h"

typedef struct reservations_catalog *RESERVATIONS_CATALOG;

/**
 * @brief Creates space in memory for the Reservations Catalog that includes an HashTable
 *
 */
RESERVATIONS_CATALOG create_reservations_catalog();

/**
 * @brief Builds the Reservation with a 2D string array parameters
 * @brief This function is used to simplify the construction of a Reservation
 * @brief We call it every time we parse a line from the csv file
 *        It creates space in memory using the create_reservation function and it also calls
 *        the insert_reservation function to put the formed Reservation on the catalog
 *
 * @param reservation_params - The reservation parameters of type 'char**'
 * @param number_of_nights - Number of nights of a reservation
 * @param total_price - total cost of a reservation
 * @param catalog - The reservations catalog of type 'RESERVATIONS_CATALOG'
 */
void build_reservation(char **reservation_params, int number_of_nights, double total_price, RESERVATIONS_CATALOG catalog);

/**
 * @brief Inserts the Reservation in the reservation HashTable with reservation_id as the key
 * @brief This function is used inside the build_reservation function and it acts as middle man to insert
 *        the Reservation on the catalog
 *
 * @param catalog - The reservation catalog of type 'RESERVATIONS_CATALOG'
 * @param reservation - The reservation of type 'RESERVATION'
 * @param reservation_id - The reservation id of type 'char*'
 */
void insert_reservation(RESERVATIONS_CATALOG catalog, RESERVATION reservation, char *reservation_id);

/**
 * @brief Looks up a Reservation in the reservations catalog passing reservation_id as the key
 * @brief This function is used every time we need to search for a reservation in the catalog
 *
 * @param catalog - The reservation catalog of type 'RESERVATIONS_CATALOG'
 * @param reservation_id - The reservation id of type 'char*'
 */
RESERVATION lookup_reservation(RESERVATIONS_CATALOG catalog, char *reservation_id);

/**
 * @brief Destroys the catalog freeing all the memory
 *
 * @param catalog - The reservations catalog of type 'RESERVATIONS_CATALOG'
 */
void free_reservations_catalog(RESERVATIONS_CATALOG catalog);

#endif