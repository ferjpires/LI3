#ifndef FLIGHTS_CATALOG_H
#define FLIGHTS_CATALOG_H

#include <glib.h>

#include "entities/flight.h"

typedef struct flights_catalog *FLIGHTS_CATALOG;

typedef void (*FlightIteratorFunc)(FLIGHT flight, void *user_data);
typedef void (*FlightIteratorFuncQ6)(FLIGHT flight, void *user_data1, void *user_data2, void *year);

/**
 * @brief Creates space in memory for the Flights Catalog that includes an HashTable
 *
 */
FLIGHTS_CATALOG create_flights_catalog();

/**
 * @brief Builds the Flight with a 2D string array parameters
 * @brief This function is used to simplify the construction of a Flight
 * @brief We call it every time we parse a line from the csv file
 *        It creates space in memory using the create_flight function and it also calls
 *        the insert_flight function to put the formed Flight on the catalog
 *
 * @param flight_params - The flight parameters of type 'char**'
 * @param catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 */
void build_flight(char **flight_params, FLIGHTS_CATALOG catalog);

/**
 * @brief Inserts the Flight in the flights HashTable with flight_id as the key
 * @brief This function is used inside the build_flight function and it acts as middle man to insert
 *        the Flight on the catalog
 *
 * @param catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param flight - The flight of type 'FLIGHT'
 * @param flight_id - The flight id of type 'char*'
 */
void insert_flight(FLIGHTS_CATALOG catalog, FLIGHT flight, char *flight_id);

/**
 * @brief Looks up a Flight in the flights catalog passing flight_id as the key
 * @brief This function is used every time we need to search for a flight in the catalog
 *
 * @param catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param flight_id - The flight id of type 'char**'
 */
FLIGHT lookup_flight(FLIGHTS_CATALOG catalog, char *flight_id);

/**
 * @brief Checks if the HashTable in the catalog contains the given key
 * @brief This function is used every time we need to search if a flight exists in the catalog
 *
 * @param catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param key - The key of type 'char*'
 */
int contains_flight(FLIGHTS_CATALOG catalog, char *key);

/**
 * @brief Destroys the catalog freeing all the memory
 *
 * @param catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 */
void free_flights_catalog(FLIGHTS_CATALOG catalog);

/**
 * @brief Removes a key and values from the table
 *
 * @param catalog - The flights catalog of type 'FLIGHTS_CATALOG'
 * @param key - The key to remove of type 'char*'
 */
void remove_flight_from_hashtable(FLIGHTS_CATALOG catalog, char *key);

/**
 * @brief Iterates through the flights table
 *        We use this to iterate through the table to get some data to perform queries
 *
 * @param catalog - The flight catalog of type 'FLIGHTS_CATALOG'
 * @param iterator_func - The function to apply to every flight on the catalog of type 'FlightIteratorFunc'
 * @param user_data - The extra data we pass to the function that we need for it to work of type 'void*'
 */
void iterate_flights(FLIGHTS_CATALOG catalog, FlightIteratorFunc iterator_func, void *user_data);

#endif