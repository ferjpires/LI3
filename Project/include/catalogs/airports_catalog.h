#ifndef AIRPORTS_CATALOG_H
#define AIRPORTS_CATALOG_H

#include <glib.h>
#include "entities/airport.h"

typedef struct airports_catalog *AIRPORTS_CATALOG;

typedef void (*AirportIteratorFunc)(AIRPORT airport, void *user_data);
typedef void (*AirportIteratorFuncNoData)(AIRPORT airport);

/**
 * @brief Creates space in memory for the Airports Catalog that includes an HashTable
 *
 */
AIRPORTS_CATALOG create_airports_catalog();

/**
 * @brief Builds the Airport with a 2D string array parameters
 * @brief This function is used to simplify the construction of a Airport
 * @brief We call it every time we parse a line from the csv file
 *        It creates space in memory using the create_airport function and it also calls
 *        the insert_airport function to put the formed Airport on the catalog
 *
 * @param catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 * @param name - The airport name of type 'char*'
 * @param delay - The flight delay of type 'int'
 * @param flight_id - The flight id of type 'char*'
 */
void build_airport(AIRPORTS_CATALOG catalog, char *name, int delay, char *flight_id);

/**
 * @brief Insert an airport in the catalog
 *
 * @param catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 * @param airport - The airport of type 'AIRPORT'
 * @param key - The airport name of type 'char*'
 */
void insert_airport(AIRPORTS_CATALOG catalog, AIRPORT airport, char *key);

/**
 * @brief Lookup an airport in the catalog
 *
 * @param catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 * @param airport_id - The airport id of type 'char*'
 * @return AIRPORT - The airport of type 'AIRPORT'
 */
AIRPORT lookup_airport(AIRPORTS_CATALOG catalog, char *airport_id);

/**
 * @brief Check if the catalog contains an airport
 *
 * @param catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 * @param key - The airport name of type 'char*'
 * @return int - 1 if the catalog contains the airport, 0 otherwise
 */
int contains_airport(AIRPORTS_CATALOG catalog, char *key);

/**
 * @brief Free the memory allocated for the airports catalog
 *
 * @param catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 */
void free_airports_catalog(AIRPORTS_CATALOG catalog);

/**
 * @brief Iterate the hash table with a user data
 *
 * @param catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 * @param iterator_func - The iterator function of type 'AirportIteratorFunc'
 * @param user_data - The user data of type 'void*'
 */
void iterate_airports(AIRPORTS_CATALOG catalog, AirportIteratorFunc iterator_func, void *user_data);

/**
 * @brief Iterate the hash table
 *
 * @param catalog - The airports catalog of type 'AIRPORTS_CATALOG'
 * @param iterator_func - The iterator function of type 'AirportIteratorFuncNoData'
 */
void iterate_airports_no_data(AIRPORTS_CATALOG catalog, AirportIteratorFuncNoData iterator_func);

#endif