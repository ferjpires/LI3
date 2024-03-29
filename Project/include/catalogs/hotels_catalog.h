#ifndef HOTELS_CATALOG_H
#define HOTELS_CATALOG_H

#include "entities/hotel.h"

typedef struct hotels_catalog *HOTELS_CATALOG;

/**
 * @brief Creates space in memory for the Hotels Catalog that includes an HashTable
 *
 */
HOTELS_CATALOG create_hotels_catalog();

/**
 * @brief Builds the Hotel
 *
 * @param hotel_id - The hotel id of type 'char*'
 * @param hotel_rating - The hotel rating of type 'char*'
 * @param reservation_id - The reservation id of type 'char*'
 */
void build_hotel(HOTELS_CATALOG catalog, char *hotel_id, char *hotel_rating, char *reservation_id);

/**
 * @brief Inserts the Hotel in the hotel HashTable with the key
 *
 * @param catalog - The reservation catalog of type 'RESERVATIONS_CATALOG'
 * @param hotel - The hotel of type 'HOTEL'
 * @param key - The key of type 'char*'
 */
void insert_hotel(HOTELS_CATALOG catalog, HOTEL hotel, char *key);

/**
 * @brief Looks up a Hotel in the hotels catalog passing hotel_id as the key
 *
 * @param catalog - The reservation catalog of type 'RESERVATIONS_CATALOG'
 * @param hotel_id - The key of type 'char*'
 */
HOTEL lookup_hotel(HOTELS_CATALOG catalog, char *hotel_id);

/*
 * @brief Checks if the catalog contains a hotel with the key
 *
 * @param catalog - The hotel catalog of type 'HOTELS_CATALOG'
 * @param key - The key of type 'char*'
 */
int contains_hotel(HOTELS_CATALOG catalog, char *key);

/**
 * @brief Destroys the catalog freeing all the memory
 *
 * @param catalog - The reservations catalog of type 'HOTELS_CATALOG'
 */
void free_hotels_catalog(HOTELS_CATALOG catalog);

#endif